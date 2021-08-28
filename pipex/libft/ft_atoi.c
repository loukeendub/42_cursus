/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 09:52:48 by lmarzano          #+#    #+#             */
/*   Updated: 2021/05/17 11:23:05 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_operator(const char *str, int nums, int i)
{
	while (str[i] >= 48 && str[i] <= 57)
	{
		nums *= 10;
		nums += (str[i] - 48);
		i++;
	}
	return (nums);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	i;
	int	nums;

	i = 0;
	sign = 1;
	nums = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			sign = sign * -1;
		i++;
	}
	nums = ft_operator(str, nums, i);
	if (nums < 0 && nums > -2147483648)
	{
		if (sign > 0)
			return (-1);
		return (0);
	}
	nums = nums * sign;
	return (nums);
}
