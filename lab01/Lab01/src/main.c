#include "../include/app.h"
#include <stdlib.h>
#include <stdio.h>


int main (int argc, char** argv)
{
    PCONFIG config;
    bool custom_config_file_read = false;

    if (argc == 2)
    {
        custom_config_file_read = true;
        if (!load_config(&config, argv[1]))
        {
            custom_config_file_read = false;
            fprintf(stderr, "Failed to parse config file %s. Attempting to parse default config file...\n", argv[1]);
        }
    }

    if (!custom_config_file_read && !load_config(&config, CONFIG_PATH))
    {
        fprintf(stderr, "Failed to parse default config file.\n");
        return -1;
    }

    return config->is_mp ? with_mp_main(config) : no_mp_main(config);
}
