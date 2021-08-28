/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 09:38:53 by lmarzano          #+#    #+#             */
/*   Updated: 2021/01/22 09:56:00 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*str;

	str = s;
	if (c)
	{
		while (*str && c)
		{
			if ((unsigned char)*str == (unsigned char)c)
				return ((char *)str);
			str++;
		}
	}
	else
	{
		while (*str)
			str++;
		return ((char *)str);
	}
	return (NULL);
}
