/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_head_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 16:07:05 by lmarzano          #+#    #+#             */
/*   Updated: 2021/09/21 11:50:28 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_move_head(t_node **a, int i)
{
	int		moves;

	if (!a)
		return (-1);
	moves = 0;
	if (i >= ft_half(ft_lstsize(*a)))
	{
		moves = ft_lstsize(*a) - i;
		ft_exec_rra(a, moves);
	}
	else if (i < ft_half(ft_lstsize(*a)))
	{
		moves = i;
		ft_exec_ra(a, moves);
	}
	return (moves);
}

int	ft_sort_head(t_node **a, int head)
{
	int		i;
	t_node	*p;
	int		moves;

	p = (*a);
	i = 0;
	moves = 0;
	while (p->content != head)
	{
		i++;
		p = p->next;
	}
	moves = ft_move_head(a, i);
	return (moves);
}

int	ft_find_head(t_node **a)
{
	t_node	*p;
	int		head;
	int		moves;

	p = (*a);
	moves = 0;
	head = p->content;
	while (p)
	{
		if (p->content < head)
			head = p->content;
		p = p->next;
	}
	moves = ft_sort_head(a, head);
	return (moves);
}
