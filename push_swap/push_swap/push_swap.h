/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:02:51 by lmarzano          #+#    #+#             */
/*   Updated: 2021/06/30 19:38:56 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

/*
**	Functions
**
**	[CHECKER]
**	ft_checker.c
*/
void	ft_print_list(t_node *n);
int		ft_fill_stack(char *args, t_node **a, t_node **b, int *size);
int		ft_checkstr(char *argv, t_node **a, t_node **b);
int		ft_checkarg(char **argv, int argc);
/*
**	ft_checkval.c
*/
void	ft_error(t_node *a, t_node *b);
void	ft_error_finale(void);
int		ft_check_doubles(t_node *a, int tmp);
int		ft_isnum(char *s);
int		ft_isvalid(t_node *a, t_node *b);
/*
**	ft_commands.c
*/
void	ft_choose_cmd_re(t_node **a, t_node **b, char *cmd);
void	ft_choose_cmd_sp(t_node **a, t_node **b, char *cmd);
void	ft_command_launch(t_node **a, t_node **b);
/*
**	ft_moves.c [FULL]
*/
void	ft_swap(t_node **n);
void	ft_push_a(t_node **a, t_node **b);
void	ft_push_b(t_node **a, t_node **b);
void	ft_rot(t_node **n);
void	ft_rev(t_node **n);
/*
**	MOVES STRUCTURES
*/
typedef struct s_cmd
{
	char			*cmd;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}					t_cmd;
/*
**
**	[PUSH_WASP]
**	ft_push_swap.c
*/
void	ft_sort_three(t_node **a, t_cmd *m);
/*
**	ft_pscheckarg.c
*/
int		ft_fill_stackp(char *args, t_node **a, t_node **b, int *size);
int		ft_checkstrp(char *argv, t_node **a, t_node **b);
int		ft_checkargp(char **argv, int argc);
/*
**	ft_pscheckval.c
*/
void	ft_errorp(t_node *a, t_node *b);
void	ft_error_finalep(void);
int		ft_check_doublesp(t_node *a, int tmp);
int		ft_isnump(char *s);
int		ft_isvalidp(t_node *a, t_node *b);
/*
**	ft_pscommands.c
*/
void	ft_putflags(t_node **a);
t_cmd	*ft_first_push(t_node **a, t_node **b, t_cmd *m);
t_cmd	*ft_max_subseq(int *aval, t_node **a, t_node **b, t_cmd *m);
void	ft_least_moves(t_node **a, t_node **b);
void	ft_mcount(t_node **l, int stk, int midp);
void	ft_fillmoves(t_node **a, t_node **b, t_cmd *m);
void	ft_commands(t_node **a, t_node **b, t_cmd **c);
/*
**	ft_psmoves.c [FULL]
*/
void	ft_swapp(t_node **n, t_cmd **m, int stk);
void	ft_push_ap(t_node **a, t_cmd **m, t_node **b);
void	ft_push_bp(t_node **a, t_cmd **m, t_node **b);
void	ft_rotp(t_node **n, t_cmd **m, int stk);
void	ft_revp(t_node **n, t_cmd **m, int stk);
/*
**	ft_utils.c	[FULL]
*/
int		*ft_lst_to_arr(t_node *a, int *aval);
void	ft_print_mov(t_node *n);
void	ft_print_cmd(t_cmd *n);
void	ft_print_flags(t_node *n);
void	ft_setprev(t_node **l);
void	ft_cmdadd_back(t_cmd **lst, t_cmd *new);
t_cmd	*ft_cmdnew(char *cont);
void	ft_flag_init(t_node **l);
void	ft_print_rev_list(t_node *n);
void	ft_dst_init(t_node **l);

#endif
