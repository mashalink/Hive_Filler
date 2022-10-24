#include "../includes/filler.h"

/*
** checks if there is an integer 'check' anywhere around a point (x,y)
*/

int		is_around(t_data **data, int x, int y, int check)
{
	if (x + 1 < (*data)->map_width && (*data)->map[y][x + 1] == check)
		return (1);
	if (x + 1 < (*data)->map_width && y + 1 < (*data)->map_height && \
	(*data)->map[y + 1][x + 1] == check)
		return (2);
	if (y + 1 < (*data)->map_height && (*data)->map[y + 1][x] == check)
		return (3);
	if (x - 1 >= 0 && y + 1 < (*data)->map_height && (*data)->map[y + 1][x - 1] == check)
		return (4);
	if (x - 1 >= 0 && (*data)->map[y][x - 1] == check)
		return (5);
	if (x - 1 >= 0 && y - 1 >= 0 && (*data)->map[y - 1][x - 1] == check)
		return (6);
	if (y - 1 >= 0 && (*data)->map[y - 1][x] == check)
		return (7);
	if (x + 1 < (*data)->map_width && y - 1 >= 0 && (*data)->map[y - 1][x + 1] == check)
		return (8);
	return (0);
}


/*
** goes the map and gives points for spots
** the farther from the enemy the less
*/

void	count_point_map(t_data **data)
{
	int	x_index;
	int y_index;
	int points;

	points = 100;
	while (100 - points < (*data)->map_width || 100 - points < (*data)->map_height)
	{
		y_index = 0;
		while (y_index < (*data)->map_height)
		{
			x_index = 0;
			while (x_index < (*data)->map_width)
			{
				if ((*data)->map[y_index][x_index] == 0)
					if (is_around(data, x_index, y_index, points))
						(*data)->map[y_index][x_index] = points - 1;
				x_index++;
			}
			y_index++;
		}
		points--;
	}
	print_map(data);
}

/*
** sets the free spots right next to enemy pieces
** to the highest value of pointmap
*/

void		point_map(t_data **data)
{
	int	x_index;
	int y_index;

	y_index = 0;
	while (y_index < (*data)->map_height)
	{
		x_index = 0;
		while (x_index < (*data)->map_width)
		{
			if ((*data)->map[y_index][x_index] == 0)
				if (is_around(data, x_index, y_index, -1))
					(*data)->map[y_index][x_index] = 100;
			x_index++;
		}
		y_index++;
	}
	count_point_map(data);
}
