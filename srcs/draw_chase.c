/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_chase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 16:50:35 by tjose             #+#    #+#             */
/*   Updated: 2017/04/21 18:26:53 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	find_first(int player[2], t_mapinfo *info, int enemy)
{
	int	i;
	int	j;

	i = -1;
	while (++i < info->height)
	{
		j = -1;
		while (++j < info->width)
		{
			if ((enemy && is_enemy(info, i, j)) ||
					(!enemy && is_me(info, i, j)))
			{
				player[0] = i;
				player[1] = j;
			}
		}
	}
}

static void	get_lowest(int me[3], int distance, int y, int x)
{
	if (distance > -1 && distance < me[0])
	{
		me[0] = distance;
		me[1] = y;
		me[2] = x;
	}
}

static int	get_dist(t_mapinfo *info, int y, int x, int e[2])
{
	if (x > -1 && x < info->width && y > -1 && y < info->height)
		return (ft_sqrt(((x - e[1]) * (x - e[1])) + ((y - e[0]) * (y - e[0]))));
	else
		return (-1);
}

/*
** me[0] = lowest distance found so far
** me[1] = y of lowest distance
** me[2] = x of lowest distance
** temp[0] = copy of first me[1]
** temp[1] = copy of first me[2]
** enemy[0] = y of first found enemy
** enemy[1] = x of first found enemy
*/

static void	draw(t_mapinfo *info, int me[3], int enemy[2], int temp[2])
{
	me[0] = 2147483647;
	get_lowest(me, get_dist(info, temp[0] - 1, temp[1] - 1, enemy),
	temp[0] - 1, temp[1] - 1);
	get_lowest(me, get_dist(info, temp[0] - 1, temp[1], enemy),
	temp[0] - 1, temp[1]);
	get_lowest(me, get_dist(info, temp[0] - 1, temp[1] + 1, enemy),
	temp[0] - 1, temp[1] + 1);
	get_lowest(me, get_dist(info, temp[0], temp[1] - 1, enemy),
	temp[0], temp[1] - 1);
	get_lowest(me, get_dist(info, temp[0], temp[1] + 1, enemy),
	temp[0], temp[1] + 1);
	get_lowest(me, get_dist(info, temp[0] + 1, temp[1] - 1, enemy),
	temp[0] + 1, temp[1] - 1);
	get_lowest(me, get_dist(info, temp[0] + 1, temp[1], enemy),
	temp[0] + 1, temp[1]);
	get_lowest(me, get_dist(info, temp[0] + 1, temp[1] + 1, enemy),
	temp[0] + 1, temp[1] + 1);
	if (info->heatmap[me[1]][me[2]] == 10)
	{
		temp[0] = me[1];
		temp[1] = me[2];
		info->heatmap[me[1]][me[2]] = 1;
		draw(info, me, enemy, temp);
	}
}

void		draw_chase(t_mapinfo *info)
{
	int	me[3];
	int	temp[2];
	int	enemy[2];

	find_first(&me[1], info, 0);
	temp[0] = me[1];
	temp[1] = me[2];
	find_first(enemy, info, 1);
	draw(info, me, enemy, temp);
}
