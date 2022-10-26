#include "../includes/filler.h"

int free_data(t_data **data, int result)
{
    free(*data);
    (*data) = NULL;
    return (result);
}

void	free_map(t_data **data)
{
	int	i;

	i = 0;
	if (!(*data)->map)
		return ;
	while (i < (*data)->map_height)
	{
		free((*data)->map[i]);
		i++;
	}
	free((*data)->map);
    (*data)->map = NULL;
}

void	free_piece(t_data **data, int height)
{
	int		i;

	i = -1;
	fd_printf((*data)->fd_log, "!DONE1 %d \n", height);
	if (!(*data)->piece)
		return ;
		fd_printf((*data)->fd_log, "!DONE2\n");
	while (++i < height)
	{

		ft_strdel(&(*data)->piece[i]);
		fd_printf((*data)->fd_log, "!DONE2.1\n");
	}
	fd_printf((*data)->fd_log, "!DONE3\n");
	free((*data)->piece);
	fd_printf((*data)->fd_log, "!DONE4\n");
	(*data)->piece = NULL;
	fd_printf((*data)->fd_log, "!DONE5\n");
}
