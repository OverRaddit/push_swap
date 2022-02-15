/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 21:09:08 by gshim             #+#    #+#             */
/*   Updated: 2022/02/15 13:59:55 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ps_init(t_ps *ps)
{
	// N-1 x
	ps->A = deq_new(10);
	ps->B = deq_new(10);
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

	// flatten
	t_list *lst = ps->opcode;
	ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("ra")));
	ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("rb")));
	ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("sa")));
	ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("rb")));
	printf("Flatten BEFORE");
	while(lst){
		printf("%s \n", (char*)lst->content);
		lst = lst->next;
	}
	flatten_opcode(ps->opcode);
	printf("Flatten AFTER");

	lst = ps->opcode;
	while(lst){
		printf("%s \n", (char*)lst->content);
		lst = lst->next;
	}
}

void replace_opcode(t_list *lst, char opcode[5])
{
	t_list *next;

	// 새로운 명령어 넣기
	free(lst->content);
	lst->content = ft_strdup(opcode);

	// 뒷 노드의 다음노드를 앞노드의 다음노드로 넣을 것이다.
	next = lst->next->next;
	ft_lstdelone(lst->next, free);
	lst->next = next;
}

void flatten_opcode(t_list *lst)
{
	while(lst->next)
	{
		if (!ft_strncmp(lst->content, "ra", 2) && !ft_strncmp(lst->next->content, "rb", 2))
			replace_opcode(lst, "rr");
		if (!ft_strncmp(lst->content, "rb", 2) && !ft_strncmp(lst->next->content, "ra", 2))
			replace_opcode(lst, "rr");

		if (!ft_strncmp(lst->content, "sa", 2) && !ft_strncmp(lst->next->content, "sb", 2))
			replace_opcode(lst, "rr");
		if (!ft_strncmp(lst->content, "sb", 2) && !ft_strncmp(lst->next->content, "sa", 2))
			replace_opcode(lst, "rr");

		if (!ft_strncmp(lst->content, "rra", 3) && !ft_strncmp(lst->next->content, "rrb", 3))
			replace_opcode(lst, "rrr");
		if (!ft_strncmp(lst->content, "rrb", 3) && !ft_strncmp(lst->next->content, "rra", 3))
			replace_opcode(lst, "rrr");

		lst = lst->next;
	}
}

int terminate(t_ps *ps)
{
	deq_clear(ps->A);
	//printf("A스택을 free합니다.\n");
	deq_clear(ps->B);
	//printf("B스택을 free합니다.\n");
	ft_lstclear(&(ps->opcode), free);
	//printf("opcode free합니다.\n");

	exit(1);
}

int	main(int argc, char *argv[]){
	int i;
	t_ps *ps;

	ps = malloc(sizeof(t_ps)); // 예외처리
	ps_init(ps);

	// INPUT
	i = 0;
	while(++i < argc)
		input(ps, argv[i]);
	deq_reverse(ps->A);

	// printf("MAIN\n");
	// test(ps);
	// print_deque(ps->A);
	// printf("%d \n", ps->A->capacity);
	// printf("%d \n", ps->A->size);

	//algorithm
	A_to_B(ps, ps->A->size);

	// t_list *lst = ps->opcode->next;
	// flatten_opcode(ps->opcode);
	// i = 1;
	// while (lst)
	// {
	// 	printf("%s\n", (char *)lst->content);
	// 	lst = lst->next;
	// 	i++;
	// }
	// terminate(ps);
}
