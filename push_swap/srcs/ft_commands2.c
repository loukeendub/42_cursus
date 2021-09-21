/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 16:33:55 by lmarzano          #+#    #+#             */
/*   Updated: 2021/09/16 16:33:57 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ss(t_node **stack_a, t_node **stack_b)
{
	ft_sab(stack_a, -1);
	ft_sab(stack_b, -1);
	write(1, "ss\n", 3);
	return (0);
}

int	ft_rr(t_node **stack1, t_node **stack2)
{
	ft_rab(stack1, -1);
	ft_rab(stack2, -1);
	write(1, "rr\n", 3);
	return (0);
}

int	ft_rrr(t_node **stack1, t_node **stack2)
{
	ft_rrab(stack1, -1);
	ft_rrab(stack2, -1);
	write(1, "rrr\n", 4);
	return (0);
}
