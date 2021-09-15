/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 17:56:14 by lmarzano          #+#    #+#             */
/*   Updated: 2021/09/15 17:56:45 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_pwd(void)
{
	char	*pwd;

	pwd = malloc(4097);
	if (pwd != NULL)
		getcwd(pwd, 4097);
	return (pwd);
}

static int	ft_pwd(int fd, t_list *var)
{
	char	*pwd;

	pwd = malloc(4097);
	if (pwd != NULL)
	{
		getcwd(pwd, 4097);
		ft_putstr_fd(pwd, fd);
		ft_putchar_fd('\n', fd);
		free(pwd);
		return (0);
	}
	return (1);
}

int	ft_check_pwd(t_parse *parse, t_list *var)
{
	int	num;

	num = ft_pwd(1, var);
	return (num);
}
