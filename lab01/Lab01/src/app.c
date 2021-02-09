#include "../include/app.h"
#include "../include/double_vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

bool load_config(PCONFIG *config, const char* config_path)
{
    FILE* config_file = fopen(config_path, "r");
    if (!config_file)
    {
        fprintf(stderr, "Failed to load config at %s\n", config_path);
        return false;
    }

    *config = (PCONFIG)malloc(sizeof(CONFIG));
    if (!*config)
    {
        fclose(config_file);
        fprintf(stderr, "Failed to create config object.\n");
        return false;
    }

    (*config)->output_path = (char*)malloc(50 * sizeof(char));
    if (!(*config)->output_path)
    {
        fclose(config_file);
        free(*config);
        fprintf(stderr, "Failed to allocate memery for config file path");
        return false;
    }

    char tmp;
    fscanf(config_file, "SIZE=%Ld\nMODE=%c\nTHREADS=%d\nMP_ON=%c\nOUTPUT=%s\n",
                                &(*config)->size,
                                &(*config)->mode,
                                &(*config)->thread_num,
                                &tmp,
                                (*config)->output_path);

    (*config)->is_mp = tmp != '0';

    fclose(config_file);

    switch((*config)->mode)
    {
        case 'b': case 'B':
            fprintf(stdout, "CONFIG:\n\tsize: %Ld byte(s)\n", (*config)->size);
            break;
        case 'k': case 'K':
            fprintf(stdout, "CONFIG:\n\tsize: %Ld KiB\n", (*config)->size);
            break;
        case 'm': case 'M':
            fprintf(stdout, "CONFIG:\n\tsize: %Ld MiB\n", (*config)->size);
            break;
        case 'g': case 'G':
            fprintf(stdout, "CONFIG:\n\tsize: %Ld GiB\n", (*config)->size);
            break;
        default:
            free((*config)->output_path);
            free(*config);
            fprintf(stderr, "Invalid mode: %c. Should either be b, B, k, K, m, M, g, G.\n", (*config)->mode);
            return false;
    }

    fprintf(stdout, "\tIS MP USED: %s\n", ((*config)->is_mp ? "true" : "false"));
    fprintf(stdout, "\tTHREAD(S): %d\n\n", (*config)->thread_num);

    return true;
}


int shared_main(PCONFIG, lvalue_t dot(PCONFIG, pvector_t, pvector_t));

int no_mp_main(PCONFIG config)
{
    return shared_main(config, dot_product);
}


int with_mp_main(PCONFIG config)
{
    return shared_main(config, MP_dot_product);
}

int shared_main(PCONFIG config, lvalue_t dot(PCONFIG, pvector_t, pvector_t))
{
    clock_t begin, end;
    pvector_t vec1, vec2;
    lvalue_t res;

    begin = clock();
    if (!generate_vector(&vec1, config, MIN_VALUE, MAX_VALUE))
    {
        fprintf(stderr, "Failed to generate vector #1.\n");
        return -1;
    }
    if (!generate_vector(&vec2, config, MIN_VALUE, MAX_VALUE))
    {
        free(vec1);
        fprintf(stderr, "Failed to generate vector #2.\n");
        return -1;
    }
    end = clock();

    printf("Spent time generating 2 vectors: %lf s\n", (double)(end - begin)/CLOCKS_PER_SEC);


    begin = clock();
    res = dot(config, vec1, vec2);
    end = clock();

    printf("Spent time calculating dot product: %lf s\n", (double)(end - begin)/CLOCKS_PER_SEC);
    printf("SCALAR: %Lf\n", res);

    free(vec1);
    free(vec2);

    return 0;
}
