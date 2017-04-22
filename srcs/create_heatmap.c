/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_heatmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:46:15 by tjose             #+#    #+#             */
/*   Updated: 2017/04/21 19:37:34 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		print_heat(t_mapinfo *info)
{
	int i;
	int j;

	i = -1;
	ft_putstr_fd("HEAT MAP\n", 2);
	while (++i < info->height)
	{
		j = -1;
		while (++j < info->width)
			ft_putstr_fd(ft_itoa((int)info->heatmap[i][j]), 2);
		ft_putstr_fd("\n", 2);
	}
}

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
	draw_chase(info);
	update_heat(info, 0);
	print_heat(info);
}
