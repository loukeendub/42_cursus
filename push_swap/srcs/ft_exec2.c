/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 16:28:04 by lmarzano          #+#    #+#             */
/*   Updated: 2021/09/16 16:55:53 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

int	ft_exec_rrr(t_node **a, t_node **b, int count)
{
	int		moves;

	if (count < 0)
		return (0);
	moves = count;
	while (count != 0)
	{
		ft_rrr(a, b);
		count--;
	}
	return (moves);
}

int	ft_exec_rr(t_node **a, t_node **b, int count)
{
	int	moves;

	if (count < 0)
		return (0);
	moves = count;
	while (count != 0)
	{
		ft_rr(a, b);
		count--;
	}
	return (moves);
}

int	ft_exec_rra(t_node **a, int count)
{
	int	moves;

	if (count < 0)
		return (0);
	moves = count;
	while (count != 0)
	{
		ft_rrab(a, 0);
		count--;
	}
	return (moves);
}

int	ft_exec_ra(t_node **a, int count)
{
	int	moves;

	if (count < 0)
		return (0);
	moves = count;
	while (count != 0)
	{
		ft_rab(a, 0);
		count--;
	}
	return (moves);
}

int	ft_exec_rrb(t_node **b, int count)
{
	int	moves;

	if (count < 0)
		return (0);
	moves = count;
	while (count != 0)
	{
		ft_rrab(b, 1);
		count--;
	}
	return (moves);
}
