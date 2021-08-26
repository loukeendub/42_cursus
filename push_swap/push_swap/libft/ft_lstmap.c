/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:18:26 by lmarzano          #+#    #+#             */
/*   Updated: 2021/05/29 11:48:27 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node	*ft_lstmap(t_node *lst, void *(*f)(int *))
{
	t_node	*new;
	t_node	*p;

	new = 0;
	if (lst && f)
	{
		while (lst)
		{
			p = ft_lstnew(f(&lst->content));
			if (!p)
			{
				ft_lstclear(&new);
				return (NULL);
			}
			ft_lstadd_back(&new, p);
			lst = lst->next;
		}
	}
	return (new);
}
