/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:37:04 by mlink             #+#    #+#             */
/*   Updated: 2022/11/01 11:07:40 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	init_data(t_data **data)
{
	(*data) = (t_data *)malloc(sizeof(t_data));
	if (!(data))
		return (-1);
	(*data)->fd = 0;
	(*data)->fd_log = open(LOG, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if ((*data)->fd_log < 0)
		return (-1);
	(*data)->map_height = 0;
	(*data)->map_width = 0;
	(*data)->map = NULL;
	(*data)->piece_height = 0;
	(*data)->piece_width = 0;
	(*data)->piece = NULL;
	(*data)->result_height = 0;
	(*data)->result_width = 0;
	return (get_player(data));
}

int	main(void)
{
	t_data	*data;

	data = NULL;
	if (!init_data(&data))
		return (free_data(&data, -1));
	while (read_map(&data) && read_piece(&data))
	{
		solve(&data);
		free_piece(&data, data->real_height);
		free_map(&data);
	}
	return (free_data(&data, 0));
}
