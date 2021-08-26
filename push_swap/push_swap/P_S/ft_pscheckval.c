/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pscheckval.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 10:54:38 by lmarzano          #+#    #+#             */
/*   Updated: 2021/06/04 10:12:46 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_errorp(t_node *a, t_node *b)
{
	write(1, "Error\n", 6);
	ft_lstclear(&a);
	ft_lstclear(&b);
	exit (0);
}

void	ft_error_finalep(void)
{
	write(1, "Error\n", 6);
	exit (0);
}

int	ft_check_doublesp(t_node *a, int tmp)
{
	while (a)
	{
		if (a->content == tmp)
			return (0);
		a = a->next;
	}
	return (1);
}

int	ft_isnump(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-')
		i++;
	while (s[i] != 0)
	{
		if (!(ft_isdigit(s[i])))
			return (0);
		i++;
	}
	return (1);
}

int	ft_isvalidp(t_node *a, t_node *b)
{
	t_node	*n;

	n = b;
	if (n)
		return (0);
	n = a;
	while (n->next)
	{
		a = a->next;
		if (n->content > a->content)
			return (0);
		n = n->next;
	}
	return (1);
}
