/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 17:00:51 by tjose             #+#    #+#             */
/*   Updated: 2017/04/21 19:37:14 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	create_maps(t_mapinfo *info)
{
	int	i;

	info->heatmap = (char**)malloc(sizeof(char*) * info->height);
	info->map = (char**)malloc(sizeof(char*) * info->height);
	if (!info->heatmap || !info->map)
		return (0);
	i = -1;
	while (++i < info->height)
	{
		info->map[i] = (char*)malloc(sizeof(char) * info->width + 1);
		info->heatmap[i] = (char*)malloc(sizeof(char) * info->width + 1);
		if (!info->map[i] || !info->heatmap[i])
			return (0);
	}
	return (1);
}

static int	get_map_size(char *line, t_mapinfo *info)
{
	if (line[8] == '1' && line[9] == '5')
	{
		info->height = 15;
		info->width = 17;
	}
	else if (line[8] == '1' && line[9] == '0')
	{
		info->height = 100;
		info->width = 99;
	}
	else if (line[8] == '2')
	{
		info->height = 24;
		info->width = 40;
	}
	else
		return (0);
	return (create_maps(info));
}

static int	get_piece(char *line, t_mapinfo *info)
{
	int		i;

	i = 6;
	info->p_hei = ft_atoi(&line[i]);
	while (!ft_is_wp(line[i]))
		i++;
	info->p_wid = ft_atoi(&line[++i]);
	if (!(info->piece = (char**)malloc(sizeof(char*) * info->p_hei)))
		return (0);
	i = -1;
	while (++i < info->p_hei)
	{
		if (!(info->piece[i] = malloc(sizeof(char) * info->p_wid + 1)))
			return (0);
		get_next_line(0, &info->piece[i]);
	}
	return (1);
}

static void	get_player_num(char *line, t_mapinfo *info)
{
	if (line[10] == '1')
		info->player_number = 1;
	else if (line[10] == '2')
		info->player_number = 2;
}

int			read_info(char *line, t_mapinfo *info, int *read)
{
	static int i;

	if (line[0] == '$' && !info->height)
		get_player_num(line, info);
	if (line[0] == 'P' && line[1] == 'l' && !info->height)
	{
		if (!get_map_size(line, info))
			return (0);
	}
	if (line[0] == '0')
	{
		ft_strcpy(info->map[i], &line[4]);
		ft_strcpy(info->heatmap[i++], &line[4]);
		if (i == info->height)
			i = 0;
	}
	if (line[0] == 'P' && line[1] == 'i')
	{
		if (!get_piece(line, info))
			return (0);
		create_heatmap(info);
		*read = 1;
	}
	return (1);
}
