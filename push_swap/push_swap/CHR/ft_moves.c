/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 10:47:22 by lmarzano          #+#    #+#             */
/*   Updated: 2021/05/31 11:12:34 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap(t_node **n)
{
	t_node	*c;

	c = 0;
	if (!(*n))
		return ;
	c = (*n)->next;
	(*n)->next = (*n)->next->next;
	c->next = (*n);
	(*n) = c;
}

void	ft_push_a(t_node **a, t_node **b)
{
	t_node	*c;

	c = 0;
	if (!(*b))
		return ;
	c = (*b)->next;
	(*b)->next = NULL;
	ft_lstadd_front(a, *b);
	*b = c;
}

void	ft_push_b(t_node **a, t_node **b)
{
	t_node	*c;

	c = 0;
	if (!(*a))
		return ;
	c = (*a)->next;
	(*a)->next = NULL;
	ft_lstadd_front(b, *a);
	*a = c;
}

void	ft_rot(t_node **n)
{
	t_node	*c;

	c = 0;
	if (!(*n) || !(*n)->next)
		return ;
	c = (*n);
	c = ft_lstlast(c);
	c->next = (*n);
	(*n) = (*n)->next;
	c->next->next = NULL;
}

void	ft_rev(t_node **n)
{
	t_node	*c;

	c = 0;
	if (!(*n) || !(*n)->next)
		return ;
	c = (*n);
	while (c->next->next)
		c = c->next;
	c->next->next = (*n);
	(*n) = c->next;
	c->next = NULL;
}
