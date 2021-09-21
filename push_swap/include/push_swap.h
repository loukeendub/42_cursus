/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:02:51 by lmarzano          #+#    #+#             */
/*   Updated: 2021/09/21 11:50:28 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
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
**	[PUSH_WASP]
**	ft_commands.c
*/
int		ft_rrab(t_node **head, int s);
int		ft_rab(t_node **head, int s);
int		ft_pab(t_node **head_to, t_node **head_from, int s);
int		ft_sab(t_node **head, int s);
void	ft_swap(t_node **stack);
/*
**	ft_commands2.c
*/
int		ft_ss(t_node **stack_a, t_node **stack_b);
int		ft_rr(t_node **stack1, t_node **stack2);
int		ft_rrr(t_node **stack1, t_node **stack2);
/*
**	ft_exec.c
*/
int		ft_exec_moves(t_node **a, t_node **b, int move);
int		ft_exec_rb(t_node **b, int count);
/*
**	ft_exec2.c
*/
int		ft_exec_rrb(t_node **b, int count);
int		ft_exec_ra(t_node **a, int count);
int		ft_exec_rra(t_node **a, int count);
int		ft_exec_rr(t_node **a, t_node **b, int count);
int		ft_exec_rrr(t_node **a, t_node **b, int count);
/*
**	ft_find.c
*/
int		ft_find_position(t_node **a, int num);
int		ft_find_int_min(t_node **a);
int		ft_find_int_max(t_node **a);
/*
**	ft_flag_utils.c
*/
void	ft_smaller(t_node *p, t_node **a);
int		ft_get_dmax(t_node **a);
/*
**	ft_flags.c
*/
int		ft_find_dmax(t_node **a);
void	ft_set_flags(t_node **a, int dmax);
int		ft_check_flag(t_node *p, int ref);
int		ft_set_negative(t_node **a, int dmax);
/*
**	ft_head_manager.c
*/
int		ft_find_head(t_node **a);
int		ft_sort_head(t_node **a, int head);
int		ft_move_head(t_node **a, int i);
/*
**	ft_movecount.c
*/
int		ft_count_moves(int i, int j, t_node **a, t_node **b);
int		ft_count_upper_half(int i, int j, t_node **a, t_node **b);
int		ft_count_low_half(int i, int j);
int		ft_count_same(int i, int j, t_node **a, t_node **b);
/*
**	ft_moves.c
*/
int		ft_max(t_node **a, t_node **b);
int		ft_count_max(t_node **a, t_node **b, int max_a);
int		ft_min(t_node **a, t_node **b);
int		ft_count_min(t_node **a, int min_a);
/*
**	ft_pscheckarg.c
*/
int		ft_fill_stackp(char *args, t_node **a);
int		ft_checkstrp(char *argv, t_node **a);
int		ft_checkargp(char **argv, int argc);
void	ft_add_prev(t_node *cmd);
/*
**	ft_pscheckval.c
*/
void	ft_errorp(t_node *a, t_node *b);
void	ft_error_finalep(void);
int		ft_check_doublesp(t_node *a, int tmp);
int		ft_isnump(char *s);
int		ft_isvalidp(t_node *a, t_node *b);
/*
**	ft_push.c
*/
int		ft_push(t_node **a, t_node **b, int dmax);
int		ft_push_after_dmax(t_node **a, t_node **b, int last);
int		ft_push_before_dmax(t_node **a, t_node **b, int check, int stop);
int		ft_final_push(t_node **a, t_node **b, int stop);
/*
**	ft_rotations.c
*/
int		ft_check_rotation(t_node **a);
int		ft_check_rotation2(t_node **a);
int		ft_check_rotation3(t_node **a);
int		ft_check_rotation4(t_node **a);
/*
**	ft_save_moves.c
*/
void	ft_save_moves(t_node **a, t_node **b, int i, int j);
void	ft_save_same(t_node **a, t_node **b, int i, int j);
void	ft_save_mixed_half(t_node **a, t_node **b, int i, int j);
void	ft_save_upper_half(t_node **a, t_node **b, int i, int j);
void	ft_save_low_half(t_node **b, int i, int j);
/*
**	ft_sort.c
*/
void	ft_commands(t_node **a);
int		ft_checker_top(t_node **a);
int		ft_chose_num(t_node **a, t_node **b);
void	ft_set_moves(t_node **a, t_node **b);
int		ft_get_info(t_node **a, t_node *b, int large, int sent);
/*
**	ft_utils.c
*/
void	ft_init_moves(t_node **stack);
int		ft_half(int size);
void	ft_print_list(t_node *n);
void	ft_print_rev_list(t_node *n);
/*
**	ft_utils2.c
*/
int		ft_get_j(t_node **a, t_node **b, int large, int j);
t_node	*ft_get_p(t_node **stack, int stop);
int		ft_check_switch(t_node **a);
/*
**	ft_quicksort.c
*/
void	ft_quicksort(t_node **a);

#endif
