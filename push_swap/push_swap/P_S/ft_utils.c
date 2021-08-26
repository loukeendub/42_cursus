/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 11:40:08 by lmarzano          #+#    #+#             */
/*   Updated: 2021/06/30 17:20:04 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*ft_lst_to_arr(t_node *a, int *aval)
{
	t_node	*p;
	int		i;

	p = a;
	i = 0;
	while (p->next)
	{
		aval[i] = p->content;
		p = p->next;
		i++;
	}
	aval[i] = p->content;
	return (aval);
}

void	ft_print_list(t_node *n)
{
	printf("content\n");
	if (!n)
		return ;
	while (n->next)
	{
		ft_putnbr_fd(n->content, 1);
		ft_putstr_fd(" ", 1);
		ft_putnbr_fd(n->flag, 1);
		ft_putstr_fd(" ", 1);
		ft_putnbr_fd(n->dist, 1);
		write(1, "\n", 2);
		n = n->next;
	}
	ft_putnbr_fd(n->content, 1);
	ft_putstr_fd(" ", 1);
	ft_putnbr_fd(n->flag, 1);
	ft_putstr_fd(" ", 1);
	ft_putnbr_fd(n->dist, 1);
	write(1, "\n\n", 2);
}
void	ft_print_rev_list(t_node *n)
{
	printf("rev content\n");
	if (!n)
		return ;
	n = ft_lstlast(n);
	while (n->prev)
	{
		ft_putnbr_fd(n->content, 1);
		ft_putstr_fd(" ", 1);
		ft_putnbr_fd(n->flag, 1);
		ft_putstr_fd(" ", 1);
		ft_putnbr_fd(n->dist, 1);
		write(1, "\n", 2);
		n = n->prev;
	}
	ft_putnbr_fd(n->content, 1);
	ft_putstr_fd(" ", 1);
	ft_putnbr_fd(n->flag, 1);
	ft_putstr_fd(" ", 1);
	ft_putnbr_fd(n->dist, 1);
	write(1, "\n", 2);
	write(1, "\n\n", 2);
}

void	ft_print_mov(t_node *n)
{
	printf("moves\n");
	if (!n)
		return ;
	while (n->next)
	{
		ft_putnbr_fd(n->moves, 1);
		write(1, "\n", 2);
		n = n->next;
	}
	ft_putnbr_fd(n->moves, 1);
	write(1, "\n\n", 2);
}

void	ft_print_cmd(t_cmd *n)
{
	printf("MOVES :\n");
	if (!n)
		return ;
	while (n->next)
	{
		ft_putstr_fd(n->cmd, 1);
		write(1, "\n", 2);
		n = n->next;
	}
	ft_putstr_fd(n->cmd, 1);
	write(1, "\n\n", 2);
}

void	ft_print_flags(t_node *n)
{
	printf("flags\n");
	if (!n)
		return ;
	while (n->next)
	{
		ft_putnbr_fd(n->flag, 1);
		write(1, "\n", 2);
		n = n->next;
	}
	ft_putnbr_fd(n->flag, 1);
	write(1, "\n\n", 2);
}

void	ft_setprev(t_node **l)
{
	t_node	*head;
	t_node	*p;

	head = *l;
	head->prev = NULL;
	p = (*l)->next;
	while (p)
	{
		p->prev = *l;
		*l = (*l)->next;
		p = p->next;
	}
	*l = head;
}

void	ft_cmdadd_back(t_cmd **lst, t_cmd *new)
{
	t_cmd	*last;

	new->prev = NULL;
	new->next = NULL;
	if (lst && *lst)
	{
		last = *lst;
		while (last->next)
			last = last->next;
		last->next = new;
		new->prev = last;
	}
	else if (*lst)
		*lst = new;
}

t_cmd	*ft_cmdnew(char *cont)
{
	t_cmd	*new;
	
	new = malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->prev = NULL;
	new->next = NULL;
	new->cmd = cont;
	return (new);
}

void	ft_flag_init(t_node **l)
{
	t_node	*i;

	i = *l;
	while (i->prev)
		i = i->prev;
	while (i)
	{
		i->flag = 0;
		if (!i->next)
			break ;
		i = i->next;
	}
}

void	ft_dst_init(t_node **l)
{
	t_node	*i;

	i = *l;
	while (i->prev)
		i = i->prev;
	while (i)
	{
		i->dist = 0;
		if (!i->next)
			break ;
		i = i->next;
	}
}