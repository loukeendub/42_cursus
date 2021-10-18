/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:16:09 by lmarzano          #+#    #+#             */
/*   Updated: 2021/10/11 18:16:21 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	while (s && *s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}

static int	ft_operator(char *str, int nums, int i)
{
	while (str[i] >= 48 && str[i] <= 57)
	{
		nums *= 10;
		nums += (str[i] - 48);
		i++;
	}
	return (nums);
}

int	ft_atoi(char *str)
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
