#include "../include/app.h"
#include <stdlib.h>
#include <stdio.h>


int main (int argc, char** argv)
{
    PCONFIG config;

    if (!load_config(&config, CONFIG_PATH))
    {
        fprintf(stderr, "No config file found");
        return -1;
    }

    int res;

    if (config->is_mp)
    {
        res = with_mp_main(config);
    }
    else
    {
        res = no_mp_main(config);
    }


    free(config->output_path);
    free(config);

    return res;
}
