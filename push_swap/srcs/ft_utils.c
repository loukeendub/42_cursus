/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:45:14 by lmarzano          #+#    #+#             */
/*   Updated: 2021/09/21 11:50:28 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_half(int size)
{
	if (!size)
		return (0);
	if (size % 2 != 0)
		return ((size + 1) / 2);
	else
		return (size / 2);
}

void	ft_init_moves(t_node **stack)
{
	t_node	*p;

	if (!stack)
		return ;
	p = (*stack);
	while (p)
	{
		p->dist = 0;
		p->rrr = -1;
		p->rra = -1;
		p->rrb = -1;
		p->rr = -1;
		p->ra = -1;
		p->rb = -1;
		p = p->next;
	}
}

void	ft_init_flags(t_node **a)
{
	t_node	*p;

	p = *a;
	while (p)
	{
		p->dist = 0;
		p = p->next;
	}
}

int	ft_checker(t_node **a)
{
	t_node	*p;

	if (!a)
		return (0);
	p = (*a);
	while (p)
	{
		if (p->next != NULL)
			if (p->content > p->next->content)
				return (0);
		p = p->next;
	}
	return (1);
}

int	ft_top_or_btm(t_node **a, int next)
{
	t_node	*p;
	int		i;
	int		check;

	if (!a || !*a)
		return (-1);
	p = (*a);
	i = 0;
	check = 0;
	while ((p->next != NULL) && (p->content != next))
	{
		if (p->dist != -1)
			check++;
		p = p->next;
	}
	if (check > ft_half(ft_lstsize(*a)))
		return (1);
	return (0);
}
