/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfabi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 18:41:09 by jfabi             #+#    #+#             */
/*   Updated: 2021/01/23 18:43:55 by jfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	t_list	*cpy;

	if (lst != 0)
	{
		cpy = lst->next;
		if (del != 0)
			del(lst->content);
		free(lst);
		lst = cpy;
	}
}
