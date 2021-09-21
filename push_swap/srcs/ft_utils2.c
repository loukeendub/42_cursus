/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:49:38 by lmarzano          #+#    #+#             */
/*   Updated: 2021/09/16 15:50:31 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_switch(t_node **a)
{
	t_node	*p;
	int		moves;

	p = (*a);
	moves = 0;
	if (((p->content > p->next->content)
			&& (p->content < 0)))
		moves += ft_sab(a, 1);
	return (moves);
}

t_node	*ft_get_p(t_node **stack, int stop)
{
	t_node	*p;

	p = *stack;
	while (stop-- != 0)
		p = p->next;
	return (p);
}

int	ft_get_j(t_node **a, t_node **b, int large, int j)
{
	if (j == 0)
		j = ft_max(a, b);
	else if (j == ft_lstsize(*a))
		j = ft_min(a, b);
	else
		j = ft_find_position(a, large);
	return (j);
}
