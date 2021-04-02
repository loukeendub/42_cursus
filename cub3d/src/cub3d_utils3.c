/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 12:05:43 by lmarzano          #+#    #+#             */
/*   Updated: 2021/04/02 12:48:35 by lmarzano         ###   ########.fr       */
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
			ft_itoa_core(line, &all->par->res_w);
		h++;
	}
	else if (h == 1)
	{
		while (ft_isdigit(**line))
			ft_itoa_core(line, &all->par->res_h);
		h++;
	}			
	else 
		return (-1);
	return (h);
}

int	ft_itoa2(char **line, t_all *all, int h)
{
	if (h == 0)
	{
		while (ft_isdigit((**line)))
			ft_itoa_core(line, &all->par->ceiling[0]);
		h++;
	}
	else if (h == 1)
	{
		while (ft_isdigit(**line))
			ft_itoa_core(line, &all->par->ceiling[1]);
		h++;
	}
	else if (h == 2)
	{
		while (ft_isdigit(**line))
			ft_itoa_core(line, &all->par->ceiling[2]);
		h++;
	}		
	else 
		return (-1);
	return (h);
}

int	ft_itoa3(char **line, t_all *all, int h)
{
	if (h == 0)
	{
		while (ft_isdigit((**line)))
			ft_itoa_core(line, &all->par->floor[0]);
		h++;
	}
	else if (h == 1)
	{
		while (ft_isdigit(**line))
			ft_itoa_core(line, &all->par->floor[1]);
		h++;
	}
	else if (h == 2)
	{
		while (ft_isdigit(**line))
			ft_itoa_core(line, &all->par->floor[2]);
		h++;
	}		
	else 
		return (-1);
	return (h);
}
