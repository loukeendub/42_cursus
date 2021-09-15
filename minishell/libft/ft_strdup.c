/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfabi <jfabi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 19:02:04 by jfabi             #+#    #+#             */
/*   Updated: 2021/07/02 15:05:13 by jfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*ret;

	i = ft_strlen(s1) + 1;
	ret = malloc(i);
	if (ret == 0)
		return (0);
	ft_strlcpy(ret, s1, i);
	return (ret);
}
