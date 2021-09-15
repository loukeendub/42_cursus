/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 17:55:41 by lmarzano          #+#    #+#             */
/*   Updated: 2021/09/15 17:56:45 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_cd(char *path, char *input, t_list *var)
{
	int		cd;
	char	*pwd;
	char	*oldpwd;

	oldpwd = ft_find_env(var, "PWD", 3);
	cd = chdir(path);
	if (cd == -1)
		return (ft_error(5, 0, input));
	pwd = malloc(4097);
	getcwd(pwd, 4097);
	if (pwd == NULL)
		return (1);
	free(pwd);
	ft_add_env(var, "OLDPWD", oldpwd, 0);
	if (ft_add_env(var, "PWD", path, 0) == -1)
		return (1);
	return (0);
}

static char	*ft_run_cd(char **output, t_list *var)
{
	int		i;
	char	*path;

	i = 1;
	if (output && output[i])
	{
		if (ft_strncmp(output[i], "-", 2) == 0)
			path = ft_create_minus_path(var);
		else if (output[i][0] == '/')
		{
			path = malloc(ft_strlen(output[i]) + 1);
			if (path == NULL)
				return (NULL);
			ft_strlcpy(path, output[i], ft_strlen(output[i]) + 1);
		}
		else
			path = ft_create_path(var, output[i]);
		i++;
	}
	if (i == 1)
		path = ft_create_home_path(var);
	return (path);
}

static int	ft_check_flag(char **input)
{
	int	flag;

	flag = 0;
	if (input[1] == NULL)
		return (0);
	else if (ft_strncmp(input[1], "-", 2) == 0)
		flag = 1;
	return (flag);
}

int	ft_check_cd(t_parse *parse, t_list *var)
{
	char	*path;
	char	*print;
	int		flag;
	int		num;

	flag = ft_check_flag(parse->input);
	path = ft_run_cd(parse->input, var);
	if (path == NULL)
		return (1);
	num = ft_cd(path, parse->input[1], var);
	if (flag == 1)
	{
		print = ft_get_pwd();
		ft_putstr_fd(print, 1);
		ft_putchar_fd('\n', 1);
		free(print);
	}
	free(path);
	return (num);
}
