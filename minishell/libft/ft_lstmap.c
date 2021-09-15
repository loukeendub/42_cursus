/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfabi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 18:39:36 by jfabi             #+#    #+#             */
/*   Updated: 2021/01/24 15:52:58 by jfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*cpy;
	t_list	*ret;
	t_list	*temp;

	if (lst == 0)
		return (0);
	cpy = lst;
	ret = ft_lstnew(f(cpy->content));
	if (ret == 0)
		return (0);
	cpy = cpy->next;
	while (cpy != 0)
	{
		temp = ft_lstnew(f(cpy->content));
		if (temp == 0)
		{
			ft_lstclear(&cpy, del);
			return (0);
		}
		ft_lstadd_back(&ret, temp);
		cpy = cpy->next;
	}
	return (ret);
}
