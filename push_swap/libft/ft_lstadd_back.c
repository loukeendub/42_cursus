/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 12:05:21 by lmarzano          #+#    #+#             */
/*   Updated: 2021/09/16 15:35:07 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*last;

	last = *lst;
	new->prev = NULL;
	new->next = NULL;
	if (lst && *lst)
	{
		last = ft_lstlast(&last);
		new->prev = last;
		last->next = new;
	}
	else
		*lst = new;
}
