/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 21:09:08 by gshim             #+#    #+#             */
/*   Updated: 2022/02/08 21:57:40 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ps_init(t_ps *ps)
{
	// N-1 x
	ps->A = deq_new(1);
	ps->B = deq_new(1);
	ps->pivot = 0;
	ps->opcode = ft_lstnew(ft_strdup("Head"));
}

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
	//int j;
	t_ps *ps;
	int ret;
	//char **temp;

	ps = malloc(sizeof(t_ps)); // 예외처리
	ps_init(ps);
	// temp = malloc(sizeof(char*) * (argc-1));
	// i = 0;
	// while(++i < argc)
	// {
	// 	temp = ft_split(argv[i], ' ');
	// 	j = -1;
	// 	while(temp[++j])
	// 		(ps->size)++;
	// 	free(temp);
	// }
	// free(temp);
	// printf("size: %d\n", ps->size);


	// INPUT
	i = 0;
	while(++i < argc)
	{
		ret = input(ps, argv[i]);
		if (ret == -1)
			return (-1);
	}
	print_deque(ps->A);

	// algorithm
	A_to_B(ps, ps->A->size);

	// 디버깅
	print_deque(ps->A);
	print_deque(ps->B);
	t_list *lst = ps->opcode;
	i = 1;
	while (lst)
	{
		printf("%s\n", (char *)lst->content);
		lst = lst->next;
		i++;
	}
	printf("%d struction\n", i);

	terminate(ps);
}
