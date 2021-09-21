/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:51:05 by lmarzano          #+#    #+#             */
/*   Updated: 2021/09/21 11:50:28 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_save_low_half(t_node **b, int i, int j)
{
	t_node	*p;

	p = ft_get_p(b, i);
	if (i == 0)
		p->ra = j;
	if (j == 0)
		p->rb = i;
	else if (j > i && i != 0)
	{
		p->rr = i;
		p->ra = j - i;
	}
	else if (j < i && j != 0)
	{
		p->rr = j;
		p->rb = i - j;
	}
}

void	ft_save_upper_half(t_node **a, t_node **b, int i, int j)
{
	t_node	*p;

	p = ft_get_p(b, i);
	p->rrb = (ft_lstsize(*b) - i);
	p->rra = (ft_lstsize(*a) - j);
	if (p->rra > p->rrb)
	{
		p->rrr = p->rrb;
		p->rra -= p->rrr;
		p->rrb = -1;
	}
	else if (p->rra < p->rrb)
	{
		p->rrr = p->rra;
		p->rrb -= p->rrr;
		p->rra = -1;
	}
	else if (p->rra == p->rrb)
	{
		p->rrr = p->rra;
		p->rra = -1;
		p->rrb = -1;
	}
}

void	ft_save_mixed_half(t_node **a, t_node **b, int i, int j)
{
	t_node	*p;

	p = ft_get_p(b, i);
	if ((i < ft_half(ft_lstsize(*b))) && (j >= ft_half(ft_lstsize(*a))))
	{
		if (j != ft_lstsize(*a))
			p->rra = ft_lstsize(*a) - j;
		p->rb = i;
	}
	if ((j < ft_half(ft_lstsize(*a)) && (i >= ft_half(ft_lstsize(*b)))))
	{
		p->rrb = ft_lstsize(*b) - i;
		p->ra = j;
	}
}

void	ft_save_same(t_node **a, t_node **b, int i, int j)
{
	t_node	*p;

	p = ft_get_p(b, i);
	if ((i < ft_half(ft_lstsize(*b))) && (j < ft_half(ft_lstsize(*a))))
		p->rr = i;
	else if ((i >= ft_half(ft_lstsize(*b))) && (j >= ft_half(ft_lstsize(*a))))
	{
		if ((ft_lstsize(*a) - j) > (ft_lstsize(*b) - i))
		{
			p->rrr = (ft_lstsize(*b) - i);
			p->rra = (ft_lstsize(*a) - j) - p->rrr;
			if (p->rra == 0)
				p->rra = 1;
		}
		else if ((ft_lstsize(*a) - j) < (ft_lstsize(*b) - i))
		{
			p->rrr = (ft_lstsize(*a) - j);
			p->rrb = (ft_lstsize(*b) - i) - p->rrr;
		}
		else
			p->rrr = ft_lstsize(*a) - j;
	}
	else
		ft_save_mixed_half(a, b, i, j);
}

void	ft_save_moves(t_node **a, t_node **b, int i, int j)
{
	if (i == j && i != 0 && j != 0)
		ft_save_same(a, b, i, j);
	else if ((i < ft_half(ft_lstsize(*b)))
		&& (j < ft_half(ft_lstsize(*a))))
		ft_save_low_half(b, i, j);
	else if ((i >= ft_half(ft_lstsize(*b)))
		&& (j >= ft_half(ft_lstsize(*a))))
		ft_save_upper_half(a, b, i, j);
	else
		ft_save_mixed_half(a, b, i, j);
}
