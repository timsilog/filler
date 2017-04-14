/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 14:36:28 by tjose             #+#    #+#             */
/*   Updated: 2017/04/13 16:53:45 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <unistd.h>
//delete this file later!!!

void	print_piece(t_mapinfo *info)
{
	int i = -1;
	// piece dimensions:
	ft_putstr_fd(">piece: ", 2);
	ft_putstr_fd(ft_itoa(info->p_hei), 2);
	ft_putstr_fd(" ", 2);
	ft_putstr_fd(ft_itoa(info->p_wid), 2);
	ft_putstr_fd("\n", 2);
	// actual piece:
	while (++i < info->p_hei)
	{
		ft_putstr_fd(info->piece[i], 2);
		ft_putstr_fd("<\n", 2);
	}
}

void	print_map(t_mapinfo *m)
{
	int i = -1;
	ft_putstr_fd(">MAP:\n", 2);
	while (++i < m->height)
	{
		ft_putstr_fd(m->map[i], 2);
		ft_putstr_fd("\n", 2);
	}
}

void	print_heat(t_mapinfo *m)
{
	int i = -1;
	int j;
	ft_putstr_fd(">HEAT:\n", 2);
	while (++i < m->height)
	{
		j = -1;
		while (++j < m->width)
		{
			ft_putstr_fd(ft_itoa((int)m->heatmap[i][j]), 2);
			ft_putstr_fd(" ", 2);
		}
		ft_putstr_fd("\n", 2);
	}
}
