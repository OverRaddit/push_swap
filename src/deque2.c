/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:20:54 by gshim             #+#    #+#             */
/*   Updated: 2022/02/21 16:21:18 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

void	deq_push_back(t_deque *deq, int n)
{
	int	idx;

	if (deq->size == deq->capacity)
		deq_extend(deq);
	idx = deq->size;
	deq->content[idx] = n;
	if (deq->size == 0)
	{
		deq->front = deq->content;
		deq->back = deq->content;
	}
	deq->size++;
	deq->back = &(deq->content[deq->size - 1]);
}

void	deq_push_front(t_deque *deq, int n)
{
	int	i;

	if (deq->size == deq->capacity)
		deq_extend(deq);
	i = deq->size;
	while (--i >= 0)
		deq->content[i + 1] = deq->content[i];
	deq->content[0] = n;
	deq->size++;
	deq->back = deq->back + 1;
}

void	deq_pop_back(t_deque *deq)
{
	if (deq->size == 1)
	{
		deq->back = 0;
		deq->front = 0;
	}
	else
		deq->back = &(deq->content[deq->size - 2]);
	deq->size--;
}

void	deq_pop_front(t_deque *deq)
{
	int	i;

	i = -1;
	if (deq->size == 1)
	{
		deq->back = 0;
		deq->front = 0;
	}
	else
		while (++i < deq->size)
			deq->content[i] = deq->content[i + 1];
	deq->size--;
}
