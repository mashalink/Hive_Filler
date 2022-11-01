/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:37:15 by mlink             #+#    #+#             */
/*   Updated: 2022/11/01 11:21:00 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
** gives integer values describing if a spot is 
** free/reserved by enemy/reserved by own player.
*/

static int	map_line(t_data **data, char *line, int height)
{
	int	x;

	x = 4;
	(*data)->map[height] = (int *)malloc(sizeof(int) * (*data)->map_width);
	if (!(*data)->map[height])
		return (0);
	while (x - 4 < (*data)->map_width)
	{
		if (line[x] == '.')
			(*data)->map[height][x - 4] = 0;
		else if (line[x] == (*data)->opponent_id || line[x] == \
		(*data)->opponent_id + 32)
			(*data)->map[height][x - 4] = -1;
		else if (line[x] == (*data)->player_id || line[x] == \
		(*data)->player_id + 32)
			(*data)->map[height][x - 4] = -2;
		fd_printf((*data)->fd_log, "%3d", (*data)->map[height][x - 4]);
		x++;
	}
	fd_printf((*data)->fd_log, "\n");
	return (1);
}

static int	save_line(t_data **data)
{
	int		height;
	char	*line;

	height = -1;
	while (++height < (*data)->map_height && get_next_line((*data)->fd, &line))
	{
		if (!map_line(data, line, height))
			return (0);
		ft_strdel(&line);
	}
	if (height == (*data)->map_height)
		return (1);
	return (0);
}

/*
** creates an integer map based of map read from stdin.
*/

int	read_map(t_data **data)
{
	char	*line;

	line = NULL;
	while (get_next_line((*data)->fd, &line) > 0 && \
	ft_strncmp(line, "Plateau", 6) != 0)
		ft_strdel(&line);
	if (!line)
		return (0);
	get_size(&line, &(*data)->map_height, &(*data)->map_width);
	fd_printf((*data)->fd_log, "Plateau %d %d\n", (*data)->map_height, \
	(*data)->map_width);
	if (get_next_line((*data)->fd, &line) > 0)
		ft_strdel(&line);
	(*data)->map = (int **)malloc(sizeof(int *) * (*data)->map_height);
	if (!(*data)->map)
		return (0);
	if (save_line(data))
		return (1);
	return (0);
}

/*
** Read_piece reads and saves piece to struct.
*/

int	read_piece(t_data **data)
{
	int		height;
	char	*line;

	line = NULL;
	while (get_next_line((*data)->fd, &line) > 0 && \
	ft_strncmp(line, "Piece", 4) != 0)
		ft_strdel(&line);
	if (!line)
		return (0);
	get_size(&line, &(*data)->piece_height, &(*data)->piece_width);
	fd_printf((*data)->fd_log, "Piece %d %d\n", (*data)->piece_height, \
	(*data)->piece_width);
	(*data)->piece = (char **)malloc(sizeof(char *) * ((*data)->piece_height));
	height = -1;
	while (++height < (*data)->piece_height && \
	get_next_line((*data)->fd, &line))
	{
		(*data)->piece[height] = ft_strdup((const char *)(line));
		fd_printf((*data)->fd_log, "%s\n", (*data)->piece[height]);
		ft_strdel(&line);
	}
	if (height == (*data)->piece_height)
		return (trim_piece(data));
	return (0);
}
