/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 10:46:37 by lmarzano          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/03/19 14:55:42 by lmarzano         ###   ########.fr       */
=======
/*   Updated: 2021/01/28 16:16:42 by lmarzano         ###   ########.fr       */
/*   Updated: 2021/01/28 17:56:29 by lmarzano         ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_realloc(char **line)
{
	char	*new;
	int		i;

	i = 0;
	if (!(new = malloc(ft_strlen(*line) + BUFFER_SIZE + 1)))
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
	if (!(new = malloc(ft_strlen(*line) + 1)))
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
