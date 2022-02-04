/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 21:09:08 by gshim             #+#    #+#             */
/*   Updated: 2022/02/04 20:51:59 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ps_init(t_ps *ps, int N)
{
	ps->A = deq_new(N - 1);
	ps->B = deq_new(N - 1);
	ps->pivot = 0;
	//ps->opcode = ft_lst
}

// A의 back에서부터 size개의 원소를 피벗값을 기준으로 나눈다.

void test(t_ps *ps){
	// sa
	s(ps->A);
	print_deque(ps->A);
	// sb

	// ss

	// pa

	// pb
	p(ps->A, ps->B);
	print_deque(ps->A);
	// ra
	r(ps->A);
	print_deque(ps->A);
	// rra

	// rb

	// rrb

	// rr
	rr(ps->A);
	print_deque(ps->A);
	// rrr
}

int	main(int argc, char *argv[]){
	int i;
	t_ps *ps;

	// 구조체 초기화
	ps = malloc(sizeof(t_ps)); // 예외처리
	ps_init(ps, argc - 1);

	//실행인자 a에 넣기(같은 숫자 거르는 예외처리 필요)
	i = 0;
	while(++i < argc)
		deq_push_back(ps->A, ft_atoi(argv[i]));

	// algorithm
	A_to_B(ps, ps->A->size);

	//test(ps);

	free(ps);
}