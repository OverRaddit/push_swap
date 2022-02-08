/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:29:39 by gshim             #+#    #+#             */
/*   Updated: 2022/02/08 14:06:59 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void minimum_sort(t_ps *ps, int n, char deq)
{
	int a;
	int b;
	int c;
	t_deque *deq;

	deq =
	if (n == 2)
		two(ps, *(ps->A->back, *(ps->A->back + 1);
	else if (n == 3)
		three(ps, *(ps->A->back), *(ps->A->back + 1), *(ps->A->back + 2));

}

void two(t_ps *ps, int a, int b)
{
	if (a > b)
	{
		s(ps->A);
		ft_lstadd_back(&ps->opcode, ft_lstnew("a" + "sA"));
	}
}

void three(t_ps *ps, int a, int b, int c)
{
	if(a < b && b > c && a < c)
	{
		s(ps->A);
		ft_lstadd_back(&ps->opcode, ft_lstnew("sA"));
		r(ps->A);
		ft_lstadd_back(&ps->opcode, ft_lstnew("rA"));
	}
	else if(a > b && b < c && a < c)
	{
		s(ps->A);
		ft_lstadd_back(&ps->opcode, ft_lstnew("pA"));
	}
	else if(a < b && b > c && a > c)
	{
		rr(ps->A);
		ft_lstadd_back(&ps->opcode, ft_lstnew("rrA"));
	}
	else if(a > b && b < c && a > c)
	{
		r(ps->A);
		ft_lstadd_back(&ps->opcode, ft_lstnew("rA"));
	}
	else if(a > b && b > c && a > c)
	{
		s(ps->A);
		ft_lstadd_back(&ps->opcode, ft_lstnew("sA"));
		rr(ps->A);
		ft_lstadd_back(&ps->opcode, ft_lstnew("rrA"));
	}

}
