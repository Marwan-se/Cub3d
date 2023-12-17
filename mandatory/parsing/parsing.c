#include "../cub3d.h"

void    check_map_syntax(char *file)
{
    int i;

    i = 0;
    while(file[i])
    {
        if(file[i] == '.')
        {
            if(file[i + 1] == 'c' && file[i + 2] == 'u' && file[i + 3] == 'b')
                return ;
        }
        i++;
    }
    printf("Error: Wrong file extension\n");
    exit(1);
}

