/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 18:39:25 by tjose             #+#    #+#             */
/*   Updated: 2017/04/10 16:04:21 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <unistd.h>

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
				if (y + py >= 0 && x + px >= 0 &&
						y + py < info->height && x + px < info->width)
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
				else
					return (0);
			}
		}
	}
	if (num_touching != 1)
		return (0);
	return (1);
}

int			place_piece(t_mapinfo *info)
{
	int	y;
	int	x;

	y = -info->p_hei - 1;
	while (++y < info->height)
	{
		x = -info->p_wid - 1;
		while (++x < info->width)
		{
			if (is_safe(info, y, x))
			{
					ft_printf("%d %d\n", y, x);
					ft_putstr_fd("i say: ", 2);
					ft_putstr_fd(ft_itoa(y), 2);
					ft_putstr_fd(" ", 2);
					ft_putstr_fd(ft_itoa(x), 2);
					return (1);
			}
		}
	}
	return (0);
}
