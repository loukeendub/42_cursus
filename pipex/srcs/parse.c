/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 11:17:22 by lmarzano          #+#    #+#             */
/*   Updated: 2021/07/29 15:08:09 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	ft_parse_cmd(t_data **data, char *argv, int cmd)
{
	char	*tmp;

	tmp = ft_strdup(argv);
	if (!tmp)
		return (-1);
	if (cmd == 1)
		(*data)->cmd1 = ft_split(tmp, ' ');
	else
		(*data)->cmd2 = ft_split(tmp, ' ');
	if (ft_strncmp(tmp, "/", 1) == 0 \
	|| ft_strncmp(tmp, "./", 2) == 0 \
	|| ft_strncmp(tmp, "../", 3) == 0)
	{
		if (cmd == 1)
			(*data)->flag1 = 1;
		else
			(*data)->flag2 = 1;
	}
	free(tmp);
	return (1);
}

int	ft_parse_path(t_data **data, char **envp)
{
	char	*path;
	char	**env;
	int		i;

	i = 0;
	while (envp[i])
	{
		env = ft_split(envp[i], '=');
		if (!ft_strncmp("PATH", env[0], 5))
		{
			path = ft_strdup(env[1]);
			if (path == NULL && ((*data)->flag1 == 0 || (*data)->flag2 == 0))
				return (-1);
			(*data)->path = ft_split(path, ':');
			free(path);
			ft_free_mtx(env);
			return (1);
		}
		i++;
		ft_free_mtx(env);
	}
	return (-1);
}

int	ft_parse_data(t_data **data, char **argv, char **envp)
{
	(*data)->infile = argv[1];
	(*data)->outfile = argv[4];
	if (!ft_parse_cmd(data, argv[2], 1) || !ft_parse_cmd(data, argv[3], 2))
		return (-1);
	 if (!ft_parse_path(data, envp))
		return (-1);
	return (0);
}

int	ft_check_path(t_data **data, char **pathcmd, char *cmd)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((*data)->path[i])
	{
		tmp = ft_strjoin((*data)->path[i], "/");
		tmp = ft_strjoin(tmp, cmd);
		if (open(tmp, O_RDONLY) != -1)
		{
			*pathcmd = ft_strdup(tmp);
			free(cmd);
			cmd = ft_strdup(tmp);
			free(tmp);
			return (1);
		}
		free(tmp);
		i++;
	}
	return (0);
}

int	ft_check_data(t_data *data)
{
	data->fdin = open(data->infile, O_RDWR);
	if (data->fdin < 0)
		return (ft_error(3));
	data->fdout = open(data->outfile, O_RDWR | O_CREAT | O_TRUNC);
	if (data->fdout < 0)
		return (ft_error(3));
	if (data->flag1 == 0)
	{
		if (!ft_check_path(&data, &data->pathcmd1, data->cmd1[0]))
			return (ft_error(4));
	}
	else
		data->pathcmd1 = ft_strdup(data->cmd1[0]);
	if (data->flag2 == 0)
	{
		if (!ft_check_path(&data, &data->pathcmd2, data->cmd2[0]))
			return (ft_error(4));
	}
	else
		data->pathcmd2 = ft_strdup(data->cmd2[0]);
	return (0);
}
