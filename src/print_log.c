/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:37:12 by mlink             #+#    #+#             */
/*   Updated: 2022/11/01 11:04:27 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	print_map(t_data **data)
{
	int	i;
	int	k;

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
