/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:56:43 by lmarzano          #+#    #+#             */
/*   Updated: 2021/09/16 15:56:45 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_min(t_node **a, int min_a)
{
	t_node	*p;
	int		j;

	p = (*a);
	j = 0;
	while (p->content != min_a)
	{
		j++;
		p = p->next;
	}
	return (j);
}

int	ft_min(t_node **a, t_node **b)
{
	int		min_a;
	t_node	*p;
	t_node	*ptr;
	int		j;

	j = 0;
	p = (*a);
	min_a = p->content;
	while (p)
	{
		if (p->content < min_a)
			min_a = p->content;
		p = p->next;
	}
	j = ft_count_min(a, min_a);
	if (j == ft_lstsize(*a) || j == 0)
	{
		ptr = (*b);
		p = (*a);
		if (ptr->content < p->content)
			return (j = 0);
	}
	return (j);
}

int	ft_count_max(t_node **a, t_node **b, int max_a)
{
	t_node	*p;
	t_node	*ptr;
	int		j;

	p = (*a);
	ptr = (*b);
	j = 1;
	while (p->content != max_a)
	{
		j++;
		p = p->next;
	}
	return (j);
}

int	ft_max(t_node **a, t_node **b)
{
	int		max_a;
	t_node	*p;
	t_node	*ptr;
	int		j;

	p = (*a);
	max_a = p->content;
	j = 0;
	while (p)
	{
		if (p->content > max_a)
			max_a = p->content;
		p = p->next;
	}
	if (j == ft_lstsize(*a))
	{
		p = *a;
		ptr = *b;
		if (((ptr->content < p->content) && (p->content < 0))
			|| ((ptr->content > p->content) && (p->content > 0)))
			return (j = 2);
	}
	j = ft_count_max(a, b, max_a);
	return (j);
}
