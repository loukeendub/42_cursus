/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_com.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 17:54:23 by lmarzano          #+#    #+#             */
/*   Updated: 2021/09/15 17:56:45 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_exit_code(int sign)
{
	printf("Dentro léxit code\n");
	exit(130);
}

static int	ft_execute_child(t_parse *parse, t_list *var)
{
	int		ret;
	char	*path;
	char	**mtx;

	path = ft_check_path(parse->command, var);
	if (path != NULL)
	{
		mtx = ft_lst_to_mtx(var);
		ret = execve(path, parse->input, mtx);
		printf("%d\n", ret);
		if (ret < 0)
			ft_putstr_fd(strerror(errno), 2);
		ft_free_matrix(mtx);
		free(path);
	}
	else
	{
		ft_putstr_fd(": command not found: ", 2);
		ft_putstr_fd(parse->command, 2);
		ft_putstr_fd("\n", 2);
		return (127);
	}
	return (ret);
}

int	ft_execute_command(t_parse *parse, t_list *var)
{
	int		pid;
	int		status;
	char	*path;
	char	**mtx;

	pid = fork();
	if (pid == 0)
	{
		exit(ft_execute_child(parse, var));
	}
	else
	{
		signal(SIGINT, ft_null);
		signal(SIGQUIT, ft_null);
		waitpid(pid, &status, 0);
		signal(SIGINT, ft_aspetta);
		signal(SIGQUIT, ft_aspetta);
		if (status == 2 || status == 3)
			return (status + 128);
		return (WEXITSTATUS(status));
	}
}
