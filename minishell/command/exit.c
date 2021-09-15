/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 17:56:02 by lmarzano          #+#    #+#             */
/*   Updated: 2021/09/15 17:56:45 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_exit(t_parse *parse, t_list *list, t_list *var)
{
	ft_cpy_history(list, var);
	ft_free_listenv(var);
	ft_free_parse(parse);
	while (list)
	{
		free(list->content);
		free(list);
		list = list->next;
	}
	ft_putstr_fd("exit\n", 1);
	exit(0);
}
