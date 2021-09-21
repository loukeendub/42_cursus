/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 16:10:12 by lmarzano          #+#    #+#             */
/*   Updated: 2021/09/16 16:27:16 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_position(t_node **a, int num)
{
	t_node	*p;
	int		j;

	p = *a;
	j = 0;
	if (p != NULL)
	{
		while (p->content != num)
		{
			j++;
			p = p->next;
		}
	}
	if (j == 0 || j == ft_lstsize(*a))
	{
		p = *a;
		if (p->content < num)
			j = 1;
	}
	return (j);
}

int	ft_find_int_min(t_node **a)
{
	t_node	*p;
	int		res;

	p = (*a);
	res = p->content;
	while (p)
	{
		if (p->content < res)
			res = p->content;
		p = p->next;
	}
	return (res);
}

int	ft_find_int_max(t_node **a)
{
	t_node	*p;
	int		res;

	p = (*a);
	res = p->content;
	while (p)
	{
		if (p->content > res)
			res = p->content;
		p = p->next;
	}
	return (res);
}
