#include <mach/mach.h>

#define MBYTE 1000000

void print_memory_usage(host_t host, vm_size_t page_size);
int vm_pages_used(host_t host);
host_cpu_load_info_data_t cpu_used(host_t host);
void print_cpu_usage(host_t host);

struct performance_stats {
    vm_size_t page_size;
    int memory_used;
    host_cpu_load_info_data_t cpu_load;
};
