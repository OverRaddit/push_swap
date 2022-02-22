/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:16:22 by gshim             #+#    #+#             */
/*   Updated: 2022/02/22 13:10:05 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

t_deque	*deq_new(int n)
{
	t_deque	*ret;

	ret = malloc(sizeof(t_deque));
	if (!ret)
		return 0;
	ret->size = 0;
	ret->content = malloc(sizeof(int) * n);
	if (!(ret->content))
	{
		free(ret);
		return (0);
	}
	ret->capacity = n;
	ret->front = ret->content;
	ret->back = ret->content;
	return (ret);
}

void	deq_extend(t_deque *deq)
{
	int	*ret;
	int	i;

	ret = malloc(sizeof(int) * deq->capacity * 2);
	if (!ret)
		exit(1);
	i = -1;
	while (++i < deq->size)
		ret[i] = deq->content[i];
	free(deq->content);
	deq->content = ret;
	deq->front = deq->content;
	deq->back = &(deq->content[deq->size - 1]);
	deq->capacity *= 2;
}

void	deq_clear(t_deque *deq)
{
	free(deq->content);
	free(deq);
}

void	deq_reverse(t_deque *deq)
{
	int	i;
	int	temp;

	i = -1;
	while (++i < deq->size / 2)
	{
		temp = deq->content[i];
		deq->content[i] = deq->content[deq->size - 1 - i];
		deq->content[deq->size - 1 - i] = temp;
	}
}
