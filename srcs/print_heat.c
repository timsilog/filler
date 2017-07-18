/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_heat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 14:36:28 by tjose             #+#    #+#             */
/*   Updated: 2017/04/26 14:01:46 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	print_heat_color(t_mapinfo *info, int y, int x)
{
	char	*str;
	int		n;

	n = info->heatmap[y][x];
	str = ft_itoa(n);
	if (n == 0)
		ft_putstr_color_fd(str, white, 2);
	else if (n == 1)
		ft_putstr_color_fd(str, lgreen, 2);
	else if (n == 2)
		ft_putstr_color_fd(str, lyellow, 2);
	else if (n == 3)
		ft_putstr_color_fd(str, lred, 2);
}

static void	print_player_color(t_mapinfo *info, int y, int x, int me)
{
	char *str;

	str = ft_itoa(info->heatmap[y][x]);
	if (me)
		ft_putstr_color_fd(str, blue, 2);
	else
		ft_putstr_color_fd(str, magenta, 2);
}

void		print_heat(t_mapinfo *info)
{
	int y;
	int x;
	int	newlines;

	newlines = -1;
	while (++newlines < 250)
		ft_putstr_fd("\n", 2);
	y = -1;
	while (++y < info->height)
	{
		x = -1;
		while (++x < info->width)
		{
			if (is_me(info, y, x) || is_enemy(info, y, x))
				print_player_color(info, y, x, is_me(info, y, x) ? 1 : 0);
			else
				print_heat_color(info, y, x);
		}
		ft_putstr_fd("\n", 2);
	}
}
