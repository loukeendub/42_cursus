/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 17:57:18 by lmarzano          #+#    #+#             */
/*   Updated: 2021/09/15 17:57:20 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_open_red(char **output, int *fd_in, int *fd_out, t_list *history)
{
	int	i;
	int	flag;
	int	fd[2];

	i = 0;
	fd[0] = 0;
	fd[1] = 1;
	while (output && output[i])
	{
		flag = ft_is_flag(output[i]);
		if (fd[flag % 2] != flag % 2)
			close (fd[flag % 2]);
		if (flag == 1 || flag == 3 || flag == 2)
			fd[flag % 2] = ft_open_arrow(flag, output[i + 1]);
		if (flag == 4)
			fd[flag % 2] = ft_run_extra_terminal(output[i + 1], history);
		if (fd[1] < 0 || fd[0] < 0)
			return (-1);
		i += 2;
	}
	*fd_in = fd[0];
	*fd_out = fd[1];
	return (0);
}

void	ft_save_fd(int *fd_in, int *fd_out)
{
	*fd_in = dup(STDIN_FILENO);
	*fd_out = dup(STDOUT_FILENO);
	g_fd = *fd_in;
}

void	ft_restore_fd(int fd[2])
{
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
}
