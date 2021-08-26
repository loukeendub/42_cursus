/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 12:05:21 by lmarzano          #+#    #+#             */
/*   Updated: 2021/06/28 16:09:37 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*last;

	new->prev = NULL;
	new->next = NULL;
	if (lst && *lst)
	{
		last = *lst;
		while (last->next)
			last = last->next;
		last->next = new;
		new->prev = last;
		last->dist = 0;
		new->dist = 0;
		last->moves = 0;
		new->moves = 0;
	}
	else if (lst)
		*lst = new;
}
