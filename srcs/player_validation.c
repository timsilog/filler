/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 23:08:18 by tjose             #+#    #+#             */
/*   Updated: 2017/04/20 23:10:34 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		is_me(t_mapinfo *info, int y, int x)
{
	if (info->player_number == 2)
	{
		if (info->map[y][x] == 'x' || info->map[y][x] == 'X')
			return (1);
	}
	else if (info->player_number == 1)
	{
		if (info->map[y][x] == 'o' || info->map[y][x] == 'O')
			return (1);
	}
	return (0);
}

int		is_enemy(t_mapinfo *info, int y, int x)
{
	if (info->player_number == 1)
	{
		if (info->map[y][x] == 'x' || info->map[y][x] == 'X')
			return (1);
	}
	else if (info->player_number == 2)
	{
		if (info->map[y][x] == 'o' || info->map[y][x] == 'O')
			return (1);
	}
	return (0);
}
