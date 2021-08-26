/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pscheckarg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 11:58:36 by lmarzano          #+#    #+#             */
/*   Updated: 2021/06/28 15:08:14 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_fill_stackp(char *args, t_node **a, t_node **b, int *size)
{
	int		tmp;
	t_node	*temp;

	tmp = ft_atoi(args);
	temp = malloc(sizeof(t_node));
	temp->content = tmp;
	if (!(ft_check_doublesp(*a, tmp)))
	{
		free (temp);
		ft_errorp((*a), (*b));
	}
	ft_lstadd_back(a, temp);
	(*size)++;
	return (1);
}

int	ft_checkstrp(char *argv, t_node **a, t_node **b)
{
	int		i;
	char	**args;
	int		size;

	i = 0;
	size = 0;
	args = ft_split(argv, ' ');
	while (args[i])
	{
		if (ft_isnump(args[i]))
		{
			if (!(ft_fill_stackp(args[i], a, b, &size)))
				ft_lstclear(a);
		}
		i++;
	}
	i = 0;
	while (args[i])
		free (args[i++]);
	free(args[i]);
	free(args);
	return (1);
}

int	ft_checkargp(char **argv, int argc)
{
	int		i;
	t_node	*a;
	t_node	*b;
	t_cmd	*c;

	i = 1;
	a = 0;
	b = 0;
	c = 0;
	while (i < argc)
	{
		if (!(ft_checkstrp(argv[i], &a, &b)))
			return (0);
		i++;
	}
	ft_commands(&a, &b, &c);//	from here the code is different from checker.
		puts("FINAL");//	<---------sigsegv before this point.
	ft_print_list(a);//	----------------DEBUG
	if(b)
		ft_print_list(b);//	----------------DEBUG
	ft_lstclear(&a);
	ft_lstclear(&b);
	ft_lstclear((t_node **)c);
	return (1);
}
