/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:30:23 by lmarzano          #+#    #+#             */
/*   Updated: 2021/06/04 12:32:03 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_choose_cmd_re(t_node **a, t_node **b, char *cmd)
{
	if (!(ft_strcmp("ra", cmd)))
		ft_rot(a);
	else if (!(ft_strcmp("rb", cmd)))
		ft_rot(b);
	else if (!(ft_strcmp("rr", cmd)))
	{
		ft_rot(a);
		ft_rot(b);
	}
	else if (!(ft_strcmp("rra", cmd)))
		ft_rev(a);
	else if (!(ft_strcmp("rrb", cmd)))
		ft_rev(b);
	else if (!(ft_strcmp("rrr", cmd)))
	{
		ft_rev(a);
		ft_rev(b);
	}
	else
		ft_error(*a, *b);
}

void	ft_choose_cmd_sp(t_node **a, t_node **b, char *cmd)
{
	if (!(ft_strcmp("sa", cmd)))
		ft_swap(a);
	else if (!(ft_strcmp("sb", cmd)))
		ft_swap(b);
	else if (!(ft_strcmp("ss", cmd)))
	{
		ft_swap(a);
		ft_swap(b);
	}
	else if (!(ft_strcmp("pa", cmd)))
		ft_push_a(a, b);
	else if (!(ft_strcmp("pb", cmd)))
		ft_push_b(a, b);
	else
		ft_choose_cmd_re(a, b, cmd);
}

void	ft_command_launch(t_node **a, t_node **b)
{
	int		i;
	char	*cmd;

	i = 0;
	cmd = 0;
	while (1)
	{
		get_next_line(0, &cmd);
		if (!*cmd)
		{
			free (cmd);
			break ;
		}
		ft_choose_cmd_sp(a, b, cmd);
		free (cmd);
	}
}
