/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:17:59 by lmarzano          #+#    #+#             */
/*   Updated: 2021/02/15 16:59:58 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*d_manager(char *s)
{
	char	*t;
	size_t	len;

	s = ft_itoa(va_arg(g_c->args, int));
	if (g_c->width > 0)
	{
		len = (g_c->width - ft_strlen(s));
		if (!(t = ft_calloc((len + 1), sizeof(char))))
			return (0);
		t[len] = '\0';
		s = int_precision(s, t, len);
	}
	return (s);
}

char	*u_manager(char *s)
{
	char	*t;
	size_t	len;

	s = ft_utoa(va_arg(g_c->args, int));
	if (g_c->width > 0)
	{
		len = (g_c->width - ft_strlen(s));
		if (!(t = ft_calloc((len + 1), sizeof(char))))
			return (0);
		t[len] = '\0';
		s = int_precision(s, t, len);
	}
	return (s);
}

char	*int_precision(char *s, char *t, size_t len)
{
	if (g_c->prec == 0 && s[0] == '0')
	{
		len = g_c->width;
		while (len-- > 0)
			s[len] = ' ';
	}
	else if (g_c->prec > 0 && g_c->prec >= ft_strlen(s))
		s = prec_manager(s, t, len);
	else
	{
		while (len-- > 0)
			t[len] = ' ';
		s = int_flags(s, t);
	}
	return (s);
}

char	*prec_manager(char *s, char *t, size_t len)
{
	if (len > g_c->prec)
	{
		len = g_c->prec - ft_strlen(s);
		while (len-- > 0)
			t[len] = '0';
		s = int_flags(t, s);
		len = g_c->width - g_c->prec;
		t[len] = '\0';
		while (len-- > 0)
			t[len] = ' ';
		s = ft_strjoin(s, t);
	}
	else
	{
		len = g_c->prec - ft_strlen(s);
		while (len-- > 0)
			t[len] = '0';
		s = int_flags(t, s);
	}
	return (s);
}

char	*int_flags(char *s, char *t)
{
	if (g_c->width < g_c->prec || g_c->flags[0] == '-')
		s = ft_strjoin(s, t);
	else
		s = ft_strjoin(t, s);
	return (s);
}
