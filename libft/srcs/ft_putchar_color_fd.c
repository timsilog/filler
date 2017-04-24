/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_color_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:29:36 by tjose             #+#    #+#             */
/*   Updated: 2017/04/24 16:04:22 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** FOREGROUND COLORS
*/
#define BLACK "\x1b[30m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define WHITE "\x1b[37m"
#define LGRAY "\x1b[90m"
#define LRED "\x1b[91m"
#define LGREEN "\x1b[92m"
#define LYELLOW "\x1b[93m"
#define LBLUE "\x1b[94m"
#define LMAGENTA "\x1b[95m"
#define LCYAN "\x1b[96m"
#define LWHITE "\x1b[97m"
#define RESET "\x1b[0m"

void	ft_putchar_color_fd(char c, t_color color, int fd)
{
	char *colors[0];

	colors[0] = BLACK;
	colors[1] = RED;
	colors[2] = GREEN;
	colors[3] = YELLOW;
	colors[4] = BLUE;
	colors[5] = MAGENTA;
	colors[6] = CYAN;
	colors[7] = WHITE;
	colors[8] = LGRAY;
	colors[9] = LRED;
	colors[10] = LGREEN;
	colors[11] = LYELLOW;
	colors[12] = LBLUE;
	colors[13] = LMAGENTA;
	colors[14] = LCYAN;
	colors[15] = LWHITE;
	ft_putstr_fd(colors[color], fd);
	write(fd, &c, 1);
	return ;
}
