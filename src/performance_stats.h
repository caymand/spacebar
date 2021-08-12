#include <mach/mach.h>

#define MBYTE 1000000
#define CPU_USAGE_STR_LEN 11
#define MEM_USAGE_STR_LEN 11

struct performance_stats {
    mach_port_t host;
    vm_size_t page_size;
    int memory_used;
    host_cpu_load_info_data_t cpu_load;
};

int performance_stats_init(struct performance_stats *performance_stats);
int performance_stats_memory(struct performance_stats *performance_stats);
float performance_stats_cpu(host_cpu_load_info_data_t prev_cpu_usage,
        host_cpu_load_info_data_t curr_cpu_usage);
host_cpu_load_info_data_t cpu_used(host_t host);
static int vm_pages_used(host_t host);


