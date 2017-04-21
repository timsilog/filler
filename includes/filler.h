/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 15:32:08 by tjose             #+#    #+#             */
/*   Updated: 2017/04/20 23:11:29 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libft/includes/libft.h"

typedef struct	s_mapinfo
{
	int			player_number;
	int			height;
	int			width;
	int			p_wid;
	int			p_hei;
	char		**map;
	char		**piece;
	char		**heatmap;
}				t_mapinfo;
int				read_info(char *line, t_mapinfo *info);
int				place_piece(t_mapinfo *info);
int				is_me(t_mapinfo *info, int y, int x);
int				is_enemy(t_mapinfo *info, int y, int x);
void			free_the_piece(t_mapinfo *info);
void			free_the_map(t_mapinfo *info);
void			create_heatmap(t_mapinfo *info);
void			draw_chase(t_mapinfo *info);

//debug stuff:
void	print_piece(t_mapinfo *info);
void	print_map(t_mapinfo *info);
void	print_heat(t_mapinfo *info);
#endif
