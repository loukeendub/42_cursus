/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 17:54:23 by lmarzano          #+#    #+#             */
/*   Updated: 2021/09/15 18:06:59 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <dirent.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <signal.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <termios.h>
# include "libft.h"
# include "get_next_line.h"

typedef struct s_token
{
	char	*line;
	t_list	*s_flag;
	t_list	*flag;
	t_list	*s_commands;
	t_list	*commands;
}				t_token;

typedef struct s_data
{
	char	*env;
	char	*content;
	int		id;
}				t_data;

typedef struct s_parse
{
	char	*command;
	char	**input;
	char	**output;
}				t_parse;

int				g_fd;

/*
**	>---COMMAND---<
*/

/* all_command */
int		ft_execute_command(t_parse *parse, t_list *env);
/* cd */
int		ft_check_cd(t_parse *parse, t_list *env);
/*echo*/
int		ft_check_echo(t_parse *parse);
/* env */
int		ft_check_env(t_parse *parse, t_list *env);
/* exit */
int		ft_check_exit(t_parse *parse, t_list *list, t_list *env);
/* export */
int		ft_check_export(t_parse *parse, t_list *env);
/* pwd */
int		ft_check_pwd(t_parse *parse, t_list *env);
char	*ft_get_pwd(void);
/* unset */
int		ft_check_unset(t_parse *parse, t_list *env);
/* utils */
char	*ft_check_path(char *str, t_list *var);

/*
**  >---FILE_MANAGER---<
*/

/* file.c */
void	ft_save_fd(int *fd_in, int *fd_out);
void	ft_restore_fd(int fd[2]);
int		ft_open_red(char **output, int *fd_in, int *fd_out, t_list *history);

/*
**	>---PARSE---<
*/

/* parse.c */
t_parse	*ft_parsing(char *line);

/* parse_check.c */
int		ft_parse_check(char *line);
int		ft_check_command(char *str);

/* parse_create.c */
t_parse	*ft_create_parse(char **stringa);

/* parse_dollar.c */
char	*ft_expand(char *line, t_list *var);

/* parse_manager.c */
int		ft_create_str_parse(char **mtx, char **red, char *line);

/* parse_utils.c */
void	ft_free_parse(t_parse *parse);
int		ft_is_quotes(char *str, int c_pos, char c, char d);
int		ft_in_quotes(char *str, int c_pos, char c, char d);

/*
**  >--PIPE---<
*/

/* create_parse.c */
t_list	*ft_list_parse(char *line);

/* exec_pipe.c */
int		ft_exec_pipe(t_parse *parse, t_parse *nxt, t_list *story, t_list *var);

/*
**  >---READ---<
*/

/* history.c */
int		ft_cpy_history(t_list *list, t_list *var);
int		ft_change_history(char *line, t_list **list);
int		ft_file_history(t_list **list, t_list *var);

/* prompt.c */
char	*ft_prompt(const char *prompt, t_list **list, struct termios *termios);
void	ft_write_prompt(char *prompt, char *line);

/* read.c */
char	*ft_read(const char *prompt, t_list **list);

/*
**	>---SRCS---<
*/

/* create_path */
char	*ft_create_path(t_list *list, char *str);
char	*ft_create_minus_path(t_list *list);
char	*ft_create_home_path(t_list *list);

/* error */
int		ft_error(int id, char c, char *str);

/* main.c */
int		ft_execute(t_parse *parse, t_list *list, t_list *var);

/*
**  >---UTILS---<
*/

/* data_utils.c */
t_data	*ft_malloc_data(int size_env, int size_content);
t_list	*ft_new_datalist(const char *env, const char *content, int id);
int		ft_data_lst_size(t_list *data_list, int id);

/* env_utils.c */
char	*ft_find_env(t_list *list, char *env, int len);
int		ft_change_env(t_list *list, char *dst, char *src);
void	ft_free_listenv(t_list *env);
int		ft_create_env(t_list *list, const char *env, const char *text, int id);
int		ft_add_env(t_list *var, char *dst, char *src, int id);

/* file_utils.c */
int		ft_run_extra_terminal(char *del, t_list *history);
int		ft_open_file(char **output, int fd);
int		ft_open_arrow(int flag, char *stringa);

/* flag_utils.c */
int		ft_find_flag(char **stringa);
char	*ft_convert_flag(int flag);
int		ft_n_flag(char **matrix);
int		ft_is_flag(char *str);

/* lst_utils.c */
int		ft_list_by_file(char *dst, t_list **list, int file_len, int offset);
int		ft_lst_add_content(void	*content, t_list **list, int flag);

/* mtr_utils.c */
int		ft_mtrlen(char **matrix);
char	**ft_mtrlcpy(char **src, int len);
void	*ft_free_matrix(char **matrix);

/* signal_utils.c */
void	ft_aspetta(int sign);
void	ft_ciao(int sign);

/* utils.c */
void	ft_free_list(t_list *list);
void	ft_free_parse_list(t_list *list);
char	*ft_strdel(char *str, int num);
char	**ft_lst_to_mtx(t_list *list);

/* utils_2.c */
int		ft_between_c(char *str, int c_pos, char c);
int		ft_find_next_c(char *str, int start, char c);
int		ft_find_next_str(char *str, const char *ref);
int		ft_in_str(const char *str, char c);
void	ft_setprev(t_list **l);

/* utils_3.c */
char	*ft_m_strlcpy(char *str, int len);
void	*ft_free_null(void	*obj);
int		ft_find_strposition(char *str, char **matrix);
void	ft_null(int sign);
void	ft_free_data(t_data *data);

#endif
