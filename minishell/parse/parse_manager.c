/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 17:59:45 by lmarzano          #+#    #+#             */
/*   Updated: 2021/09/15 18:00:02 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	ft_strlcpy_no_c(char *dst, char *s, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s == 0 || dst == 0)
		return (0);
	if (size != 0)
	{
		while (i < (size - 1) && s[i] != 0)
		{
			if (s[i] == '\'' && ft_is_quotes(s, i, '\'', '"') != 1)
				dst[j++] = s[i];
			else if (s[i] == '"' && ft_is_quotes(s, i, '"', '\'') != 1)
				dst[j++] = s[i];
			else if (s[i] != '\'' && s[i] != '"')
				dst[j++] = s[i];
			i++;
		}
		dst[j] = 0;
	}
	return (j);
}

static int	ft_red(char *line, char **mtx, int *flag)
{
	char	*tmp;
	int		j;
	int		k;

	j = 0;
	k = 0;
	while (line[j] == line[0])
		j++;
	tmp = malloc(j + 1);
	if (tmp == NULL)
		return (-1);
	ft_strlcpy(tmp, line, j + 1);
	while (mtx[k])
		k++;
	mtx[k] = tmp;
	*flag = 1;
	return (j);
}

static int	ft_cpy(char *l, char **mtx)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (l[i] && (!ft_in_str(" <>", l[i]) || ft_in_quotes(l, i, '\'', '\"')))
	{
		if (l[i] == '\'' && ft_is_quotes(l, i, '\'', '\"') == 1)
			j += 0;
		if (l[i] == '"' && ft_is_quotes(l, i, '"', '\'') == 1)
			j += 0;
		else
			j++;
		i++;
	}
	while (mtx[k])
		k++;
	mtx[k] = malloc(j + 1);
	if (mtx[k] == NULL)
		return (-1);
	ft_strlcpy_no_c(mtx[k], l, i + 1);
	return (i);
}

int	ft_create_str_parse(char **mtx, char **red, char *line)
{
	int	i;
	int	num;
	int	flag;

	i = 0;
	flag = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			num = 1;
		else if ((line[i] == '>' || line[i] == '<'))
			num = ft_red(line + i, red, &flag);
		else if (flag == 1)
		{
			flag = 0;
			num = ft_cpy(line + i, red);
		}
		else
			num = ft_cpy(line + i, mtx);
		if (num == -1)
			return (num);
		i += num;
	}
	return (1);
}
