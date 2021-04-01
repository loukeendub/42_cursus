/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 12:05:43 by lmarzano          #+#    #+#             */
/*   Updated: 2021/04/01 14:55:47 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t i;

	i = 0;
	while (*(dst + i) && i < dstsize)
		++i;
	while (*src && i + 1 < dstsize)
	{
		*(dst + i) = *src;
		++src;
		++i;
	}
	if (i < dstsize)
		*(dst + i) = 0;
	while (*src++)
		++i;
	return (i);
}

int	ft_itoa(char **line, t_all *all, int h)
{
	if (h == 0)
	{
		while (ft_isdigit((**line)))
		{
			if (all->par->res_w == -1)
				all->par->res_w = 0;
			all->par->res_w = all->par->res_w * 10 + ((int)(**line) - 48);
			(*line)++;
		}
		h++;
	}
	else if (h == 1)
	{
		while (ft_isdigit(**line))
		{
			if (all->par->res_h == -1)
				all->par->res_h = 0;
			all->par->res_h = all->par->res_h * 10 + ((int)(**line) - 48);
			(*line)++;
		}
		h++;
	}			
	else 
		return (-1);
	return (h);
}

int	ft_itoa2(char **line, t_all *all, int h)// 33 lines
{
	if (h == 0)
	{
		while (ft_isdigit((**line)))
		{
			if (all->par->ceiling[0] == -1)
				all->par->ceiling[0] = 0;
			all->par->ceiling[0] = all->par->ceiling[0] * 10 + ((int)(**line) - 48);
			(*line)++;
		}
		h++;
	}
	else if (h == 1)
	{
		while (ft_isdigit(**line))
		{
			if (all->par->ceiling[1] == -1)
				all->par->ceiling[1] = 0;
			all->par->ceiling[1] = all->par->ceiling[1] * 10 + ((int)(**line) - 48);
			(*line)++;
		}
		h++;
	}
	else if (h == 2)
	{
		while (ft_isdigit(**line))
		{
			if (all->par->ceiling[2] == -1)
				all->par->ceiling[2] = 0;
			all->par->ceiling[2] = all->par->ceiling[2] * 10 + ((int)(**line) - 48);
			(*line)++;
		}
		h++;
	}		
	else 
		return (-1);
	return (h);
}

int	ft_itoa3(char **line, t_all *all, int h)// 33 lines
{
	if (h == 0)
	{
		while (ft_isdigit((**line)))
		{
			if (all->par->floor[0] == -1)
				all->par->floor[0] = 0;
			all->par->floor[0] = all->par->floor[0] * 10 + ((int)(**line) - 48);
			(*line)++;
		}
		h++;
	}
	else if (h == 1)
	{
		while (ft_isdigit(**line))
		{
			if (all->par->floor[1] == -1)
				all->par->floor[1] = 0;
			all->par->floor[1] = all->par->floor[1] * 10 + ((int)(**line) - 48);
			(*line)++;
		}
		h++;
	}
	else if (h == 2)
	{
		while (ft_isdigit(**line))
		{
			if (all->par->floor[2] == -1)
				all->par->floor[2] = 0;
			all->par->floor[2] = all->par->floor[2] * 10 + ((int)(**line) - 48);
			(*line)++;
		}
		h++;
	}		
	else 
		return (-1);
	return (h);
}

int	check_val(t_all *all)
{
	int i;

	i = 0;
	if (all->chr->r != 1 || all->chr->no != 1 || all->chr->so != 1 || all->chr->we != 1\
	|| all->chr->ea != 1 || all->chr->s != 1 || all->chr->f != 1 || all->chr->c != 1 || all->chr->mp != 1) 
	{
		//puts("bowser");
		return (0);
	}
	while (i < 3)
	{
		if (all->par->ceiling[i] == -1)
		{
			//puts("mario");
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < 3)
	{
		if (all->par->floor[i] == -1)
		{
			//puts("luigi");
			return (0);
		}
		i++;
	}
	return (1);
}