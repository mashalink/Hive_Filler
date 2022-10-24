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

void	free_piece(char ***piece, int height)
{
	int		i;

	i = -1;
	if (!(*piece))
		return ;
	while (++i < height)
		ft_strdel(&(*piece[i]));
	free((*piece));
	(*piece) = NULL;
}
