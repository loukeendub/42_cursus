/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfabi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 10:50:41 by jfabi             #+#    #+#             */
/*   Updated: 2021/01/24 11:02:05 by jfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isin(char s, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		cont;
	char	*ret;

	if (s1 == 0)
		return (ft_strdup(""));
	i = 0;
	cont = 0;
	while (s1[i] != 0 && isin(s1[i], set))
		i++;
	if (s1[i] == 0)
		return (ft_strdup(""));
	cont = i;
	i = ft_strlen(s1) - 1;
	while (isin(s1[i], set))
		i--;
	ret = (char *)malloc(sizeof(char) * (i - cont + 2));
	if (ret == 0)
		return (0);
	ft_strlcpy(ret, s1 + cont, (i - cont) + 2);
	return (ret);
}
