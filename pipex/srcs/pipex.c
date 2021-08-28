/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 11:17:22 by lmarzano          #+#    #+#             */
/*   Updated: 2021/07/29 15:10:16 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	ft_exec_cmd(t_data *data, char **envp, int cmd)
{
	int	ret;

	if (cmd == 1)
	{
		dup2(data->fdin, 0);
		dup2(data->fd[1], 1);
		ret = execve(data->pathcmd1, data->cmd1, envp);
		if (ret == -1)
			return (ft_error(0));
	}
	else if (cmd == 2)
	{
		close(data->fdin);
		close(data->fd[1]);
		dup2(data->fd[0], 0);
		dup2(data->fdout, 1);
		close(data->fdout);
		close(data->fd[0]);
		if (execve(data->pathcmd2, data->cmd2, envp) == -1)
			return (ft_error(0));
	}
	return (1);
}

int	ft_exec_pipe(t_data *data, char **envp)
{
	data->fork_id = fork();
	if (data->fork_id == 0)
	{
		ft_exec_cmd(data, envp, 1);
		exit(0);
	}
	else if (data->fork_id == -1)
		return (ft_error(1));
	else
	{
		waitpid(data->fork_id, NULL, 0);
		ft_exec_cmd(data, envp, 2);
	}
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;

	if (argc != 5)
		return (ft_error(1));
	data = malloc(sizeof(t_data));
	if (!data)
		return (ft_error(0));
	ft_struct_init(data);
	if (ft_parse_data(&data, argv, envp) == -1)
		return (ft_error(0));
	if (ft_check_data(data) == -1)
		return (ft_error(0));
	if (pipe(data->fd) != 0)
		return (ft_error(0));
	if (ft_exec_pipe(data, envp) == -1)
		return (ft_error(5));
	ft_free_data(&data);
	free(data);
	return (0);
}
