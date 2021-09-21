/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 14:15:05 by loukeen           #+#    #+#             */
/*   Updated: 2021/09/21 13:43:17 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_megasort(t_node **stk)
{
	int		moves;
	t_node	*p;

	moves = 0;
	p = (*stk)->next;
	if (p->content > p->next->content && \
	(p->content < p->prev->content || p->next->content > p->prev->content))
		moves += ft_sab(stk, 0);
	if (p->content < p->next->content && p->content < p->prev->content)
	{
		if (p->next->content > p->prev->content)
			moves += ft_sab(stk, 0);
		else
			moves += ft_rab(stk, 0);
	}
	else if (p->content > p->next->content && p->content > p->prev->content)
		moves += ft_rrab(stk, 0);
	return (moves);
}

void	ft_quicksort(t_node **a)
{
	int		moves;
	t_node	**b;

	b = malloc(sizeof(t_node));
	*b = NULL;
	moves = 0;
	while (ft_lstsize(*a) > 3)
		moves += ft_pab(b, a, 1);
	moves += ft_megasort(a);
	while (ft_lstsize(*b) != 0)
	{
		ft_init_moves(b);
		if (ft_lstsize(*b) != 1)
			moves += ft_check_switch(b);
		ft_set_moves(a, b);
		moves += ft_chose_num(a, b);
	}
	moves += ft_find_head(a);
	free(b);
	ft_checker_top(a);
}
