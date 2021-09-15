/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 17:56:35 by lmarzano          #+#    #+#             */
/*   Updated: 2021/09/15 17:56:45 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_set_path(char **mtx, char *str)
{
	char		*path;
	int			i;
	struct stat	sb;

	i = 0;
	while (mtx[i])
	{
		path = malloc(ft_strlen(mtx[i]) + ft_strlen(str) + 2);
		if (path == NULL)
			return (NULL);
		ft_memcpy(path, mtx[i], ft_strlen(mtx[i]));
		ft_memcpy(path + ft_strlen(mtx[i]), "/", 1);
		ft_strlcpy(path + ft_strlen(mtx[i]) + 1, str, ft_strlen(str) + 1);
		if (lstat(path, &sb) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

char	*ft_check_path(char *str, t_list *var)
{
	char		**mtx;
	char		*path;
	char		*indirizzo;
	struct stat	sb;

	path = malloc(ft_strlen(str) + 1);
	if (path == NULL)
		return (NULL);
	ft_strlcpy(path, str, ft_strlen(str) + 1);
	if (lstat(path, &sb) == 0)
		return (path);
	free(path);
	indirizzo = ft_find_env(var, "PATH", 4);
	if (indirizzo == NULL)
		return (NULL);
	mtx = ft_split(indirizzo, ':');
	if (mtx == NULL)
		return (NULL);
	path = ft_set_path(mtx, str);
	ft_free_matrix(mtx);
	return (path);
}
