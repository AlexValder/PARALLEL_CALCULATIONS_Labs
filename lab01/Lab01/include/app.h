#ifndef APP_H
#define APP_H

#include <stdbool.h>

#define ONE_KIB 1024
#define ONE_MIB 1048576 // 1024*1024
#define ONE_GIB 1073741824 // 1024*1024*1024

typedef struct {
    char* output_path;
    char mode;
    char is_mp;
    long long size;
} CONFIG, *PCONFIG;

const static long long SIZE = ONE_GIB / sizeof(double) * 4; // in 1KB * in 1MB * in 1GB / sizeof(double)
const static char CONFIG_PATH[] = "config.txt";

bool load_config(PCONFIG *config, const char* config_path);

int no_mp_main(PCONFIG config);
int with_mp_main(PCONFIG config);

#endif // APP_H
