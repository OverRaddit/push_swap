/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 11:56:10 by gshim             #+#    #+#             */
/*   Updated: 2022/02/21 16:30:40 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_H
# define DEQUE_H

# include <stddef.h>	// need?
# include <stdlib.h>
# include <unistd.h>

typedef struct s_deque
{
	int			*content;
	int			size;
	int			capacity;
	int			*front;
	int			*back;
}	t_deque;

// deque.c
t_deque		*deq_new(int n);
void		deq_extend(t_deque *deq);
void		deq_clear(t_deque *deq);
void		deq_reverse(t_deque *deq);

// deque2.c
void		deq_push_back(t_deque *deq, int n);
void		deq_push_front(t_deque *deq, int n);
void		deq_pop_back(t_deque *deq);
void		deq_pop_front(t_deque *deq);

// instruction.c
void		p(t_deque *src, t_deque *dest);
void		s(t_deque *A);
void		r(t_deque *A);
void		rr(t_deque *A);

#endif
