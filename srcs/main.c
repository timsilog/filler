/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 17:00:56 by tjose             #+#    #+#             */
/*   Updated: 2017/04/06 19:58:21 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** dimensions are all in HEIGHT by WIDTH
** map sizes are: 15 17, 24 40, and 100 99
**
** if "plateau" get map dimensions and make 2d array of char
** copy map into 2d array
** if "piece" get piece
** getnextline piece's height more times to get actual piece
** use is_safe function to place piece
*/

static t_mapinfo	*init_mapinfo(void)
{
	t_mapinfo *mapinfo;

	if (!(mapinfo = malloc(sizeof(t_mapinfo))))
		return (NULL);
	mapinfo->height = 0;
	mapinfo->width = 0;
	return (mapinfo);
}

int					main(void)
{
	char		*line;
	t_mapinfo	*mapinfo;
	int			read;

	if (!(mapinfo = init_mapinfo()))
	{
		ft_printf("Error");
		return (-1);
	}
	read = 0;
	while (!read)
	{
		get_next_line(0, &line);
		if (!read_info(line, mapinfo))
		{
			ft_printf("Map read error\n");
			return (-1);
		}
		ft_putstr_fd(line, 2);
		ft_putstr_fd("a\n", 2);
		if (line[0] == 'P' && line[1] == 'i')
			read = 1;
	}
	ft_printf("8 2\n");
	ft_putstr_fd(mapinfo->piece[0], 2);
	ft_putstr_fd("<<<", 2);
	//place_piece(mapinfo);
	// dont forget to free piece and map!!
	return (0);
}
