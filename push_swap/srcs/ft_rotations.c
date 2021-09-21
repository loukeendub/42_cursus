/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:54:22 by lmarzano          #+#    #+#             */
/*   Updated: 2021/09/16 15:54:23 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_rotation4(t_node **a)
{
	t_node	*p;
	int		moves;

	moves = 0;
	p = *a;
	if (p->content > p->next->content
		&& p->next->content < p->next->next->content)
	{
		if (p->content > p->next->next->content)
		{
			moves += ft_sab(a, 0);
			moves += ft_rab(a, 0);
			moves += ft_sab(a, 0);
		}
		else
			moves += ft_sab(a, 0);
	}
	return (moves);
}

int	ft_check_rotation3(t_node **a)
{
	int		moves;
	t_node	*p;
	int		last;

	moves = 0;
	p = (*a);
	if (p->content < p->next->content)
	{
		moves += ft_sab(a, 0);
		p = ft_lstlast(a);
		last = p->content;
		p = *a;
		if (p->content > last)
		{
			moves += ft_rrab(a, 0);
			moves += ft_sab(a, 0);
			moves += ft_rab(a, 0);
			p = (*a);
			moves += ft_check_rotation4(a);
		}
	}
	return (moves);
}

int	ft_check_rotation2(t_node **a)
{
	t_node	*p;
	int		moves;
	int		last;

	moves = 0;
	p = ft_lstlast(a);
	last = p->content;
	p = *a;
	if (((p->content < p->next->content)
			&& (last < p->next->content)
			&& (p->next->content < p->next->next->content))
		|| ((p->content < last)
			&& (p->content > p->next->content)))
	{
		moves += ft_rrab(a, 0);
		moves += ft_sab(a, 0);
	}
	else if ((p->content < p->next->content) && (p->next->content > last)
		&& (p->content < last) && (p->next->content > p->next->next->content)
		&& (p->next->next->content < last))
		moves += ft_check_rotation3(a);
	return (moves);
}

int	ft_check_rotation(t_node **a)
{
	t_node	*p;
	int		moves;
	int		last;
	int		i;

	if (!a)
		return (0);
	i = 0;
	moves = 0;
	p = ft_lstlast(a);
	last = p->content;
	p = *a;
	if (p->next != NULL && p->next->next != NULL)
	{
		if ((p->content > p->next->content)
			&& (p->next->content > p->next->next->content))
			moves += ft_sab(a, 0);
		moves += ft_check_rotation2(a);
	}
	p = ft_lstlast(a);
	if (p->content == ft_find_int_min(a))
		moves += ft_find_head(a);
	return (moves);
}
