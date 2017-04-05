#ifndef FILLER_H
# define FILLER_H
# include "../libft/includes/libft.h"

typedef struct	s_mapinfo
{
	int			height;
	int			width;
	char		**map;
	t_coord		*piece;
}				t_mapinfo;
typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;
int				get_map(char *line, t_mapinfo *mapinfo);

#endif
