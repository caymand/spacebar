#include <mach/mach.h>

#define MBYTE 1000000

struct performance_stats {
    mach_port_t host;
    vm_size_t page_size;
    int memory_used;
    host_cpu_load_info_data_t cpu_load;
};
host_cpu_load_info_data_t cpu_used(host_t host);
int performance_stats_init(struct performance_stats *performance_stats);
void print_memory_usage(host_t host, vm_size_t page_size);
int vm_pages_used(host_t host);
host_cpu_load_info_data_t cpu_used(host_t host);
void print_cpu_usage(host_t host);
float performance_stats_cpu(host_cpu_load_info_data_t prev_cpu_usage,
        host_cpu_load_info_data_t curr_cpu_usage);

