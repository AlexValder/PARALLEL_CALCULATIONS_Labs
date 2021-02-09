#include "../include/app.h"
#include <stdlib.h>
#include <stdio.h>


int main (int argc, char** argv)
{
    PCONFIG config;

    if (!load_config(&config, CONFIG_PATH))
    {
        fprintf(stderr, "Failed to parse config file.\n");
        return -1;
    }

    return config->is_mp ? with_mp_main(config) : no_mp_main(config);
}
