/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 18:39:25 by tjose             #+#    #+#             */
/*   Updated: 2017/04/20 23:46:50 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <unistd.h>

static int	is_safe_spot(t_mapinfo *info, int yy, int xx, int *num_touching)
{
	if (yy >= 0 && xx >= 0 && yy < info->height && xx < info->width)
	{
		if (info->player_number == 1 && (info->map[yy][xx] == 'o'
					|| info->map[yy][xx] == 'O'))
			(*num_touching)++;
		else if (info->player_number == 2 && (info->map[yy][xx] == 'x'
							|| info->map[yy][xx] == 'X'))
			(*num_touching)++;
		else if (info->map[yy][xx] != '.')
			return (0);
	}
	else
		return (0);
	return (1);
}

static int	is_safe(t_mapinfo *info, int y, int x)
{
	int	px;
	int	py;
	int	num_touching;

	py = -1;
	num_touching = 0;
	while (++py < info->p_hei)
	{
		px = -1;
		while (++px < info->p_wid)
		{
			if (info->piece[py][px] == '*')
			{
				if (!is_safe_spot(info, y + py, x + px, &num_touching))
					return (0);
			}
		}

	}
	if (num_touching != 1)
		return (0);
	return (1);
}

static void	update_highest(int highest[3], t_mapinfo *info, int y, int x)
{
	int	i;
	int	j;
	int	sum;

	sum = 0;
	i = -1;
	while (++i < info->p_hei)
	{
		j = -1;
		while (++j < info->p_wid)
		{
			if (info->piece[i][j] == '*')
				sum += info->heatmap[i + y][j + x];	
		}
	}
	if (sum > highest[0])
	{
		highest[0] = sum;
		highest[1] = y;
		highest[2] = x;
	}
}

/*
**	for "int	highest[3]" below:
**	highest[0] = highest sum from heatmap
**	highest[1] = y;
**	highest[2] = x;
*/

int			place_piece(t_mapinfo *info)
{
	int			y;
	int			x;
	int			highest[3];

	highest[0] = -1;
	y = -info->p_hei - 1;
	while (++y < info->height)
	{
		x = -info->p_wid - 1;
		while (++x < info->width)
		{
			if (is_safe(info, y, x))
				update_highest(highest, info, y, x);
		}
	}
	if (highest[0] != -1)
	{
		ft_printf("%d %d\n", highest[1], highest[2]);
		sleep(1);
		return (1);
	}
	ft_printf("-1 -1\n");
	return (0);
}
