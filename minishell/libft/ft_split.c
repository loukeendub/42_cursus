/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfabi <jfabi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 13:25:59 by jfabi             #+#    #+#             */
/*   Updated: 2021/06/21 17:10:39 by jfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && (i == 0 || str[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static void	free_matrix(char **matrix)
{
	int		i;

	i = 0;
	while (matrix[i] != NULL)
		free(matrix[i++]);
	free(matrix);
}

static int	split(char const *s, char **matrix, char c)
{
	int	mat_i;
	int	i;
	int	word_len;

	mat_i = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			word_len = 0;
			while (s[i + word_len] != c && s[i + word_len] != '\0')
				word_len++;
			matrix[mat_i] = malloc(word_len + 1);
			if (matrix[mat_i] == NULL)
				return (-1);
			ft_strlcpy(matrix[mat_i], (s + i), word_len + 1);
			matrix[mat_i++][word_len] = '\0';
			i += word_len;
		}
		else
			i++;
	}
	return (mat_i);
}

char	**ft_split(char const *s, char c)
{
	int		mat_i;
	char	**matrix;

	if (s == NULL)
		return (NULL);
	matrix = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (matrix == NULL)
		return (NULL);
	mat_i = split(s, matrix, c);
	if ((mat_i) == -1)
	{
		free_matrix(matrix);
		return (NULL);
	}
	matrix[mat_i] = 0;
	return (matrix);
}
