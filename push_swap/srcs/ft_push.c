/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loukeen <loukeen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:59:58 by lmarzano          #+#    #+#             */
/*   Updated: 2021/09/18 14:32:37 by loukeen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_final_push(t_node **a, t_node **b, int stop)
{
	t_node	*p;
	int		moves;

	if (!a || !b)
		return (-1);
	p = (*a);
	moves = 0;
	if (p->dist == stop)
		return (moves += ft_rab(a, 0));
	while ((p) && (p->dist != stop))
	{
		if (p->dist == -1)
			moves += ft_pab(b, a, 1);
		else
			moves += ft_rab(a, 0);
		p = (*a);
	}
	return (moves);
}

int	ft_push_before_dmax(t_node **a, t_node **b, int check, int stop)
{
	t_node	*p;
	int		moves;
	int		ref;

	if (!a || !b)
		return (-1);
	p = (*a);
	moves = 0;
	ref = -2147483648;
	while (ref == -2147483648 && p->content != check)
	{
		if ((p->content > ref) && (p->content < check))
		{
			ref = p->content;
			moves += ft_rab(a, 0);
		}
		else
			moves += ft_pab(b, a, 1);
		p = (*a);
	}
	moves += ft_final_push(a, b, stop);
	return (moves);
}

int	ft_push_after_dmax(t_node **a, t_node **b, int last)
{
	t_node	*p;
	int		moves;

	if (!a || !b)
		return (-1);
	moves = 0;
	p = (*a);
	while (p)
	{
		if (p->content == last)
		{
			moves += ft_pab(b, a, 1);
			return (moves);
		}
		if (p->dist == -1)
			moves += ft_pab(b, a, 1);
		else
			moves += ft_rab(a, 0);
		p = (*a);
	}
	return (moves);
}

int	ft_push(t_node **a, t_node **b, int dmax)
{
	t_node	*p;
	int		moves;
	int		last;
	int		ref;

	if (!a || !b)
		return (-1);
	moves = 0;
	last = 0;
	ref = 0;
	p = (*a);
	while (p && p->dist != dmax)
		p = p->next;
	if (p)
		ref = p->content;
	p = ft_lstlast(a);
	if (p)
		last = p->content;
	moves += ft_push_before_dmax(a, b, ref, dmax);
	moves += ft_push_after_dmax(a, b, last);
	return (moves);
}
