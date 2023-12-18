#include "cub3d.h"

int main(int ac, char **av)
{

    if(ac != 2)
    {
        printf("Error: Wrong number of arguments\n");
        exit(1);
    }
    check_map_syntax(av[1]);

}