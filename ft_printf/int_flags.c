/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:17:59 by lmarzano          #+#    #+#             */
/*   Updated: 2021/02/16 18:00:45 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*d_manager(char *s)
{
	char	*t;
	size_t	len;

	s = ft_itoa(va_arg(g_c->args, int));
	if (g_c->wd > 0)
	{
		len = (g_c->wd - ft_strlen(s));
		if (!(t = ft_calloc((len + 1), sizeof(char))))
			return (0);
		t[len] = '\0';
		s = int_precision(s, t, len);
	}
	else if (g_c->pr > 0)
	{
		len = (g_c->pr - ft_strlen(s));
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
	if (g_c->wd > 0)
	{
		len = (g_c->wd - ft_strlen(s));
		if (!(t = ft_calloc((len + 1), sizeof(char))))
			return (0);
		t[len] = '\0';
		s = int_precision(s, t, len);
	}
	else if (g_c->pr > 0)
	{
		len = (g_c->pr - ft_strlen(s));
		if (!(t = ft_calloc((len + 1), sizeof(char))))
			return (0);
		t[len] = '\0';
		s = int_precision(s, t, len);
	}
	return (s);
}

char	*int_precision(char *s, char *t, size_t len)
{
	if (g_c->pr == 0 && s[0] == '0')
	{
		len = g_c->wd;
		while (len-- > 0)
			s[len] = ' ';
	}
	else if (g_c->pr > 0 && g_c->pr >= ft_strlen(s))
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
	if (len > g_c->pr)
	{
		len = g_c->pr - ft_strlen(s);
		while (len-- > 0)
			t[len] = '0';
		s = int_flags(t, s);
		len = g_c->wd - g_c->pr;
		t[len] = '\0';
	}
	else
	{
		len = g_c->pr - ft_strlen(s);
		while (len-- > 0)
			t[len] = '0';
		s = int_flags(t, s);
	}
	if (g_c->wd - g_c->pr > 0)
		s = fill_space(s);
	return (s);
}

char	*int_flags(char *s, char *t)
{
	if ((g_c->type == 'x' || g_c->type == 'X') && g_c->flags[1] == '#')
		s = g_c->type == 'X' ? ft_strjoin("0X", s) : ft_strjoin("0x", s);
	s = ft_strjoin(s, t);
	s = sign_manager(s, t);
	return (s);
}
