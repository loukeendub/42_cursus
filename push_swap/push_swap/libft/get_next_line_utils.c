/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 10:46:37 by lmarzano          #+#    #+#             */
/*   Updated: 2021/05/26 14:52:13 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc(char **line)
{
	char	*new;
	int		i;

	i = 0;
	new = malloc(ft_strlen(*line) + BUFFER_SIZE + 1);
	if (!new)
		return (NULL);
	if (*line)
	{
		while ((*line)[i])
		{
			new[i] = (*line)[i];
			i++;
		}
		free(*line);
		*line = NULL;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_realloc_finale(char **line)
{
	char	*new;
	int		i;

	i = 0;
	new = malloc(ft_strlen(*line) + 1);
	if (!new)
		return (NULL);
	if (*line)
	{
		while ((*line)[i])
		{
			new[i] = (*line)[i];
			i++;
		}
		free(*line);
		*line = NULL;
	}
	new[i] = '\0';
	return (new);
}
