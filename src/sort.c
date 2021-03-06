/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:29:39 by gshim             #+#    #+#             */
/*   Updated: 2022/02/21 17:08:38 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "deque.h"

void	bubblesort(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = -1;
	while (++i < size - 1)
	{
		j = -1;
		while (++j < size - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int	isAscending(int *arr, int size)
{
	int	i;

	i = -1;
	while (++i < size - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
	}
	return (1);
}

int	isDescending(int *arr, int size)
{
	int	i;

	i = -1;
	while (++i < size - 1)
	{
		if (arr[i] < arr[i + 1])
			return (0);
	}
	return (1);
}

void	twoA(t_ps *ps, int a, int b)
{
	if (a > b)
	{
		s(ps->A);
		ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("sa")));
	}
}

void	twoB(t_ps *ps, int a, int b)
{
	if (a < b)
	{
		s(ps->B);
		ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("sb")));
	}
}

void	threeA(t_ps *ps, int a, int b, int c)
{
	if (a < b && b > c && a < c)
	{
		s(ps->A);
		ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("sa")));
		r(ps->A);
		ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("ra")));
	}
	else if (a > b && b < c && a < c)
	{
		s(ps->A);
		ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("sa")));
	}
	else if (a < b && b > c && a > c)
	{
		rr(ps->A);
		ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("rra")));
	}
	else if (a > b && b < c && a > c)
	{
		r(ps->A);
		ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("ra")));
	}
	else if (a > b && b > c && a > c)
	{
		s(ps->A);
		ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("sa")));
		rr(ps->A);
		ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("rra")));
	}
}

void threeB(t_ps *ps, int a, int b, int c)	// top 3 2 1 bottom
{
	if (a < b && b < c && a < c)	// 1 2 3
	{
		s(ps->B);
		ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("sb")));
		rr(ps->B);
		ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("rrb")));
	}
	else if (a < b && b > c && a < c)	// 1 3 2
	{
		r(ps->B);
		ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("rb")));
	}
	else if (a > b && b < c && a < c)	// 2 1 3
	{
		rr(ps->B);
		ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("rrb")));
	}
	else if (a < b && b > c && a > c)	// 2 3 1
	{
		s(ps->B);
		ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("sb")));
	}
	else if (a > b && b < c && a > c)	// 3 1 2
	{
		s(ps->B);
		ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("sb")));
		r(ps->B);
		ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("rb")));
	}
}
