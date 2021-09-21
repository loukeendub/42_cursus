/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 16:10:00 by lmarzano          #+#    #+#             */
/*   Updated: 2021/09/16 16:10:02 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_dmax(t_node **a)
{
	t_node	*p;
	int		dmax;

	if (!a || !*a)
		return (-1);
	p = (*a);
	dmax = 0;
	while (p)
	{
		if (p->dist >= dmax)
			dmax = p->dist;
		p = p->next;
	}
	return (dmax);
}

void	ft_smaller(t_node *p, t_node **a)
{
	int		smaller;
	t_node	*cycle;

	if (!p || !a)
		return ;
	smaller = p->content;
	cycle = (*a);
	while (cycle != p)
	{
		if (cycle && (cycle->content < smaller))
		{
			p->dist++;
			smaller = cycle->content;
		}
		cycle = cycle->next;
	}
}
