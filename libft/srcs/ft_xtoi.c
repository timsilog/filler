/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 17:30:37 by tjose             #+#    #+#             */
/*   Updated: 2017/03/09 14:58:55 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_xtoi(char *s)
{
	int	i;
	int	ans;
	int	multiplier;

	i = ft_strlen(s) - 1;
	ans = 0;
	multiplier = 1;
	while (i >= 0)
	{
		if (s[i] >= 'A' && s[i] <= 'F')
			ans += multiplier * (s[i] - ('A' - 10));
		else if (s[i] >= 'a' && s[i] <= 'f')
			ans += multiplier * (s[i] - ('a' - 10));
		else if (s[i] >= '0' && s[i] <= '9')
			ans += multiplier * (s[i] - '0');
		multiplier *= 16;
		i--;
	}
	return (ans);
}
