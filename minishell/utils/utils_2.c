/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 18:01:59 by lmarzano          #+#    #+#             */
/*   Updated: 2021/09/15 18:02:18 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_find_next_c(char *str, int start, char c)
{
	int	i;

	i = 1;
	while (str[i + start] && str[i + start] != c)
		i++;
	if (str[i + start] == 0)
		return (0);
	return (i);
}

int	ft_find_next_str(char *str, const char *ref)
{
	int	i;

	i = 0;
	while (str[i] && ft_in_str(ref, str[i]) == 0)
		i++;
	return (i);
}

int	ft_in_str(const char *str, char c)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_between_c(char *str, int c_pos, char c)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (i < c_pos)
	{
		if (str[i] == c && flag == 0)
			flag = 1;
		else if (str[i] == c && flag == 1)
			flag = 0;
		i++;
	}
	if (flag == 0)
		return (0);
	if (ft_find_next_c(str, i, c))
		return (1);
	return (0);
}

void	ft_setprev(t_list **l)
{
	t_list	*head;
	t_list	*p;

	head = *l;
	p = (*l)->next;
	while (p)
	{
		p->prev = *l;
		*l = (*l)->next;
		p = p->next;
	}
	*l = head;
	(*l)->prev = NULL;
}
