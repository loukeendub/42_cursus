/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 13:56:26 by lmarzano          #+#    #+#             */
/*   Updated: 2021/02/25 15:02:41 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	order_manager_d(char *s)
{
	int	len;

	len = ft_strlen(s);
	if (g_p->flags[0] == '-')
		print_minus_d(s, len);
	else
		print_standard_d(s, len);
}

void	order_manager_u(char *s)
{
	unsigned int	len;

	len = ft_strlen(s);
	if (g_p->flags[0] == '-')
		print_minus_u(s, len);
	else
		print_standard_u(s, len);
}

void	order_manager_x(char *s)
{
	unsigned int	len;

	len = ft_strlen(s);
	if (g_p->flags[0] == '-')
		print_minus_x(s, len);
	else
		print_standard_x(s, len);
}

void	order_manager_p(char *s)
{

}
