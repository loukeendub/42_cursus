/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dollar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 17:59:40 by lmarzano          #+#    #+#             */
/*   Updated: 2021/09/15 18:00:02 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_len_dollar_utils(char *line, t_list *var, int *tot)
{
	char	*tmp;
	int		len;

	len = ft_find_next_str(line + 1, " \'\"<>$");
	tmp = ft_substr(line, 1, len);
	if (tmp == NULL)
		return (-1);
	*tot += ft_strlen(ft_find_env(var, tmp, len)) - 1;
	free(tmp);
	return (len);
}

static int	ft_len_dollar(char *line, t_list *var)
{
	int		flag;
	int		i;
	int		tot;
	int		num;

	i = 0;
	tot = 0;
	flag = 1;
	while (line && line[i])
	{
		if (line[i] == '\'' && ft_in_quotes(line, i + 1, '\'', '\"') == 1)
			flag *= -1;
		else if (line[i] == '$' && flag == 1)
		{
			num = ft_len_dollar_utils(line + i, var, &tot);
			if (num == -1)
				return (-1);
			i += num;
		}
		tot++;
		i++;
	}
	return (tot);
}

static int	ft_change_dollar(char *dst, char *src, int src_pos, t_list *var)
{
	int		len;
	char	*content;
	char	*tmp;

	if (ft_between_c(src, src_pos, '"'))
		len = ft_find_next_str(src + src_pos + 1, " \'\"<>$");
	else
		len = ft_find_next_str(src + src_pos + 1, " \'<>$");
	tmp = malloc(len + 1);
	if (tmp == NULL)
		return (-1);
	ft_strlcpy(tmp, src + src_pos + 1, len + 1);
	content = ft_find_env(var, tmp, len);
	ft_memcpy(dst, content, ft_strlen(content));
	free(tmp);
	return (ft_strlen(content));
}

static char	*ft_dollar_manager(char *line, t_list *var)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = malloc(ft_len_dollar(line, var) + 1);
	if (tmp == NULL)
		return (NULL);
	while (line && line[i])
	{
		if (line[i] == '$' && ft_in_quotes(line, i, '\'', '\"') != 1)
		{
			j += ft_change_dollar(tmp + j, line, i, var);
			if (ft_between_c(line, i, '\"'))
				i += ft_find_next_str(line + i + 1, " \'\"<>$") + 1;
			else
				i += ft_find_next_str(line + i + 1, " \'<>$") + 1;
		}
		else
			tmp[j++] = line[i++];
	}
	tmp[j] = 0;
	return (tmp);
}

char	*ft_expand(char *line, t_list *var)
{
	char	*tmp;

	tmp = line;
	if (line)
		line = ft_dollar_manager(line, var);
	free (tmp);
	return (line);
}
