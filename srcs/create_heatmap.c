/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_heatmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:46:15 by tjose             #+#    #+#             */
/*   Updated: 2017/04/13 17:00:09 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** Calculate distance from every single point to nearest opposing character
**
*/

static int		is_enemy(t_mapinfo *info, int y, int x)
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

static int		find_closest_dist(t_mapinfo *info, int hy, int hx)
{
	int		dist;
	int		closest;
	int		x;
	int		y;

	closest = 1000000;
	y = -1;
	while (++y < info->height)
	{
		x = -1;
		while (++x < info->width)
		{
			if (is_enemy(info, y, x))
			{
				dist = ft_sqrt(((x - hx) * (x - hx)) + ((y - hy) * (y - hy)));
				if (dist == 0)
					return (0);
			}
			if (dist < closest)
				closest = dist;
		}
	}
	return (closest);
}

void			create_heatmap(t_mapinfo *info)
{
	float	distance;
	int		x;
	int		y;

	y = -1;
	while (++y < info->height)
	{
		x = -1;
		while (++x < info->width)
		{
			distance = find_closest_dist(info, y, x);
			distance = distance == 2 ? distance + 2 : distance;
			distance = distance == 1 ? distance + 3 : distance;
			info->heatmap[y][x] = distance;
		}
	}
}
