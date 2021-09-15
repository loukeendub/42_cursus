/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 18:02:04 by lmarzano          #+#    #+#             */
/*   Updated: 2021/09/15 18:02:18 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_m_strlcpy(char *str, int len)
{
	char	*ret;

	if (len == 0)
		return (NULL);
	ret = malloc(len);
	if (ret == NULL)
		return (NULL);
	if (str == NULL)
		ret[0] = 0;
	else
		ft_strlcpy(ret, str, len);
	return (ret);
}

void	ft_null(int signal)
{
	if (signal == 2)
		ft_putendl_fd("", 2);
	else if (signal == 3)
	{
		ft_putstr_fd("Quit: ", 2);
		ft_putnbr_fd(signal, 2);
		ft_putendl_fd("", 2);
	}
	else
		return ;
}

void	*ft_free_null(void	*obj)
{
	free(obj);
	return (NULL);
}

int	ft_find_strposition(char *str, char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		if (ft_strncmp(matrix[i], str, ft_strlen(str) + 1) == 0)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_free_data(t_data *data)
{
	t_data	*d;

	d = data;
	free(d->content);
	free(d->env);
	free (data);
}
