/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:18:26 by lmarzano          #+#    #+#             */
/*   Updated: 2021/01/21 17:13:52 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*p;

	new = 0;
	if (lst && f)
	{
		while (lst)
		{
			if (!(p = ft_lstnew(f(lst->content))))
			{
				ft_lstclear(&new, del);
				return (NULL);
			}
			ft_lstadd_back(&new, p);
			lst = lst->next;
		}
	}
	return (new);
}
