/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pscheckarg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 11:58:36 by lmarzano          #+#    #+#             */
/*   Updated: 2021/09/21 13:46:03 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_prev(t_node *cmd)
{
	t_node	*prev;

	if (cmd)
	{
		cmd->prev = NULL;
		prev = cmd;
		if (cmd->next != NULL)
		{
			cmd = cmd->next;
			while (cmd)
			{
				cmd->prev = prev;
				prev = cmd;
				cmd = cmd->next;
			}
		}
	}
	else
		if (cmd)
			cmd->prev = NULL;
}

int	ft_fill_stackp(char *args, t_node **a)
{
	int		tmp;
	t_node	*temp;

	tmp = ft_atoi(args);
	temp = malloc(sizeof(t_node));
	temp->content = tmp;
	temp->next = NULL;
	temp->prev = NULL;
	temp->dist = 0;
	if (!(ft_check_doublesp(*a, tmp)))
	{
		free (temp);
		write(1, "Error\n", 6);
		exit (0);
	}
	ft_lstadd_back(a, temp);
	return (1);
}

int	ft_checkstrp(char *argv, t_node **a)
{
	int		i;
	char	**args;

	i = 0;
	args = ft_split(argv, ' ');
	while (args[i])
	{
		if (ft_isnump(args[i]))
		{
			if (!(ft_fill_stackp(args[i], a)))
				ft_lstclear(a);
		}
		i++;
	}
	i = 0;
	while (args[i] != 0)
		free(args[i++]);
	free(args[i]);
	free(args);
	return (1);
}

int	ft_checkargp(char **argv, int argc)
{
	int		i;
	int		size;
	t_node	*a;

	i = 1;
	a = 0;
	size = 0;
	while (i < argc)
	{
		if (!(ft_checkstrp(argv[i], &a)))
			return (0);
		i++;
		size++;
	}
	if (ft_lstsize(a) == 1)
		exit (0);
	if ((ft_checker_top(&a) == -1))
		exit (0);
	ft_add_prev(a);
	if (ft_lstsize(a) < 6 && ft_lstsize(a) > 2)
		ft_quicksort(&a);
	else
		ft_commands(&a);
	ft_lstclear(&a);
	return (1);
}
