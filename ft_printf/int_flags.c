/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:17:59 by lmarzano          #+#    #+#             */
/*   Updated: 2021/02/12 18:48:31 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*d_flags(char *s)
{
	char	*t;
	size_t	len;

	s = ft_itoa(va_arg(g_c->args, int));
	if (g_c->width > 0)
	{
		len = (g_c->width - ft_strlen(s));
		if (!(t = malloc((len + 1) * sizeof(char))))
			return (0);
		t[len + 1] = '\0';
		while (len-- > 0)
			t[len] = ' ';
		s = (g_c->flags[0] == '-' ? ft_strjoin(s, t) : ft_strjoin(t, s));
	}
	return (s);
}
