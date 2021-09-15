/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 17:56:07 by lmarzano          #+#    #+#             */
/*   Updated: 2021/09/15 17:56:45 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_create_export(char *str, t_list *var)
{
	char	**matrix;
	int		ret;
	t_list	*list;

	ret = 1;
	matrix = ft_split(str, '=');
	if (matrix == NULL)
		return (-1);
	if (ft_find_env(var, matrix[0], ft_strlen(matrix[0])) == NULL)
	{
		list = ft_new_datalist(matrix[0], matrix[1], 0);
		if (list == NULL)
			ret = -1;
		else
		{
			ft_lstadd_back(&var, list);
			ft_setprev(&var);
		}
	}
	else
		ret = ft_change_env(var, matrix[0], matrix[1]) == -1;
	ft_free_matrix(matrix);
	return (ret);
}

static int	ft_check_export_format(char *str)
{
	int	i;

	i = 0;
	if (ft_isalpha(str[i]) == 0)
		return (-1);
	while (ft_isalnum(str[i]) == 1)
		i++;
	if (str[i] == 0)
		return (2);
	else if (str[i] != '=')
		return (-1);
	i++;
	return (1);
}

static int	ft_run_export(char **str, t_list *var)
{
	int	i;
	int	flag;

	i = 1;
	while (str[i])
	{
		flag = ft_check_export_format(str[i]);
		if (flag == -1)
			return (ft_error(6, 0, str[i]));
		else if (flag == 1)
		{
			if (ft_create_export(str[i], var) == -1)
				return (ft_error(6, 0, str[i]));
		}
		i++;
	}
	return (1);
}

int	ft_check_export(t_parse *parse, t_list *var)
{
	char	**new_var;

	new_var = ft_calloc(3, sizeof(char *));
	if (new_var == NULL)
		return (1);
	ft_run_export(parse->input, var);
	ft_free_matrix(new_var);
	return (0);
}
