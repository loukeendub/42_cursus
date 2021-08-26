/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_psmoves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 10:47:22 by lmarzano          #+#    #+#             */
/*   Updated: 2021/06/30 18:04:41 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_cmd_to_lst(t_cmd **m, char *cmd)
{
	if (!(*m))
		*m = ft_cmdnew(cmd);
	else
		ft_cmdadd_back(m, ft_cmdnew(cmd));
}

void	ft_swapp(t_node **n, t_cmd **m, int stk)
{
	t_node	*c;
	

	c = 0;
	if (!(*n))
		return ;
	if (stk == 1)
		ft_cmd_to_lst(m, "sa");
	else if (stk == 2)
		ft_cmd_to_lst(m, "sb");
	else if (stk == 3)
		ft_cmd_to_lst(m, "ss");
	c = (*n)->next;
	(*n)->next = (*n)->next->next;
	c->next = (*n);
	(*n) = c;
}

void	ft_push_ap(t_node **a, t_cmd **m, t_node **b)
{
	t_node	*c;

	c = 0;
	if (!(*b))
		return ;
	ft_cmd_to_lst(m, "pa");
	c = (*b)->next;
	(*b)->next = NULL;
	ft_lstadd_front(a, *b);
	*b = c;
}

void	ft_push_bp(t_node **a, t_cmd **m, t_node **b)
{
	t_node	*c;

	c = 0;
	if (!(*a))
		return ;
	ft_cmd_to_lst(m, "pb");
	c = (*a);
	(*a) = (*a)->next;
	c->next = 0;
	ft_lstadd_front(b, c);
}

void	ft_rotp(t_node **n, t_cmd **m, int stk)
{
	t_node	*c;

	c = 0;
	if (!(*n) || !(*n)->next)
		return ;
	if (stk == 1)
		ft_cmd_to_lst(m, "ra");
	else if (stk == 2)
		ft_cmd_to_lst(m, "rb");
	else if (stk == 3)
		ft_cmd_to_lst(m, "rr");
	c = (*n);
	(*n) = (*n)->next;
	(*n)->prev = NULL;
	c->next = 0;
	c->prev = 0;
	ft_lstadd_back(n, c);
}

void	ft_revp(t_node **n, t_cmd **m, int stk)
{
	t_node	*c;

	c = 0;
	if (!(*n) || !(*n)->next)
		return ;
	if (stk == 1)
		ft_cmd_to_lst(m, "rra");
	else if (stk == 2)
		ft_cmd_to_lst(m, "rrb");
	else if (stk == 3)
		ft_cmd_to_lst(m, "rrr");
	c = (*n);
	while (c->next->next)
		c = c->next;
	c->next->next = (*n);
	(*n) = c->next;
	c->next = NULL;
}
