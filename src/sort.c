/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:29:39 by gshim             #+#    #+#             */
/*   Updated: 2022/02/09 21:04:10 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void bubblesort(int *arr, int size)
{
	int i;
	int j;
	int temp;

	i = -1;
	while(++i < size - 1)
	{
		j = -1;
		while(++j < size - 1 - i)
			if(arr[j] > arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
	}
}

int isAscending(int *arr, int size)
{
	int i;

	i = -1;
	while(++i < size - 1)
	{
		if (arr[i] > arr[i + 1])
			return 0;
	}
	return 1;
}

int isDescending(int *arr, int size)
{
	int i;

	i = -1;
	while(++i < size - 1)
	{
		if (arr[i] < arr[i + 1])
			return 0;
	}
	return 1;
}

void minimum_sort(t_ps *ps, int n, char c)
{
	if (c == 'A'){
		if (n == 2)
			twoA(ps, *(ps->A->back), *(ps->A->back + 1));
		// else if (n == 3)
		// 	threeA(ps, *(ps->A->back), *(ps->A->back + 1), *(ps->A->back + 2));
	}
	else if (c == 'B'){
		if (n == 2)
			twoB(ps, *(ps->B->back), *(ps->B->back + 1));
		// else if (n == 3)
		// 	threeB(ps, *(ps->B->back), *(ps->B->back + 1), *(ps->B->back + 2));
	}
}

void twoA(t_ps *ps, int a, int b)
{
	if (a > b)
	{
		s(ps->A);
		ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("sA")));
	}
}

void twoB(t_ps *ps, int a, int b)
{
	if (a < b)
	{
		s(ps->B);
		ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("sB")));
	}
}

void threeA(t_ps *ps, int a, int b, int c)
{
	if(a < b && b > c && a < c)
	{
		s(ps->A);
		ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("sA")));
		r(ps->A);
		ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("rA")));
	}
	else if(a > b && b < c && a < c)
	{
		s(ps->A);
		ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("pA")));
	}
	else if(a < b && b > c && a > c)
	{
		rr(ps->A);
		ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("rrA")));
	}
	else if(a > b && b < c && a > c)
	{
		r(ps->A);
		ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("rA")));
	}
	else if(a > b && b > c && a > c)
	{
		s(ps->A);
		ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("sA")));
		rr(ps->A);
		ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("rrA")));
	}
}

// void threeB(t_ps *ps, int a, int b, int c)
