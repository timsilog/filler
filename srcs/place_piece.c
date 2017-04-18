/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 18:39:25 by tjose             #+#    #+#             */
/*   Updated: 2017/04/17 16:54:40 by tjose            ###   ########.fr       */
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

static int	get_heat_sum(t_mapinfo *info, int y, int x)
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
	return (sum);
}

static void	update_lowest(int lowest[3], t_mapinfo *info, int y, int x)
{
	int	temp;

	temp = get_heat_sum(info, y, x);
	if (temp < lowest[0])
	{
		lowest[0] = temp;
		lowest[1] = y;
		lowest[2] = x;
	}
}

/*
**	for "int	lowest[3]" below:
**	lowest[0] = lowest value
**	lowest[1] = y;
**	lowest[2] = x;
*/

int			place_piece(t_mapinfo *info)
{
	int			y;
	int			x;
	int			lowest[3];

	lowest[0] = 100000;
	y = -info->p_hei - 1;
	while (++y < info->height)
	{
		x = -info->p_wid - 1;
		while (++x < info->width)
		{
			if (is_safe(info, y, x))
				update_lowest(lowest, info, y, x);
		}
	}
	if (lowest[0] != 100000)
	{
		ft_printf("%d %d\n", lowest[1], lowest[2]);
		return (1);
	}
	ft_printf("-1 -1\n");
	return (0);
}
