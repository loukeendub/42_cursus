/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfabi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 15:25:37 by jfabi             #+#    #+#             */
/*   Updated: 2021/02/27 18:45:14 by jfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*copia(char *s1, const char *s2)
{
	int	i;

	i = 0;
	if (s2 == 0)
		return (s1);
	while (s2[i] != 0)
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = 0;
	return (s1);
}

int	ft_strlenn(const char *s)
{
	int	i;

	i = 0;
	if (s == 0)
		return (0);
	while (s[i] != 0)
		i++;
	return (i);
}
