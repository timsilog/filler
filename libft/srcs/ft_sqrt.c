/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 19:04:49 by tjose             #+#    #+#             */
/*   Updated: 2017/04/12 21:30:13 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int nb)
{
	int guess;

	guess = 0;
	if (nb > 2147395600)
		return (0);
	while (guess * guess < nb)
		guess++;
	if (guess * guess == nb)
		return (guess);
	while (guess * guess > nb)
	{
		guess--;
	}
	return (guess);
}
