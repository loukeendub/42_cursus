/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfabi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 18:43:26 by jfabi             #+#    #+#             */
/*   Updated: 2021/01/23 18:43:39 by jfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cpy;

	if (lst != 0)
	{
		while (*lst != 0)
		{
			cpy = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = cpy;
		}
	}
}
