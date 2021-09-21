/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 12:08:55 by lmarzano          #+#    #+#             */
/*   Updated: 2021/09/16 16:09:22 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_set_negative(t_node **a, int dmax)
{
	t_node	*p;

	if (!a || !*a)
		return (-1);
	p = (*a);
	while (p->dist != dmax)
	{
		p->dist = -1;
		p = p->next;
	}
	return (p->content);
}

int	ft_check_flag(t_node *p, int ref)
{
	if (!p)
		return (ref);
	if (p->dist != -1)
	{
		if (p->content >= ref)
			ref = p->content;
		else
			p->dist = -1;
	}
	return (ref);
}

void	ft_set_flags(t_node **a, int dmax)
{
	t_node	*p;
	t_node	*cycle;
	int		ref;

	if (!a)
		return ;
	ref = ft_set_negative(a, dmax);
	p = (*a);
	while (p->dist != dmax)
		p = p->next;
	p = p->next;
	while (p)
	{
		cycle = p;
		while (cycle)
		{
			if (p->dist > cycle->dist)
				if (p->content < ref)
					p->dist = -1;
			cycle = cycle->next;
		}
		ref = ft_check_flag(p, ref);
		p = p->next;
	}
}

int	ft_find_dmax(t_node **a)
{
	t_node	*p;
	t_node	*cycle;
	int		ref;

	if (!a || !*a)
		return (-1);
	p = (*a);
	while (p)
	{
		ref = p->content;
		ft_smaller(p, a);
		cycle = p;
		while (cycle->next != NULL)
		{
			if (cycle->content > ref)
			{
				p->dist++;
				ref = cycle->content;
			}
			cycle = cycle->next;
		}
		p = p->next;
	}
	return (ft_get_dmax(a));
}
