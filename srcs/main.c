/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 17:00:56 by tjose             #+#    #+#             */
/*   Updated: 2017/04/25 15:27:58 by tjose            ###   ########.fr       */
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

static void			play_the_game(t_mapinfo *info)
{
	char	*line;
	int		read;

	read = 0;
	while (1)
	{
		while (!read)
		{
			get_next_line(0, &line);
			if (!read_info(line, info, &read))
			{
				ft_printf("Map read error\n");
				return ;
			}
		}
		if (!place_piece(info))
		{
			free_the_piece(info);
			return ;
		}
		free_the_piece(info);
		read = 0;
		//sleep(1);
	}
}

int					main(void)
{
	t_mapinfo	*info;

	if (!(info = init_mapinfo()))
	{
		ft_printf("Error");
		return (-1);
	}
	play_the_game(info);
	free_the_map(info);
	return (0);
}
