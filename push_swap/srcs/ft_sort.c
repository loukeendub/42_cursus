/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:18:38 by lmarzano          #+#    #+#             */
/*   Updated: 2021/09/16 15:58:50 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_info(t_node **a, t_node *b, int large, int sent)
{
	t_node	*stack_a;
	int		j;

	j = 0;
	stack_a = *a;
	while (stack_a)
	{
		if (b->content < stack_a->content)
		{
			j++;
			if (stack_a->content < large)
				large = stack_a->content;
		}
		stack_a = stack_a->next;
	}
	if (sent == 0)
		return (j);
	if (sent == 1)
		return (large);
	return (0);
}

void	ft_set_moves(t_node **a, t_node **b)
{
	int		i;
	int		j;
	int		large;
	t_node	*stack_b;

	i = 0;
	stack_b = (*b);
	while (stack_b && i <= ft_lstsize(*b))
	{
		large = 2147483647;
		j = ft_get_info(a, stack_b, large, 0);
		large = ft_get_info(a, stack_b, large, 1);
		j = ft_get_j(a, b, large, j);
		stack_b->dist = ft_count_moves(i, j, a, b);
		ft_save_moves(a, b, i, j);
		i++;
		stack_b = stack_b->next;
	}
}

int	ft_chose_num(t_node **a, t_node **b)
{
	t_node	*p;
	int		move;
	int		min;
	int		moves;

	if (!b || !a)
		return (0);
	p = (*b);
	moves = 0;
	min = p->dist;
	move = p->content;
	while (p)
	{
		if (p->dist < min)
		{
			min = p->dist;
			move = p->content;
		}
		p = p->next;
	}
	moves = ft_exec_moves(a, b, move);
	return (moves);
}

int	ft_checker_top(t_node **a)
{
	t_node	*p;

	p = (*a);
	while (p)
	{
		if (p->next != NULL)
		{
			if (p->content > p->next->content)
				return (0);
		}
		p = p->next;
	}
	return (-1);
}

void	ft_commands(t_node **a)
{
	t_node	**b;
	int		dmax;
	int		moves;

	b = malloc(sizeof(t_node));
	*b = NULL;
	moves = 0;
	moves += ft_check_rotation(a);
	if (!(ft_checker_top(a)))
	{
		dmax = ft_find_dmax(a);
		ft_set_flags(a, dmax);
		moves += ft_push(a, b, dmax);
		while (ft_lstsize(*b) != 0)
		{
			ft_init_moves(b);
			if (ft_lstsize(*b) != 1)
				moves += ft_check_switch(b);
			ft_set_moves(a, b);
			moves += ft_chose_num(a, b);
		}
		moves += ft_find_head(a);
	}
	free(b);
	ft_checker_top(a);
}
