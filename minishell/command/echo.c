/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfabi <jfabi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 11:33:23 by jfabi             #+#    #+#             */
/*   Updated: 2021/07/08 18:09:42 by jfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_echo(char **stringa, int fd)
{
	int	i;
	int	flag;
	int	flag2;

	flag = 0;
	i = 1;
	while (stringa && stringa[i] != 0 && ft_strncmp(stringa[i], "-n", 3) == 0)
	{
		flag = 1;
		i++;
		flag2 = i;
	}
	while (stringa && stringa[i])
	{
		if ((flag == 1 && i == flag2) || (flag == 0 && i == 1))
			ft_putstr_fd(stringa[i], fd);
		else
		{
			ft_putchar_fd(' ', fd);
			ft_putstr_fd(stringa[i], fd);
		}
		i++;
	}
	if (flag == 0)
		ft_putchar_fd('\n', fd);
}

int	ft_check_echo(t_parse *parse)
{
	ft_echo(parse->input, 1);
	return (0);
}
