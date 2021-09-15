/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 17:59:22 by lmarzano          #+#    #+#             */
/*   Updated: 2021/09/15 18:00:02 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_check_red(char *line, char c)
{
	int	i;
	int	flag;

	i = 0;
	if (line[i] == c)
		i++;
	if (line[i] == c && c == '<')
		i++;
	while (line[i] == ' ')
		i++;
	flag = ft_in_str("\"#&\'()*\\;?`><", line[i]);
	if (flag == 1 && (line[i + 1] == ' ' || line[i + 1] == 0))
		return (ft_error(1, line[i], NULL));
	flag = ft_in_str("!#&()\\;`<>", line[i]);
	if (flag == 1 && (line[i + 1] != ' ' || line[i + 1] != 0))
		return (ft_error(1, line[i], NULL));
	flag = ft_in_str("./~", line[i]);
	if (flag == 1 && (line[i + 1] == ' ' || line[i + 1] == 0))
		return (ft_error(2, line[i], NULL));
	flag = ft_in_str("/~", line[i]);
	if (flag == 1 && (line[i + 1] != ' ' || line[i + 1] != 0))
		return (ft_error(2, line[i], NULL));
	if (line[i] == 0)
		return (ft_error(3, 0, NULL));
	return (1);
}

static int	ft_flag_check(char *str)
{
	int	num;

	num = 0;
	if ((str[0] == '<' || str[0] == '>'))
		num = ft_check_red(str + 1, str[0]);
	return (num);
}

static int	ft_is_empty(char *line)
{
	int	i;
	int	j;

	i = 0;
	if (line == NULL)
		return (1);
	while (line[i] == ' ')
		i++;
	j = i;
	while (line[i])
		i++;
	if (i == j)
		return (1);
	return (0);
}

int	ft_parse_check(char *line)
{
	int	i;
	int	flg;

	i = 0;
	flg = 0;
	if (ft_is_empty(line) == 1)
		return (-1);
	while (line && line[i])
	{
		if (line[i] == '\'' && flg == 0 && ft_find_next_c(line, i, '\''))
			flg = 1;
		else if (line[i] == '\'' && flg == 1)
			flg = 0;
		else if (line[i] == '\"' && flg == 0 && ft_find_next_c(line, i, '\"'))
			flg = 2;
		else if (line[i] == '\"' && flg == 2)
			flg = 0;
		if (flg == 0 && ft_in_str("!><", line[i]))
		{
			if (ft_flag_check(line + i) == -1)
				return (-1);
		}
		i++;
	}
	return (1);
}

int	ft_check_command(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (!ft_in_str(">< ", str[i]))
			return (1);
		else if (ft_in_str("><", str[i]) && !ft_in_quotes(str, i, '\'', '\"'))
		{
			while (ft_in_str("><", str[i]))
				i++;
			while (str[i] == ' ')
				i++;
			while (str[i] && !ft_in_str(">< ", str[i]))
				i++;
		}
		else
			i++;
	}
	return (-1);
}
