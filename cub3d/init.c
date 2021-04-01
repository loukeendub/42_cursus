/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:36:08 by lmarzano          #+#    #+#             */
/*   Updated: 2021/04/01 10:25:52 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_init(t_all *all)
{
	all->chr = malloc(sizeof (t_check));
	all->chr->r = 0;
	all->chr->no = 0;
	all->chr->so = 0;
	all->chr->we = 0;
	all->chr->ea = 0;
	all->chr->s = 0;
	all->chr->f = 0;
	all->chr->c = 0;
	all->chr->mp = 0;	
}

void	ft_ref_init(t_all *all)
{
	all->par->reference[0] = ' ';
	all->par->reference[1] = '0';
	all->par->reference[2] = '1';
	all->par->reference[3] = '2';
	all->par->reference[4] = 'N';
	all->par->reference[5] = 'S';
	all->par->reference[6] = 'E';
	all->par->reference[7] = 'W';
	all->par->map_h = -1;
	all->par->spawn = 0;
	all->par->f = 'N';
}

void	ft_tx_init(t_all *all)
{
	all->par->wall[0] = 0;
	all->par->wall[1] = 0;
	all->par->wall[2] = 0;
	all->par->wall[3] = 0;
	all->par->sfc[0] = 0;
	all->par->sfc[1] = 0;
	all->par->sfc[2] = 0;
}

void	ft_struct_init(t_all *all)
{
	all->par = malloc(sizeof (t_parse));
	all->par->res_w = -1;
	all->par->res_h = -1;
	all->par->sky[0] = -1;
	all->par->sky[1] = -1;
	all->par->sky[2] = -1;
	all->par->floor[0] = -1;
	all->par->floor[1] = -1;
	all->par->floor[2] = -1;
	all->par->ceiling[0] = -1;
	all->par->ceiling[1] = -1;
	all->par->ceiling[2] = -1;
	all->par->sprite = 0;
	ft_tx_init(all);
	ft_ref_init(all);
	ft_check_init(all);
}

void	ft_str_all_init(t_all *all)
{
	all->par = 0;
	all->chr = 0;
	ft_struct_init(all);
}