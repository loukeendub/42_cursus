/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 11:07:41 by lmarzano          #+#    #+#             */
/*   Updated: 2021/09/16 15:35:25 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_node **lst, t_node *new)
{
	t_node	*list;

	list = *lst;
	new->prev = NULL;
	new->next = NULL;
	if (!(*lst))
		(*lst) = new;
	else
	{
		new->next = list;
		list->prev = new;
		(*lst) = new;
	}
}
