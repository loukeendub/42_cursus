/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 18:01:31 by lmarzano          #+#    #+#             */
/*   Updated: 2021/09/15 18:02:18 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_add_history(t_list *history)
{
	while (history)
	{
		add_history(history->content);
		history = history->next;
	}
}

static int	ft_run_extra_terminal_child(char *del, int fd, t_list *history)
{
	char	*line;

	signal(SIGINT, ft_ciao);
	signal(SIGQUIT, ft_ciao);
	dup2(g_fd, STDIN_FILENO);
	ft_add_history(history);
	line = readline("> ");
	while (line)
	{
		if (ft_strncmp(line, del, ft_strlen(del) + 1) == 0)
			return (0);
		ft_putendl_fd(line, fd);
		line = readline("> ");
	}
	return (0);
}

int	ft_run_extra_terminal(char *del, t_list *history)
{
	pid_t	pid;
	int		status;
	int		fd;

	fd = open(".heredoc", O_RDWR | O_TRUNC | O_CREAT, 00755);
	if (fd == -1)
		return (-1);
	pid = fork();
	if (pid < 0)
		return (-1);
	else if (pid == 0)
		exit(ft_run_extra_terminal_child(del, fd, history));
	else
	{
		waitpid(pid, &status, 0);
		close (fd);
		if (status == 0)
			fd = open(".heredoc", O_RDONLY, 00755);
		else
			fd = open(".heredoc", O_RDONLY | O_TRUNC, 00755);
		return (fd);
	}
}

int	ft_open_arrow(int flag, char *stringa)
{
	int	fd;

	if (flag == 1)
		fd = open(stringa, O_WRONLY | O_CREAT | O_TRUNC, 00755);
	else if (flag == 2)
		fd = open(stringa, O_RDONLY);
	if (flag == 3)
		fd = open(stringa, O_WRONLY | O_APPEND | O_CREAT, 00755);
	if (fd < 0)
	{
		ft_putstr_fd("#: ", 2);
		ft_putstr_fd(stringa, 2);
		ft_putstr_fd(". No such file or directory\n", 2);
	}
	return (fd);
}
