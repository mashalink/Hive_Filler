/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:35:52 by mlink             #+#    #+#             */
/*   Updated: 2022/11/01 10:52:50 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
** returns the number of points received when placing a piece
*/

int	count_score(t_data **data, int check_x, int check_y)
{
	int	score;
	int	x_index;
	int	y_index;

	y_index = 0;
	score = 0;
	while (y_index < (*data)->real_height)
	{
		x_index = 0;
		while (x_index < (*data)->real_width)
		{
			if ((*data)->piece[y_index][x_index] == '*' && \
			(*data)->map[check_y + y_index][check_x + x_index] != -2)
				score += (*data)->map[check_y + y_index][check_x + x_index];
			x_index++;
		}
		y_index++;
	}
	return (score);
}

/*
** checks if piece can be placed in spot of given coordinates.
*/

int	check_place(t_data **data, int check_x, int check_y)
{
	int	x_index;
	int	y_index;
	int	touch;

	y_index = -1;
	touch = 0;
	while (++y_index < (*data)->real_height)
	{
		x_index = -1;
		while (++x_index < (*data)->real_width)
		{
			if ((*data)->piece[y_index][x_index] == '*')
			{
				if (check_y + y_index >= (*data)->map_height || \
				check_x + x_index >= (*data)->map_width || \
				(*data)->map[check_y + y_index][check_x + x_index] == -1)
					return (-1);
				if ((*data)->map[check_y + y_index][check_x + x_index] == -2)
					touch++;
			}
		}
	}
	if (touch != 1)
		return (-1);
	return (count_score(data, check_x, check_y));
}

void	found_max(t_data **data, int *max_score, int x_index, int y_index)
{
	int		score;

	score = check_place(data, x_index, y_index);
	if (score != -1 && score > *max_score)
	{
		*max_score = score;
		(*data)->result_height = y_index;
		(*data)->result_width = x_index;
	}
}

/*
** finds all possible places to put and 
** chooses the place with the highest points
*/

int	best_place(t_data **data)
{
	int	max_score;
	int	x_index;
	int	y_index;

	max_score = -1;
	y_index = -1;
	while (++y_index < (*data)->map_height)
	{
		x_index = -1;
		while (++x_index < (*data)->map_width)
			found_max(data, &max_score, x_index, y_index);
	}
	fd_printf((*data)->fd_log, "MAX_score = %d\n", max_score);
	return (max_score);
}

int	solve(t_data **data)
{
	point_map(data);
	if (best_place(data) != -1)
	{
		(*data)->result_height = (*data)->result_height - (*data)->start_height;
		(*data)->result_width = (*data)->result_width - (*data)->start_width;
		fd_printf((*data)->fd_log, "%d %d\n", (*data)->result_height, \
		(*data)->result_width);
		ft_printf("%d %d\n", (*data)->result_height, (*data)->result_width);
		(*data)->result_height = 0;
		(*data)->result_width = 0;
		return (1);
	}
	ft_printf("0 0\n");
	return (0);
}
