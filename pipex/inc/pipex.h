/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 11:17:35 by lmarzano          #+#    #+#             */
/*   Updated: 2021/07/29 15:14:47 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_data
{
	char	*infile;
	char	*outfile;
	char	**cmd1;
	char	**cmd2;
	int		fd[2];
	int		fdin;
	int		fdout;
	char	**path;
	char	*pathcmd1;
	char	*pathcmd2;
	int		fork_id;
	int		flag1;
	int		flag2;
}	t_data;

/*
**	[ parse.c ]
*/

int		ft_parse_cmd(t_data **data, char *argv, int cmd);
int		ft_parse_path(t_data **data, char **envp);
int		ft_parse_data(t_data **data, char **argv, char **envp);
int		ft_check_path(t_data **data, char **pathcmd, char *cmd);
int		ft_check_data(t_data *data);

/*
**	[ pipex.c ]
*/

int		ft_exec_cmd(t_data *data, char **envp, int cmd);
int		ft_exec_pipe(t_data *data, char **envp);
int		main(int argc, char **argv, char **envp);

/*
**	[ utils.c ]
*/

void	ft_struct_init(t_data *data);
int		ft_error(int err);
void	ft_free_mtx(char **mtx);
void	ft_free_data(t_data **data);
void	ft_print_mtx(char **mtx);

#endif
