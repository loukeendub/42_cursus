/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtr_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 18:01:45 by lmarzano          #+#    #+#             */
/*   Updated: 2021/09/15 18:02:18 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_mtrlcpy(char **src, int len)
{
	char	**ret;
	int		i;

	i = 0;
	ret = malloc(sizeof(char *) * (ft_mtrlen(src) + 1));
	if (ret == 0)
		return (NULL);
	while (src[i] && i < len)
	{
		ret[i] = malloc(sizeof(ft_strlen(src[i])) + 1);
		if (ret[i] == 0)
		{
			ft_free_matrix(ret);
			return (NULL);
		}
		ft_strlcpy(ret[i], src[i], ft_strlen(src[i]) + 1);
		i++;
	}
	ret[i] = 0;
	return (ret);
}

int	ft_mtrlen(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

void	*ft_free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix && matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	return (NULL);
}
