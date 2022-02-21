/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 21:09:08 by gshim             #+#    #+#             */
/*   Updated: 2022/02/20 18:32:57 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "deque.h"

void	ps_init(t_ps *ps)
{
	ps->A = deq_new(10);
	ps->B = deq_new(10);
	ps->opcode = ft_lstnew(ft_strdup("Head"));
}

void	replace_opcode(t_list *lst, char opcode[5])
{
	t_list	*next;

	// 새로운 명령어 넣기
	free(lst->content);
	lst->content = ft_strdup(opcode);
	// 뒷 노드의 다음노드를 앞노드의 다음노드로 넣을 것이다.
	next = lst->next->next;
	ft_lstdelone(lst->next, free);
	lst->next = next;
}

void	flatten_opcode(t_list *lst)
{
	while (lst->next)
	{
		if (!ft_strncmp(lst->content, "ra", 2)
			&& !ft_strncmp(lst->next->content, "rb", 2))
			replace_opcode(lst, "rr");
		if (!ft_strncmp(lst->content, "rb", 2)
			&& !ft_strncmp(lst->next->content, "ra", 2))
			replace_opcode(lst, "rr");
		if (!ft_strncmp(lst->content, "sa", 2)
			&& !ft_strncmp(lst->next->content, "sb", 2))
			replace_opcode(lst, "ss");
		if (!ft_strncmp(lst->content, "sb", 2)
			&& !ft_strncmp(lst->next->content, "sa", 2))
			replace_opcode(lst, "ss");
		if (!ft_strncmp(lst->content, "rra", 3)
			&& !ft_strncmp(lst->next->content, "rrb", 3))
			replace_opcode(lst, "rrr");
		if (!ft_strncmp(lst->content, "rrb", 3)
			&& !ft_strncmp(lst->next->content, "rra", 3))
			replace_opcode(lst, "rrr");
		lst = lst->next;
	}
}

int	terminate(t_ps *ps)
{
	deq_clear(ps->A);
	deq_clear(ps->B);
	ft_lstclear(&(ps->opcode), free);
	exit(1);
}

int	main(int argc, char *argv[])
{
	int		i;
	t_ps	*ps;
	t_list	*lst;

	ps = (t_ps *)malloc(sizeof(t_ps)); // 예외처리
	ps_init(ps);
	// INPUT
	i = 0;
	while (++i < argc)
		input(ps, argv[i]);
	deq_reverse(ps->A);
	//algorithm
	A_to_B_extend(ps, ps->A->size, 0);
	// flatten
	lst = ps->opcode->next;
	flatten_opcode(ps->opcode);
	i = 1;
	while (lst)
	{
		ft_putstr_fd((char *)lst->content, 1);
		ft_putstr_fd("\n", 1);
		lst = lst->next;
		i++;
	}
	terminate(ps);
}
/*
ARG="1 2 3 4"; ./push_swap $ARG | ./checker_MAC $ARG

*/
