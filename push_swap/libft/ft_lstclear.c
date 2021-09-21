/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 14:18:09 by lmarzano          #+#    #+#             */
/*   Updated: 2021/09/16 15:36:15 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_node **lst)
{
	t_node	*p;

	p = (*lst);
	if (lst)
	{
		while (*lst)
		{
			p = (*lst)->next;
			free(*lst);
			*lst = p;
		}
	}
	*lst = NULL;
}
