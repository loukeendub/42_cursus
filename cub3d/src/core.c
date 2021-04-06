/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 12:45:22 by lmarzano          #+#    #+#             */
/*   Updated: 2021/04/06 11:44:13 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_type_core(char **line, t_all *all, int *chr, char *f)
{
	if (*f == 'F' || *f == 'C')
	{
		if (ft_parse_digit2(line, all) == -1)
			return (-1);
	}
	else
	{
		if (ft_parse_digit(line, all) == -1 && chr == 0)
				return (-1);
	}
	chr++;
	return (1);
}

int	ft_wall_core(char **line, char **wall, int *chr)
{
	*wall = ft_text_store(line);
	if (*wall == 0)
		return (-1);
	*chr += 1;
	return (1);
}

void	ft_itoa_core(char **line, int *all)
{
	while (ft_isdigit((**line)))
	{
		if (*all == -1)
			*all = 0;
		*all = *all * 10 + ((**line) - 48);
		(*line)++;
	}
}

int	ft_split_core(char *s, char **arr, char c, t_all *all)
{
	size_t	len;
	int		i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = ft_strclen(s, c);
			arr[i] = malloc(len + 1);
			if (!arr[i])
				return (0);
			ft_strlcpy(arr[i], s, len + 1);
			s += len;
			i++;
			all->par->map_h++;
		}
		else
			s++;
	}
	return (i); 
}

int	ft_parse_line_core(char *line, int i, int ret, t_all *all)
{
	while (i-- && *line)
		line++;
	ret = ft_check_type(&line, all);
	if (ret == -1)
		return (-1);
	else if (ret == 1)
		return (1);
	else
		return (-1);
}
