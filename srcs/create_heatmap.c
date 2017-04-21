/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_heatmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:46:15 by tjose             #+#    #+#             */
/*   Updated: 2017/04/20 17:45:06 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** Calculate distance from every single point to nearest opposing character
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

/*static int		find_closest_dist(t_mapinfo *info, int hy, int hx)
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
				if (dist < closest)
					closest = dist;
			}
		}
	}
	return (closest);
}*/

static int		add_heat(t_mapinfo *info, int new, int old)
{
	int	i;
	int	j;
	int	flag;

	flag = 0;
	new = new < 0 ? -new : new;
	i = -1;
	while (++i < info->height)
	{
		j = -1;
		while (++j < info->width)
		{
			if ((info->heatmap[i][j] == 10) &&
				((j + 1 < info->width && info->heatmap[i][j + 1] == old) ||
				(j - 1 > 0 && info->heatmap[i][j - 1] == old) ||
				(i + 1 < info->height && info->heatmap[i + 1][j] == old) ||
				(i - 1 > 0 && info->heatmap[i - 1][j] == old)))
			{
				info->heatmap[i][j] = new;
				flag = 1;
			}
		}
	}
	return (flag);
}

static void		update_heat(t_mapinfo *info, int mode)
{
	int	i;
	int	j;

	i = -1;
	while (++i < info->height)
	{
		j = -1;
		while (++j < info->width)
		{
			if (mode == 1)
			{
				if (is_enemy(info, i, j))
					info->heatmap[i][j] = 0;
				else
					info->heatmap[i][j] = 10;
			}
			else if (mode == 0)
			{
				if (info->heatmap[i][j] == 10)
					info->heatmap[i][j] = 0;
			}
		}
	}
}

void			create_heatmap(t_mapinfo *info)
{
	/*int		distance;
	int		x;
	int		y;*/
	int		heat;

	heat = 0;
	update_heat(info, 1);
	while (++heat < 4)
	{
		if (!(add_heat(info, heat, heat - 1)))
			break ;
	}
	if (--heat == 3)
	{
		while (--heat > 0)
		{
			if (!(add_heat(info, heat, heat + 1)))
				break ;
		}
	}
	draw_chase(info)
	update_heat(info, 0);
	/*y = -1;
	while (++y < info->height)
	{
		x = -1;
		while (++x < info->width)
		{
			distance = find_closest_dist(info, y, x);
			distance = distance == 2 ? distance + 3 : distance;
			distance = distance == 1 ? distance + 3 : distance;
			info->heatmap[y][x] = distance;
		}
	}*/
}
