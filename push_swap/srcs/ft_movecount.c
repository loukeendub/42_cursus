/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movecount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 16:05:39 by lmarzano          #+#    #+#             */
/*   Updated: 2021/09/21 11:50:25 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_same(int i, int j, t_node **a, t_node **b)
{
	int	res;

	res = 0;
	if (i == 0 && j == 0)
		res = 0;
	else if ((i < ft_half(ft_lstsize(*b))) && \
	(j < ft_half(ft_lstsize(*a))))
		res = i;
	else if ((i >= ft_half(ft_lstsize(*b))) && \
	(j >= ft_half(ft_lstsize(*a))))
	{
		if ((ft_lstsize(*a) - j) > (ft_lstsize(*b) - i))
			res = ft_lstsize(*a) - j;
		if ((ft_lstsize(*a) - j) < (ft_lstsize(*b) - i))
			res = ft_lstsize(*b) - i;
		else
			res = (ft_lstsize(*b) - i);
	}
	else if ((i < ft_half(ft_lstsize(*b)))
		&& (j >= (ft_half(ft_lstsize(*a)))))
		res = i + ft_lstsize(*a) - j;
	else if ((i >= ft_half(ft_lstsize(*b))) && \
	(j < ft_half(ft_lstsize(*a))))
		res = ft_lstsize(*b) - i + j;
	return (res);
}

int	ft_count_low_half(int i, int j)
{
	int	res;

	res = 0;
	if (j == 0 && i != 0)
		res = i;
	if (i == 0)
		res = j;
	if (j > i && i != 0)
		res = i + (j - i);
	if (j < i && j != 0)
		res = j + (i - j);
	return (res);
}

int	ft_count_upper_half(int i, int j, t_node **a, t_node **b)
{
	int	res;

	if (!a || !b)
		return (-1);
	res = 0;
	if ((ft_lstsize(*a) - j) > (ft_lstsize(*b) - i))
		res = ((ft_lstsize(*a) - j) - (ft_lstsize(*b) - i)
				+ ((ft_lstsize(*a) - j)) + (ft_lstsize(*b) - i));
	if ((ft_lstsize(*a) - j) == (ft_lstsize(*b) - i))
		res = ((ft_lstsize(*b) - i) - (ft_lstsize(*a) - j))
			+ (ft_lstsize(*b) - i) + (ft_lstsize(*a) - j);
	if ((ft_lstsize(*a) - j) < (ft_lstsize(*b) - i))
		res = ((ft_lstsize(*a) - j) + (ft_lstsize(*b) - i));
	if (res == 0)
		res = 1;
	return (res);
}

int	ft_count_moves(int i, int j, t_node **a, t_node **b)
{
	int	res;

	res = 0;
	if (i == j)
		res = ft_count_same(i, j, a, b);
	else if ((i < ft_half(ft_lstsize(*b))) && (j < ft_half(ft_lstsize(*a))))
		res = ft_count_low_half(i, j);
	else if ((i >= ft_half(ft_lstsize(*b))) && (j >= ft_half(ft_lstsize(*a))))
		res = ft_count_upper_half(i, j, a, b);
	else if ((i < ft_half(ft_lstsize(*b))) && (j >= ft_half(ft_lstsize(*a))))
	{
		if (j == ft_lstsize(*a))
			res = 1;
		else
			res = (ft_lstsize(*a) - j) + i;
	}
	else if ((j < ft_half(ft_lstsize(*a)) && (i >= ft_half(ft_lstsize(*b)))))
	{
		if (j == 0)
			j += 1;
		res = (ft_lstsize(*b) - i) + (j - 1);
	}
	res += 1;
	return (res);
}
