/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:31:11 by lmarzano          #+#    #+#             */
/*   Updated: 2021/05/29 11:47:23 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_node *lst, void (*f)(int *))
{
	if (lst && f)
	{
		while (lst)
		{
			f(&(lst)->content);
			lst = lst->next;
		}
	}
}
