/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:36:54 by mlink             #+#    #+#             */
/*   Updated: 2022/11/01 11:10:31 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	free_data(t_data **data, int result)
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
	if (!(*data)->piece)
		return ;
	while (++i < height)
	{
		ft_strdel(&(*data)->piece[i]);
	}
	free((*data)->piece);
	(*data)->piece = NULL;
}
