/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 16:29:03 by lmarzano          #+#    #+#             */
/*   Updated: 2021/09/16 16:55:54 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_exec_rb(t_node **b, int count)
{
	int	moves;

	if (count < 0)
		return (0);
	moves = count;
	while (count-- != 0)
		ft_rab(b, 1);
	return (moves);
}

int	ft_exec_moves(t_node **a, t_node **b, int move)
{
	t_node	*p;
	int		moves;

	if (!a || !b)
		return (0);
	p = (*b);
	moves = 0;
	while (p && p->content != move)
		if (p->next != NULL)
			p = p->next;
	if (p->rrr != -1)
		moves += ft_exec_rrr(a, b, p->rrr);
	if (p->rr != -1)
		moves += ft_exec_rr(a, b, p->rr);
	if (p->ra != -1)
		moves += ft_exec_ra(a, p->ra);
	if (p->rb != -1)
		moves += ft_exec_rb(b, p->rb);
	if (p->rra != -1)
		moves += ft_exec_rra(a, p->rra);
	if (p->rrb != -1)
		moves += ft_exec_rrb(b, p->rrb);
	moves += ft_pab(a, b, 0);
	return (moves);
}
