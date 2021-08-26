/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 10:55:45 by lmarzano          #+#    #+#             */
/*   Updated: 2021/06/28 14:46:34 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//	3 random digits
void	ft_sort_three(t_node **a, t_cmd *m)//	32 lines
{
	t_node	*c;
	int		mid;

	c = (*a)->next;
	mid = c->content;
	c = c->next;
	if ((*a)->content < mid && mid < c->content)
		return ;
	else if ((*a)->content > mid)
	{
		if (mid < c->content)
		{
			if ((*a)->content > c->content)
				ft_revp(a, &m, 1);//	case 3 (ra)
			else
			ft_swapp(a, &m, 1);//	case 1 (sa)
		}
		else
		{
			ft_swapp(a, &m, 1);
			ft_revp(a, &m, 1);// case 2 (sa - rra)
		}
	}
	else
	{
		if ((*a)->content < c->content)
		{
			ft_swapp(a, &m, 1);
			ft_rotp(a, &m, 1);//	case 4 (sa - ra)
		}
		else
			ft_revp(a, &m, 1);//	case 5 (rra)
	}
}

//	5 random digits

//	100 random digits

//	500 random digits

/*------------------------------------------------*/
//	NEW APPROACH :

/*
**	A)
**	find max subseq, analyzing how many lower digits are there before current digit,
**	and save the amount into structure "dist";
**
**	B) 
**	Starting from end of list, find the "max dist", then save the smallest/closest digits to current one.
**	That will be the longest subseq;
**	push everything else to stack b, in the mean time. <------------ we are here!!!
**	eventually use a -1 in "dist" for what doesn't belong to max subseq;
**
**	C)
**	for each element of stack b, determine how many moves would cost to sort it into stack a,
**	and save that value into "dist" (we can use dist, as we won't use it for previous task anymore);
**
**	D)
**	sort the least expensive digit and repeat C) && D) until stack b is empty and stack a is sorted well.
**	set up a len of stack b, so that if the best move is equal/greater than the position of len/2, will reverse-rotate, instead of rotating.
*/