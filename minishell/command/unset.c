/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 17:56:21 by lmarzano          #+#    #+#             */
/*   Updated: 2021/09/15 17:56:45 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_free_lst(t_list **list)
{
	t_list	*p;
	t_list	*n;

	p = (*list)->prev;
	n = (*list)->next;
	ft_free_data((t_data *)((*list)->content));
	if (p != NULL)
		p->next = n;
	if (n != NULL)
		n->prev = p;
	free (*list);
	*list = n;
}

static int	ft_unset(t_list *list, char *parse)
{
	t_data	*p;
	t_data	*p_prev;

	if (parse == NULL)
		return (-1);
	while (list)
	{
		p = ((t_data *)(list->content));
		if (ft_strncmp(p->env, parse, ft_strlen(parse) + 1) == 0)
		{
			ft_free_lst(&list);
			return (1);
		}
		list = list->next;
	}
	if (!list)
		return (-1);
	return (1);
}

int	ft_check_unset(t_parse *parse, t_list *var)
{
	if (ft_unset(var, parse->input[1]) == -1)
		return (1);
	return (0);
}
