/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:37:11 by gshim             #+#    #+#             */
/*   Updated: 2022/02/22 15:15:42 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../include/libft/libft.h"
# include "deque.h"

typedef struct s_ps
{
	t_deque	*A;
	t_deque	*B;
	t_list	*opcode;
}	t_ps;

typedef struct s_info
{
	int Spivot;
	int Lpivot;
	int ra;
	int rb;
}	t_info;

// push_swap.c
void	A_to_B(t_ps *ps, int size);
void	B_to_A(t_ps *ps, int size);
int		getPivot(t_ps *ps, int *arr, int size);
void	getPivot_extend(t_ps *ps, int *arr, int size, t_info *info);
void	A_to_B_extend(t_ps *ps, int size);
void	B_to_A_extend(t_ps *ps, int size);

// push_swap2.c
void	A_to_B_move(t_ps *ps, int size, t_info *info);
void	B_to_A_move(t_ps *ps, int size, t_info *info);
void	rewind(t_ps *ps, int ra, int rb);
int		A_to_B_base(t_ps *ps, int size);
int		B_to_A_base(t_ps *ps, int size);

// sort.c
void	bubblesort(int *arr, int size);
int		isAscending(int *arr, int size);
int		isDescending(int *arr, int size);
void	twoA(t_ps *ps, int a, int b);
void	twoB(t_ps *ps, int a, int b);
void	minimum_sort(t_ps *ps, int n, char c);
void	threeA(t_ps *ps, int a, int b, int c);
void	threeB(t_ps *ps, int a, int b, int c);

// input.c
int		is_duplicate(t_ps *ps, int *arr, int size);
int		input(t_ps *ps, char *argv);

// main.c
int		terminate(t_ps *ps);
void	replace_opcode(t_list *lst, char opcode[5]);
void	flatten_opcode(t_list *lst);

#endif
