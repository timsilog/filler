/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   let_it_go.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 13:54:27 by tjose             #+#    #+#             */
/*   Updated: 2017/04/10 15:25:13 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_the_piece(t_mapinfo *info)
{
	int	i;

	i = -1;
	while (++i < info->p_hei)
		free(info->piece[i]);
	free(info->piece);
}

void	free_the_map(t_mapinfo *info)
{
	int i;

	i = -1;
	while (++i < info->height)
		free(info->map[i]);
	free(info->map);
}
