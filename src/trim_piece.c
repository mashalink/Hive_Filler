/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:35:41 by mlink             #+#    #+#             */
/*   Updated: 2022/11/08 11:03:22 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
** checks how many horizontal lines of old piece are not empty.
*/

static void	get_new_height(t_data **data, int start_y)
{
	int	new_height;

	new_height = 0;
	while (start_y < (*data)->piece_height)
	{
		if (ft_strchr((*data)->piece[start_y], '*') != NULL)
			new_height++;
		start_y++;
	}
	(*data)->real_height = new_height;
}

/*
** checks how many vertical lines of old piece are not empty.
*/

static void	get_new_width(t_data **data, int start_x, int start_y)
{
	int	new_width;
	int	x_counter;
	int	x_cur_counter;

	new_width = 0;
	while (++start_y < (*data)->piece_height)
	{
		if (ft_strchr((*data)->piece[start_y], '*') != NULL)
		{
			x_counter = start_x;
			x_cur_counter = 0;
			while ((*data)->piece[start_y][x_counter] != '\0')
			{
				if ((*data)->piece[start_y][x_counter] == '*')
					x_cur_counter = x_counter + 1;
				x_counter++;
			}
			if (x_cur_counter - start_x > new_width)
				new_width = x_cur_counter - start_x;
		}
	}
	(*data)->real_width = new_width;
}

/*
** finds the upper left coordinates of where piece starts.
*/

static int	find_start(t_data **data)
{
	int	y_index;
	int	x_index;

	y_index = -1;
	while (++y_index < (*data)->piece_height)
	{
		x_index = -1;
		while (++x_index < (*data)->piece_width)
		{
			if ((*data)->piece[y_index][x_index] == '*')
			{
				if (y_index < (*data)->start_height)
					(*data)->start_height = y_index;
				if (x_index < (*data)->start_width)
					(*data)->start_width = x_index;
			}
		}
	}
	return (1);
}

/*
** allocates memory for char ** array
** copies piece without free lines and columns
** frees memory which used for data with piece
*/

/*
**	print new size in filler.log:
**	fd_printf((*data)->fd_log, "%s\n", new_piece[y_index]); // after ft_strndup()
*/

static int	save_new_piece(t_data **data, int start_y)
{
	char	**new_piece;
	int		y_index;

	new_piece = NULL;
	new_piece = (char **)malloc(sizeof(char *) * (*data)->real_height);
	if (!new_piece)
		return (0);
	y_index = 0;
	while (y_index < (*data)->real_height)
	{
		new_piece[y_index] = ft_strndup((const char *)(*data)->piece[start_y] \
		+ (*data)->start_width, (*data)->real_width);
		y_index++;
		start_y++;
	}
	free_piece(data, (*data)->piece_height);
	(*data)->piece = new_piece;
	return (1);
}

/*
** gets size for just piece
** trims out unnecessary empty lines from piece and saves
** new array with just piece
*/

/*
**	print new size in filler.log:
**	fd_printf((*data)->fd_log, "New Piece %d %d\n", (*data)->real_height, \
	(*data)->real_width); // before return()
*/

int	trim_piece(t_data **data)
{
	(*data)->start_height = (*data)->piece_height;
	(*data)->start_width = (*data)->piece_width;
	find_start(data);
	get_new_height(data, (*data)->start_height);
	get_new_width(data, (*data)->start_width, (*data)->start_height - 1);
	return (save_new_piece(data, (*data)->start_height));
}
