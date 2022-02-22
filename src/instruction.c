/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:22:39 by gshim             #+#    #+#             */
/*   Updated: 2022/02/21 16:22:54 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

// pa = p(b, a);
// pb = p(a, b);
void	p(t_deque *src, t_deque *dest)
{
	int	temp;

	temp = *(src->back);
	deq_pop_back(src);
	deq_push_back(dest, temp);
}

void	s(t_deque *A)
{
	int	foo;
	int	bar;

	foo = *(A->back);
	deq_pop_back(A);
	bar = *(A->back);
	deq_pop_back(A);
	deq_push_back(A, foo);
	deq_push_back(A, bar);
}

void	r(t_deque *A)
{
	int	temp;
	int	i;

	temp = *(A->back);
	i = A->size;
	while (--i > 0)
	{
		A->content[i] = A->content[i - 1];
	}
	A->content[0] = temp;
}

void	rr(t_deque *A)
{
	int	temp;
	int	i;

	temp = *(A->front);
	i = 0;
	while (++i < A->size)
	{
		A->content[i - 1] = A->content[i];
	}
	*(A->back) = temp;
}
