/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:29:39 by gshim             #+#    #+#             */
/*   Updated: 2022/02/15 15:47:20 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "deque.h"

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
		ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("sa")));
	}
}

void twoB(t_ps *ps, int a, int b)
{
	if (a < b)
	{
		s(ps->B);
		ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("sb")));
	}
}

void threeA(t_ps *ps, int a, int b, int c)
{
	if(a < b && b > c && a < c)
	{
		s(ps->A);
		ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("sa")));
		r(ps->A);
		ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("ra")));
	}
	else if(a > b && b < c && a < c)
	{
		s(ps->A);
		ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("pa")));
	}
	else if(a < b && b > c && a > c)
	{
		rr(ps->A);
		ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("rra")));
	}
	else if(a > b && b < c && a > c)
	{
		r(ps->A);
		ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("ra")));
	}
	else if(a > b && b > c && a > c)
	{
		s(ps->A);
		ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("sa")));
		rr(ps->A);
		ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("rra")));
	}
}

// void threeB(t_ps *ps, int a, int b, int c)
