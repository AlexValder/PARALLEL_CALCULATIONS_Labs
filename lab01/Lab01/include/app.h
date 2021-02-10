#ifndef APP_H
#define APP_H

#include <stdbool.h>

#define ONE_KIB 1024
#define ONE_MIB 1048576 // 1024*1024
#define ONE_GIB 1073741824 // 1024*1024*1024

typedef struct {
    char* output_path; // unused yet
    char mode;         // B, K, M, G - mode
    char is_mp;        // is OMP used or not
    int thread_num;    // number of threads
    long long size;    // amount of doubles
} CONFIG, *PCONFIG;

const static char CONFIG_PATH[] = "config.txt";

bool load_config(PCONFIG *config, const char* config_path);

void log_time(PCONFIG config, double scalar_time);

int no_mp_main(PCONFIG config);
int with_mp_main(PCONFIG config);

#endif // APP_H
