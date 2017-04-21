/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_chase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 16:50:35 by tjose             #+#    #+#             */
/*   Updated: 2017/04/20 17:45:04 by tjose            ###   ########.fr       */
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
			if ((enemy && is_enemy) || (!enemy && is_me))
			{
				player[0] = i;
				player[1] = j;
			}
		}
	}
}

static int	check(t_mapinfo *info, int y, int x)
{
	if (x > 0 && x < info->width && y > 0 && y > info->height)
		return (1);
	return (0);
}

//get_distance uses check function


//draw_lowest determines lowest and calls draw() again

static void	draw(t_mapinfo *info, int me[2], int enemy[2])
{
	int	temp[8];

	temp[0] = get_distance(me[0] - 1, me[1] - 1, enemy);
	temp[1] = get_distance(me[0] - 1, me[1], enemy);
	temp[2] = get_distance(me[0] - 1, me[1] + 1, enemy);
	temp[3] = get_distance(me[0], me[1] - 1, enemy);
	temp[4] = get_distance(me[0], me[1] + 1, enemy);
	temp[5] = get_distance(me[0] + 1, me[1] - 1, enemy);
	temp[6] = get_distance(me[0] + 1, me[1], enemy);
	temp[7] = get_distance(me[0] + 1, me[1] + 1, enemy);
	draw_lowest(temp);
}

void		draw_chase(t_mapinfo *info)
{
	int	me[2];
	int	enemy[2];

	find_first(me, info, 0);
	find_first(enemy, info, 1);
	draw(info, me, enemy);
}
