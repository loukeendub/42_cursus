/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 11:17:22 by lmarzano          #+#    #+#             */
/*   Updated: 2021/07/29 14:39:47 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"
#include <errno.h>

void	ft_struct_init(t_data *data)
{
	data->infile = NULL;
	data->outfile = NULL;
	data->cmd1 = NULL;
	data->cmd2 = NULL;
	data->fdin = 0;
	data->fdout = 0;
	data->path = NULL;
	data->pathcmd1 = NULL;
	data->pathcmd2 = NULL;
	data->flag1 = 0;
	data->flag2 = 0;
}

int	ft_error(int err)
{
	if (err == 0)
		return (-1);
	else if (err == 1)
		ft_putstr_fd("Error\n", 2);
	else if (err == 2)
		ft_putstr_fd("Error: invalid input\n", 2);
	else if (err == 3)
		ft_putstr_fd("Error: invalid file(s)\n", 2);
	else if (err == 4)
		ft_putstr_fd("Error: invalid command(s)\n", 2);
	else if (err == 5)
		ft_putstr_fd("Error: bad execution\n", 2);
	return (-1);
}

void	ft_free_mtx(char **mtx)
{
	int	i;

	i = 0;
	while (mtx[i])
	{
		free(mtx[i]);
		i++;
	}
	free(mtx);
}

void	ft_free_data(t_data **data)
{
	if ((*data)->infile)
		free((*data)->infile);
	if ((*data)->outfile)
		free((*data)->outfile);
	if ((*data)->cmd1)
		ft_free_mtx((*data)->cmd1);
	if ((*data)->cmd2)
		ft_free_mtx((*data)->cmd2);
	if ((*data)->pathcmd1)
		free((*data)->pathcmd1);
	if ((*data)->pathcmd2)
		free((*data)->pathcmd2);
	if ((*data)->flag1 == 0 || (*data)->flag2 == 0)
	{
		if ((*data)->path)
			ft_free_mtx((*data)->path);
	}
}

void	ft_print_mtx(char **mtx)
{
	int	i;

	i = 0;
	while (mtx[i])
	{
		ft_putstr_fd(mtx[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
	ft_putchar_fd('\n', 1);
}
