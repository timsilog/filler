/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 17:00:56 by tjose             #+#    #+#             */
/*   Updated: 2017/04/05 19:16:49 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

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

void	init_mapinfo(t_mapinfo *mapinfo)
{
	mapinfo->height = 0;
	mapinfo->width = 0;
}

int		main()
{
	char		*line;
	t_mapinfo	*mapinfo;

	init_mapinfo(map_info);
	line = malloc(sizeof(char) * 105);
	while (get_next_line(0, &line))
	{
		if (!read_info(line, mapinfo))
		{
			ft_printf("Map read error\n");
			return (-1);
		}
	}
	return (0);
}
