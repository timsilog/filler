/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 18:39:25 by tjose             #+#    #+#             */
/*   Updated: 2017/04/06 20:13:03 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
			if (piece[py][px] == '*')
			{
				if (info->player_number == 1 && (info->map[y + py][x + px] == 'o'
						|| info->map[y + py][x + px] == 'O'))
					num_touching++;
				else if (info->player_number == 2 && (info->map[y + py][x + px] == 'x'
						|| info->map[y + py][x + px] == 'X'))
					num_touching++;
				else if (info->map[y + py][x + px] != '.')
					return (0);
			}
		}
		// this is where you left off last yo
	}
}

void		place_piece(t_mapinfo *info)
{
	int	y;
	int	x;

	y = -info->p_hei;
	while (y < info->height)
	{
		x = -info->p_wid;
		while (x < info->width)
		{
			if (is_safe(info, x, y))
					ft_printf("%d %d\n", y, x);
		}
	}
}
