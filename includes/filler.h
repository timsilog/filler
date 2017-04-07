/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 15:32:08 by tjose             #+#    #+#             */
/*   Updated: 2017/04/06 19:56:37 by tjose            ###   ########.fr       */
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
}				t_mapinfo;
int				read_info(char *line, t_mapinfo *mapinfo);

#endif
