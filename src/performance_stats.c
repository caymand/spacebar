#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdint.h>
#include <mach/message.h>
#include "performance_stats.h"
//Get the memory use from:
// Active, speculative, wired

int performance_stats_init(struct performance_stats *performance_stats) {
    //Time between memory usage updates
    //int update_time = 2;

    //Page size of host machine
    vm_size_t page_size;
    //Gets acces to the the name port of the host (the host itself is a mach object)
    //which in turn gives access to information about the object(host=
    // so we can query the name host port about memory usage
    //mach_port_t=host_t=*host
    //that is we are given the send privilege
    mach_port_t host = mach_host_self();
    //Verify that the host name port was returned by the kernel
    if (host == MACH_PORT_NULL) {
        fprintf(stderr, "Failed to get the host port\n");
        return EXIT_FAILURE;
    }
    //Use the host name port and send privilege to get the page size of the host
    if (host_page_size(host, &page_size) != KERN_SUCCESS) {
        fprintf(stderr, "Failed to get the VM page size, but uses page size of 4K bytes\n");
        page_size = 4096; //use default page size
    }
    performance_stats->page_size = page_size;
    performance_stats->cpu_load = cpu_used(host);
    return EXIT_SUCCESS;
}

void print_memory_usage(host_t host, vm_size_t page_size) {
    int pages = vm_pages_used(host);
    if (pages < 0) {
        fprintf(stderr, "Failed to get memory usage.\n");
    } else {
        unsigned long mem_used = (pages * page_size)/MBYTE; //ignoring decimals
        fprintf(stdout, "Memory used: %lu\n", mem_used);//mult of long and int
    }
}


void print_cpu_usage(host_t host) {
    host_cpu_load_info_data_t first_tick = cpu_used(host);
    sleep(5);
    host_cpu_load_info_data_t second_tick = cpu_used(host);

    unsigned long long diff_user = second_tick.cpu_ticks[CPU_STATE_USER] - first_tick.cpu_ticks[CPU_STATE_USER];
    unsigned long long diff_system = second_tick.cpu_ticks[CPU_STATE_SYSTEM] - first_tick.cpu_ticks[CPU_STATE_SYSTEM];
    unsigned long long diff_nice = second_tick.cpu_ticks[CPU_STATE_NICE] - first_tick.cpu_ticks[CPU_STATE_NICE];
    unsigned long long diff_idle = second_tick.cpu_ticks[CPU_STATE_IDLE] - first_tick.cpu_ticks[CPU_STATE_IDLE];

    unsigned long long used_cpu_ticks = diff_user + diff_system + diff_nice;
    float cpu_used = (float) used_cpu_ticks / (used_cpu_ticks + diff_idle);
    cpu_used *= 100;
    fprintf(stdout, "CPU USAGE: %f\n", cpu_used);
}

host_cpu_load_info_data_t cpu_used(host_t host) {
    host_cpu_load_info_data_t cpu_load_info;
    mach_msg_type_number_t msg_type_count = HOST_CPU_LOAD_INFO_COUNT;

    if (host_statistics(host, HOST_CPU_LOAD_INFO,
                (host_info64_t) &cpu_load_info, &msg_type_count) != KERN_SUCCESS) {
        fprintf(stderr, "Failed to get CPU load from host port.\n");
        return cpu_load_info;
    }

    return cpu_load_info;
}



int vm_pages_used(host_t host) {
    vm_statistics64_data_t vm_stats;
    mach_msg_type_number_t msg_type = HOST_VM_INFO64_COUNT;
    //pointer to host port, flavor is VM info for 64 bit machine
    //struct of VM statistics filled by callee, pointer to number of fields in struct
    if (host_statistics64(host, HOST_VM_INFO64,
                (host_info64_t) &vm_stats, &msg_type) != KERN_SUCCESS) {
        fprintf(stderr, "Failed to get VM statistics from host object.\n");
        return -1;
    }

    uint64_t memory_usage = vm_stats.active_count;
    memory_usage += vm_stats.wire_count;
    memory_usage += vm_stats.compressor_page_count;
    //memory_usage += vm_stats.speculative_count;
    return memory_usage;
}
