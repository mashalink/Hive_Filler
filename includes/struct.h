/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlink <mlink@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:36:44 by mlink             #+#    #+#             */
/*   Updated: 2022/11/01 11:12:09 by mlink            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_data
{
	int		fd;
	int		fd_log;
	char	player_id;
	char	opponent_id;
	int		map_height;
	int		map_width;
	int		**map;
	int		piece_height;
	int		piece_width;
	char	**piece;
	int		start_height;
	int		start_width;
	int		real_height;
	int		real_width;
	int		result_height;
	int		result_width;
}				t_data;

#endif