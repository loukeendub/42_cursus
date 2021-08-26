/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pscommands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 09:53:05 by lmarzano          #+#    #+#             */
/*   Updated: 2021/07/02 11:46:44 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_putflags(t_node **a)//	32 lines
{
	t_node	*p;
	int		dmax;

	p = (*a);
	p->prev = NULL;
	dmax = 0;
	while (p)
	{
		if (p->dist > dmax)
			dmax = p->dist;
		if (p->next)
			p = p->next;
		else
			break ;
	}
	while (p->dist != dmax)
	{
		p->flag = -1;
		p = p->prev;
	}
	while (p->prev)
	{
		p->flag = 0;
		if (dmax > p->dist)
			dmax = p->dist;
		else if ((p->prev->dist < dmax && p->dist == dmax && p->next->dist == dmax) || (p->dist > dmax) || (p->dist == dmax && dmax == 0))
			p->flag = -1;
		p = p->prev;
	}
	if (p->dist == dmax && p->next->dist <= dmax)
		p->flag = -1;
	else
		p->flag = 0;
}

t_cmd	*ft_first_push(t_node **a, t_node **b, t_cmd *m)//	<------- to moves
{
	t_node	*p;
	int		cmd;

	cmd = 0;
	while ((*a) && (*a)->flag != 1)
	{
		p = (*a)->next;
		if (p->prev->flag == -1)
			ft_push_bp(a, &m, b);
		else
		{
			p->prev->flag = 1;
			ft_rotp(a, &m, 1);
		}
	}
	ft_setprev(a);
	ft_setprev(b);
	return (m);
}

t_cmd	*ft_max_subseq(int *aval, t_node **a, t_node **b, t_cmd *m)// 26 lines
{
	t_node	*p;
	int	i;
	int	last;
	int	val;

	p = ft_lstlast(*a);
	i = ft_lstsize(*a) - 1;
	last = i;
	while (last >= 0)
	{
		i = last;
		val = aval[i];
		while (i >= 0)
		{
			if (val > aval[i])
				p->dist++;
			i--;
		}
		if (p->prev)
			p = p->prev;
		else
			break;
		last--;
	}
	ft_putflags(&(*a));
	return (ft_first_push(a, b, m));
}

//void	ft_set_mov_flag(t_node **a, t_node **b, int num)
//{
//	t_node *p;
//	t_node *q;
//
//	p = *a;
//	q = *b;
//	while (q)
//	{
//		if (q->content == num)
//			q->flag = 1;
//		if (!q->next)
//			break ;
//		q = q->next;
//	}
//	while (p->content < num)
//	{
//		if (!p->next)
//		{
//			while (p->prev)
//				p = p->prev;
//			break ;
//		}
//		else
//			p = p->next;
//	}
//	p->flag = 1;
//}

/*
**	TUTTA QUESTA BELLA ROBA VA INFILATA DENTRO FT_LEAST_MOVES!!!
**
**	1) funzione che prende in input (*a) e restituisce la posizione dell'elemento più piccolo (pos);
**	2) itero stack_a fino a posizione (pos);
**	3) controllo:
**		a. se b_elem < p->content : valore = p->moves;
**		b. se !p->next : p = *a && controlli SOLO (pos) elementi;
**		c. se non c'è corrispondenza (max list_elem)  valore = p->next->moves
**		d. se non c'è corrispondenza e !p->next : valore = 0;
*/

t_node	*ft_find_min(t_node **stk)
{
	t_node	*p;

	p = *stk;
	if (!p)
		return (NULL);
	while(p->prev)
		p = p->prev;
	while (p->next && p->content < p->next->content)
		p = p->next;
	if (!p->next)
		return (*stk);
	return (p->next);
}

int	ft_mov_flg_update(t_node **a, t_node **b, t_node *pos, int tot)
{
	int	mov;

	mov = (*a)->moves + (*b)->moves;
	if ((*a)->content > (*b)->content || (*a)->content == pos->content)
	{
		if ((*a)->prev->content > (*b)->content)
			mov = (*a)->prev->moves + (*b)->moves;
		if (tot > mov || tot == 0)
		{
			ft_flag_init(a);
			ft_flag_init(b);
			if ((*b)->content < pos->content && (*a)->content == pos->next->content)
				(*a)->prev->flag = 1;
			else
				(*a)->flag = 1;
			(*b)->flag = 1;
			return (mov);//	in case of lower movecount found in current check
		}
	}
	return (tot);
}

int	ft_check_mov(t_node *pos, t_node **a, t_node *b, int tot)
{
	t_node	*p;
	int		mov;

	mov = 0;
	p = pos;
	p = p->next;
	while (p != pos && p->content < b->content)
	{
		if (!p->next)
			p = *a;
		else
			p =p->next;
	}
	mov = ft_mov_flg_update(&p, &b, pos, tot);
	mov = ft_mov_flg_update(&p, &b, pos, tot);
	return (mov);//	in case of higher movecount found in current check
}

void	ft_least_moves(t_node **a, t_node **b)
{
	t_node	**p;
	t_node	*q;
	int		mov;

	p = a;
	*p = ft_find_min(a);
	//printf("first stack elm : %d\n", (*p)->content);//	----------------DEBUG
	q = *b;
	mov = 0;
	while (q)
	{
		mov = ft_check_mov(*p, a, q, mov);
		//printf("mov : %d\n", mov);
		q = q->next;
	}
	//puts("end of least_moves");
	//ft_print_list(*a);//	----------------DEBUG
	//ft_print_rev_list(*a);//	----------------DEBUG
	//ft_print_list(*b);//	----------------DEBUG
	//ft_print_rev_list(*b);//	----------------DEBUG
}


// void	ft_least_moves(t_node **a, t_node **b)//	finds the least expensive move to sort and push elems from stack_b
// {
// 	t_node	*p;
// 	t_node	*q;
// 	int		last;
// 	int		mov;
// 	int		mov_tot;
// 	int		b_cont;

// 	q = *b;
// 	mov = 0;
// 	mov_tot = 0;
// 	b_cont = 0;
// 	while (q)
// 	{
// 		p = *a;
// 		last = 0;
// 		mov = q->moves;
// 		while (p )
// 		{
// 			if (!p->next)
// 			{
// 				last = 1;
// 				p = *a;
// 			}
// 			else
// 				p = p->next;
// 			if (q->content < p->content || last == 1)
// 			{
// 				if (mov_tot == 0 || mov_tot > mov + p->moves)
// 				{	
// 					mov_tot = mov + p->moves;//	q->moves + p->moves
// 					b_cont = q->content;
// 				}
// 				break ;
// 			}
// 		}
// 		if (!q->next)
// 			break ;
// 		q = q->next;
// 	}
// 	printf("num : %d\n", b_cont);
// 	ft_set_mov_flag(a, b, b_cont);
// }

void	ft_mcount(t_node **l, int stk, int midp)//	gets the amount of moves for stack_elems
{
	t_node	*head;
	t_node	*end;

	head = (*l);
	end = ft_lstlast(*l);
	if (stk == 2)
	{
		head->moves = 1;
		end->moves = 2;
	}
	else if (stk == 1)
	{
		head->moves = 0;
		end->moves = 1;
	}
	while (midp > 1)
	{
		head = head->next;
		end = end->prev;
		head->moves = head->prev->moves + 1;
		end->moves = end->next->moves + 1;
		if (head->next == end->prev)
			head->next->moves = end->moves;
		midp--;
	}
}

t_node	*ft_check_mid(t_node **stk)
{
	t_node	*p;
	int		count;

	ft_dst_init(stk);
	p = *stk;
	count = 0;
	while (p && p->flag != 1)
	{
		count++;
		if (p->next)
			p = p->next;
		else
			break ;
	}
	if (count < ft_lstsize(*stk) / 2)
		p->dist = 1;//	first half (ra/rb)
	else
		p->dist = 2;//	second half (ra/rb)
	puts("end of check mid");
	ft_print_list(*stk);
	ft_print_rev_list(*stk);
	return (p);
}

// function not sorting... stuck as soon as it has to rotate any stack towards any direction...
void	ft_sort_b(t_node **a, t_node **b, t_cmd **m)
{
	t_node	*p;
	t_node	*q;

	p = ft_check_mid(a);
	q = ft_check_mid(b);
	printf("p = %d\n", p->content);
	printf("q = %d\n", q->content);
	while (p->prev)
	{
		if (q->dist == p->dist && q->prev)
		{
			if (q->dist == 1)
			{
				ft_rotp(b, m, 0);
				ft_rotp(a, m, 3);//	rr
			}
			else if (q->dist == 2)
			{
				ft_revp(b, m, 0);
				ft_revp(a, m, 3);//	rrr
			}
		}
		else if (p->dist == 1)
			ft_rotp(a, m, 1);// ra
		else if (p->dist == 2)
			ft_revp(a, m, 1);// rra
	}
	puts("bidule");
	while (q->prev)
	{
		if (q->dist == 1)
			ft_rotp(b, m, 2);// rb
		else if (q->dist == 2)
			ft_revp(b, m, 2);// rrb
	}
	puts("lolo");
	ft_setprev(a);
	ft_setprev(b);
	//puts("end of sort b");
	//	ft_print_list(*a);//	----------------DEBUG
	//	ft_print_rev_list(*a);//	----------------DEBUG
	//	ft_print_list(*b);//	----------------DEBUG
	//	ft_print_rev_list(*b);//	----------------DEBUG
}

void	ft_fillmoves(t_node **a, t_node **b, t_cmd *m)//	A)
{
	t_node	*q;
	int		mid_a;
	int		mid_b;

	ft_setprev(a);
	ft_setprev(b);
	q = (*b);
	mid_a = (ft_lstsize(*a) / 2);
	mid_b = (ft_lstsize(*b) / 2);
	ft_mcount(a, 1, mid_a);
	ft_mcount(b, 2, mid_b);
	ft_least_moves(a, b);
	ft_sort_b(a, b, &m);//	<------------------------------------- I AM HERE!!!!
	ft_push_ap(a, &m, b);
	ft_print_cmd(m);//	----------------DEBUG
	ft_setprev(a);
	ft_setprev(b);
}

void	ft_commands(t_node **a, t_node **b, t_cmd **c)
{
	int		i;
	int		*aval;
	t_node	*p;
	int	debug = 5;

	i = 0;
	p = (*a);
	aval = malloc(sizeof(int) * ft_lstsize(*a));
	if (!aval)
		return ;
	aval = ft_lst_to_arr(*a, aval);
	*c = ft_max_subseq(aval, a, b, *c);
	while (*b)
	{
		if (debug-- == 0)
			exit (0);
		printf("*b : %p | %d\n", *b, (*b)->content);//	----------------DEBUG
		printf("*a : %p | %d\n", *a, (*a)->content);//	----------------DEBUG
		ft_flag_init(a);
		ft_flag_init(b);
		ft_fillmoves(a, b, *c);
		puts("outta fillmoves");
		ft_print_list(*a);//	----------------DEBUG
		ft_print_rev_list(*a);//	----------------DEBUG
		ft_print_list(*b);//	----------------DEBUG
		ft_print_rev_list(*b);//	----------------DEBUG
		//exit (0);//	----------------DEBUG
	}
	puts("so far so good_LAST");
	free (aval);
	ft_print_list((*a));//	----------------DEBUG
	puts("EOFT");
}

/*
**		FIND THE LEAST EXPENSIVE ELEMENT TO SORT :
**
**	A)
**	[V] first of all, determine where the stack (a & b) midpoint is (set this value into an int).
**	[V] in struct t_move, enter the stack pos of b_elem + 1 into moves;
**	[V] figure out a way to count moves for bottom half of both stacks.
**	[V] in stack_a, determine how many moves will occur to rotate until space to put b_elem is at top of the stack_a
**	[V]	for each b_elem, find the correct spot in stack_a and add up a_moves to b_moves.
**	[V] save this value into an int (moves)
**	[V] repeat for every element in stack_b. If (moves) is greater than t_move moves, replace (moves) with t_move moves.
**	[ ] at the end of the process, (moves) will store THE LEAST AMOUNT OF MOVES.
*/

//	DEBUG SEQ :
//	make re
//	./push_swap 61 49 19 11 31 22 4 51 12 47 9 38 34 94 92