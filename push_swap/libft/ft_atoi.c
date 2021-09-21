/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 09:52:48 by lmarzano          #+#    #+#             */
/*   Updated: 2021/09/16 15:34:46 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_longerint(void)
{
	write(1, "Error\n", 6);
	exit (0);
}

int	ft_atoi(const char *str)
{
	long int	total;
	long int	multiplier;

	total = 0;
	multiplier = 1;
	while (*str == ' ' || *str == '\f' || *str == '\n' || \
		 *str == '\r' || *str == '\t' || *str == '\v')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		multiplier = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		total *= 10;
		total += *str - '0';
		if ((total * multiplier < INT_MIN) || (total * multiplier > INT_MAX))
			ft_longerint();
		str++;
	}
	return (total * multiplier);
}
