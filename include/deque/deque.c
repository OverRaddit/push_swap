/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:16:22 by gshim             #+#    #+#             */
/*   Updated: 2022/02/08 21:54:02 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

t_deque		*deq_new(int n)
{
	t_deque *ret;

	ret = malloc(sizeof(t_deque));
	ret->size = 0;
	ret->content = malloc(sizeof(int) * n);
	ret->capacity = n;
	ret->front = 0;
	ret->back = 0;
	return (ret);
}

void		deq_extend(t_deque *deq)
{
	int *ret;
	int i;

	ret = malloc(sizeof(deq->size * 2));
	i = -1;
	while (++i)
		ret[i] = deq->content[i];
	free(deq->content);
	deq->content = ret;
	deq->capacity *= 2;
}

void		deq_clear(t_deque *deq)
{
	free(deq->content);
	free(deq);
}

void		deq_push_back(t_deque *deq, int n)
{
	int idx;

	if (deq->size == deq->capacity)
		deq_extend(deq);
	idx = deq->size;
	deq->content[idx] = n;
	if(deq->size == 0)
	{
		deq->front = deq->content;
		deq->back = deq->content;
	}
	deq->size++;
	//deq->back = deq->back + 1; -> 이거는 0으로 저장되던데 왜그러지?
	deq->back = &(deq->content[deq->size - 1]);
}

void		deq_push_front(t_deque *deq, int n)
{
	int i;

	if (deq->size == deq->capacity)
		deq_extend(deq);
	i = deq->size - 1;
	while(--i >= 0)
		deq->content[i] = deq->content[i-1];
	deq->content[0] = n;
	deq->size++;
	deq->back = deq->back + 1;
}

void		deq_pop_back(t_deque *deq)
{
	if(deq->size == 1)
	{
		deq->back = 0;
		deq->front = 0;
	}
	else
		deq->back = deq->back - 1;
	deq->size--;
}

void		deq_pop_front(t_deque *deq)
{
	int i;

	i = -1;
	if(deq->size == 1)
	{
		deq->back = 0;
		deq->front = 0;
	}
	else
		while(++i<deq->size)
			deq->content[i] = deq->content[i+1];
	deq->size--;
}

// pa = p(b, a);
// pb = p(a, b);
void		p(t_deque *src, t_deque *dest)
{
	int temp;

	temp = *(src->back);
	deq_pop_back(src);
	deq_push_back(dest, temp);
}

void		s(t_deque *A)
{
	int foo;
	int bar;

	foo = *(A->back);
	deq_pop_back(A);
	bar = *(A->back);
	deq_pop_back(A);

	deq_push_back(A, foo);
	deq_push_back(A, bar);
}
// front(아래) back위
// back -> front(맨위에서 아래로)
void		r(t_deque *A)
{
	int temp;
	int i;

	temp = *(A->back);
	i = A->size;
	while(--i > 0)
	{
		A->content[i] = A->content[i - 1];
	}
	A->content[0] = temp;
}

// front -> back(맨아래에서 위로)
void		rr(t_deque *A)
{
	int temp;
	int i;

	temp = *(A->front);
	i = 0;
	while(++i < A->size)
	{
		A->content[i - 1] = A->content[i];
	}
	*(A->back) = temp;
}
