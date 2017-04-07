/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 17:00:51 by tjose             #+#    #+#             */
/*   Updated: 2017/04/06 19:55:11 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	create_map(t_mapinfo *mapinfo)
{
	int	i;

	if (!(mapinfo->map = (char**)malloc(sizeof(char*) * mapinfo->height)))
		return (0);
	i = -1;
	while (++i < mapinfo->height)
	{
		if (!(mapinfo->map[i] = (char*)malloc(sizeof(char)
						* mapinfo->width + 1)))
			return (0);
	}
	return (1);
}

static int	get_map_size(char *line, t_mapinfo *mapinfo)
{
	if (line[8] == '1' && line[9] == '5')
	{
		mapinfo->height = 15;
		mapinfo->width = 17;
	}
	else if (line[8] == '1' && line[9] == '0')
	{
		mapinfo->height = 100;
		mapinfo->width = 99;
	}
	else if (line[8] == '2')
	{
		mapinfo->height = 24;
		mapinfo->width = 40;
	}
	else
		return (0);
	return (create_map(mapinfo));
}

static int	get_piece(char *line, t_mapinfo *mapinfo)
{
	int		i;

	i = 6;
	mapinfo->p_hei = ft_atoi(&line[i]);
	while (!ft_is_wp(line[i]))
		i++;
	mapinfo->p_wid = ft_atoi(&line[++i]);
	if (!(mapinfo->piece = (char**)malloc(sizeof(char*) * mapinfo->p_hei)))
		return (0);
	i = -1;
	while (++i < mapinfo->p_hei)
	{
		if (!(mapinfo->piece[i] = malloc(sizeof(char) * mapinfo->p_wid + 1)))
			return (0);
		get_next_line(0, &mapinfo->piece[i]);
	}
	return (1);
}

static void	get_player_num(char *line, t_mapinfo *mapinfo)
{
	if (line[10] == '1')
		mapinfo->player_number = 1;
	else if (line[10] == '2')
		mapinfo->player_number = 2;
}

int			read_info(char *line, t_mapinfo *mapinfo)
{
	int i;

	i = 0;
	if (line[0] == '$')
		get_player_num(line, mapinfo);
	if (line[0] == 'P' && line[1] == 'l' && !mapinfo->height)
	{
		if (!get_map_size(line, mapinfo))
			return (0);
	}
	if (line[0] == '0')
		ft_strcpy(mapinfo->map[i++], &line[4]);
	if (line[0] == 'P' && line[1] == 'i')
	{
		if (!get_piece(line, mapinfo))
			return (0);
	}
	return (1);
}
