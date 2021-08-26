/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 11:58:36 by lmarzano          #+#    #+#             */
/*   Updated: 2021/06/04 09:50:07 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_print_list(t_node *n)
{
	if (!n)
		return ;
	while (n->next)
	{
		ft_putnbr_fd(n->content, 1);
		write(1, "\n", 2);
		n = n->next;
	}
	ft_putnbr_fd(n->content, 1);
	write(1, "\n\n", 2);
}

int	ft_fill_stack(char *args, t_node **a, t_node **b, int *size)
{
	int		tmp;
	t_node	*temp;

	tmp = ft_atoi(args);
	temp = malloc(sizeof(temp));
	temp->content = tmp;
	temp->dist = 0;
	temp->next = NULL;
	temp->prev = NULL;
	if (!(ft_check_doubles(*a, tmp)))
	{
		free (temp);
		ft_error((*a), (*b));
	}
	ft_lstadd_back(a, temp);
	size++;
	return (1);
}

int	ft_checkstr(char *argv, t_node **a, t_node **b)
{
	int		i;
	char	**args;
	int		size;

	i = 0;
	size = 0;
	args = ft_split(argv, ' ');
	while (args[i])
	{
		if (ft_isnum(args[i]))
		{
			if (!(ft_fill_stack(args[i], a, b, &size)))
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

int	ft_checkarg(char **argv, int argc)
{
	int		i;
	t_node	*a;
	t_node	*b;

	i = 1;
	a = 0;
	b = 0;
	while (i < argc)
	{
		if (!(ft_checkstr(argv[i], &a, &b)))
			return (0);
		i++;
	}
	ft_command_launch(&a, &b);
	ft_print_list(a);
	ft_print_list(b);
	if (!(ft_isvalid(a, b)))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	ft_lstclear(&a);
	ft_lstclear(&b);
	return (1);
}
// gcc push_swap/CHR/ft_checker.c push_swap/CHR/ft_commands.c push_swap/libft/ft_atoi.c push_swap/libft/ft_lstadd_back.c push_swap/libft/ft_split.c push_swap/libft/ft_isdigit.c push_swap/libft/ft_lstclear.c push_swap/libft/ft_strlcpy.c push_swap/libft/ft_strncmp.c push_swap/libft/get_next_line.c push_swap/libft/get_next_line_utils.c push_swap/libft/ft_strlen.c push_swap/libft/ft_lstadd_front.c push_swap/libft/ft_lstlast.c push_swap/CHR/main.c push_swap/CHR/ft_moves.c push_swap/CHR/ft_checkval.c push_swap/libft/ft_putnbr_fd.c push_swap/libft/ft_putchar_fd.c
