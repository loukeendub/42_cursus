/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 17:59:55 by lmarzano          #+#    #+#             */
/*   Updated: 2021/09/15 18:00:02 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_redlen_parse(char *line)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (line[i])
	{
		if (ft_in_str("<>", line[i]) && line[i + 1] != line[i])
		{
			if (!ft_in_quotes(line, i, '\'', '"'))
				len++;
		}
		i++;
	}
	return (len * 2);
}

static int	ft_matlen_parse(char *line)
{
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	while (line[i])
	{
		if (line[i] == '"' || line[i] == '\'')
			i += ft_find_next_c(line, i, line[i]);
		else if (ft_in_str("<>", line[i]))
		{
			if (i != 0 && (line[i - 1] != line[i]))
				len++;
			if (line[i + 1] != line[i] && line[i + 1] != ' ')
				len++;
		}
		else if (line[i] == ' ' && !ft_in_str("<> ", line[i + 1]))
			len++;
		i++;
	}
	if (i != 0 && !ft_in_str("<> ", line[i - 1]))
		return (len + 1);
	return (len);
}

static int	ft_parse_lst(char **line, t_parse *parse)
{
	int		len;
	int		r_len;

	len = ft_matlen_parse(*line);
	r_len = ft_redlen_parse(*line);
	parse->input = (char **)ft_calloc(sizeof(char *), (len - r_len + 1));
	if (parse->input == NULL)
		return (-1);
	parse->output = (char **)ft_calloc(sizeof(char *), (r_len + 1));
	if (parse->output == NULL)
	{
		free(parse->input);
		return (-1);
	}
	if (ft_create_str_parse(parse->input, parse->output, *line) == -1)
	{
		ft_free_matrix(parse->input);
		ft_free_matrix(parse->output);
		return (-1);
	}
	return (1);
}

t_parse	*ft_parsing(char *line)
{
	t_parse	*pars;

	if (line == NULL)
		return (NULL);
	if (ft_parse_check(line) == -1)
		return (NULL);
	if (ft_check_command(line) == -1)
		return (NULL);
	pars = (t_parse *)malloc(sizeof(t_parse));
	if (pars == NULL)
		return (NULL);
	if (ft_parse_lst(&line, pars) == -1)
		return (ft_free_null(pars));
	pars->command = ft_m_strlcpy(pars->input[0], ft_strlen(pars->input[0]) + 1);
	if (pars->command == NULL)
	{
		ft_free_matrix(pars->input);
		ft_free_matrix(pars->output);
		return (NULL);
	}
	return (pars);
}
