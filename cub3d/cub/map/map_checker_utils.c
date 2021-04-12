/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 11:27:35 by lmarzano          #+#    #+#             */
/*   Updated: 2021/04/12 11:27:36 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libcub.h"

int	check_around_walkables(int index, char *prev, char *curr, char *next)
{
	int	prev_max;
	int	next_max;

	prev_max = ft_strlen(prev) - 1;
	next_max = ft_strlen(next) - 1;
	if (index > prev_max || index > next_max)
		return (0);
	if (index == 0)
		return (0);
	if (prev[index] == ' ' || next[index] == ' '
		|| curr[index - 1] == ' ' || curr[index + 1] == ' ')
		return (0);
	return (1);
}

int	intermidiate_row(char *prev, char *curr, char *next)
{
	int	index;

	index = 0;
	while (curr[index])
	{
		if (is_in_cset(curr[index], "02NSWE"))
			if (!check_around_walkables(index, prev, curr, next))
				return (0);
		index++;
	}
	return (1);
}
