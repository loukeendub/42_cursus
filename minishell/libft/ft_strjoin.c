/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfabi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 10:44:47 by jfabi             #+#    #+#             */
/*   Updated: 2021/01/24 10:46:50 by jfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_prot(const char *s)
{
	size_t	i;

	i = 0;
	if (s == 0)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		i;
	char	*ret;

	len = ft_strlen_prot(s1) + ft_strlen_prot(s2) + 1;
	ret = (char *)malloc(sizeof(char) * len);
	if (ret == 0)
		return (0);
	i = 0;
	while (i < ft_strlen_prot(s1))
	{
		ret[i] = s1[i];
		i++;
	}
	while (i < (ft_strlen_prot(s1) + ft_strlen_prot(s2)))
	{
		ret[i] = s2[i - ft_strlen_prot(s1)];
		i++;
	}
	ret[i] = 0;
	return (ret);
}
