#include "../includes/filler.h"

void    print_map(t_data **data)
{
    int i;
    int k;

    i = -1;
    while (++i < (*data)->map_height)
    {
        k = -1;
        while (++k < (*data)->map_width)
    {
        fd_printf((*data)->fd_log, "%3d ", (*data)->map[i][k]);
    }
    fd_printf((*data)->fd_log, "\n");
    }
}

// void    print_piece(t_data **data, int height)
// {
//     int i;

//     i = -1;
//     while (++i < height)
//         fd_printf((*data)->fd, "%s\n", (*data)->piece[i]);
// }
