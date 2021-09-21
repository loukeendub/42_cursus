/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 16:34:33 by lmarzano          #+#    #+#             */
/*   Updated: 2021/09/16 16:35:03 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_node **stack)
{
	t_node	*p;
	int		x;

	p = *stack;
	x = p->content;
	p->content = p->next->content;
	p->next->content = x;
}

int	ft_sab(t_node **head, int s)
{
	t_node	*stack;

	stack = *head;
	if (stack && stack->next)
		ft_swap(head);
	if (s != -1)
	{
		if (s == 0)
			write(1, "sa\n", 3);
		else if (s == 1)
			write(1, "sb\n", 3);
	}
	return (1);
}

int	ft_pab(t_node **head_to, t_node **head_from, int s)
{
	t_node	*tmp;
	int		res;

	res = 1;
	tmp = *head_from;
	(*head_from) = (*head_from)->next;
	ft_lstadd_front(head_to, tmp);
	if (s != -1)
	{
		if (s == 0)
			write(1, "pa\n", 3);
		else if (s == 1)
			write(1, "pb\n", 3);
	}
	return (res);
}	

int	ft_rab(t_node **head, int s)
{
	t_node	*change;

	if (!head)
		return (0);
	if (s == 0)
		write(1, "ra\n", 3);
	if (s == 1)
		write(1, "rb\n", 3);
	change = *head;
	if ((*head)->next != NULL)
	{
		(*head) = (*head)->next;
		(*head)->prev = NULL;
	}
	ft_lstadd_back(head, change);
	return (1);
}

int	ft_rrab(t_node **head, int s)
{
	t_node	*last;
	t_node	*p;

	if (!head)
		return (0);
	if (s == 0)
		write(1, "rra\n", 4);
	if (s == 1)
		write(1, "rrb\n", 4);
	p = ft_lstlast(head);
	last = p;
	p = p->prev;
	p->next = NULL;
	ft_lstadd_front(head, last);
	return (1);
}
