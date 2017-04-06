#ifndef FILLER_H
# define FILLER_H
# include "../libft/includes/libft.h"

typedef struct	s_mapinfo
{
	int			player_number;
	int			height;
	int			width;
	char		**map;
	char		*piece;
}				t_mapinfo;
int				read_info(char *line, t_mapinfo *mapinfo);

#endif
