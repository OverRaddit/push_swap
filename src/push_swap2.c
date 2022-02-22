/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:46:52 by gshim             #+#    #+#             */
/*   Updated: 2022/02/21 17:41:12 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "deque.h"

void	A_to_B_move(t_ps *ps, int size, t_info *info)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (info->Lpivot < *(ps->A->back))
		{
			r(ps->A);
			ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("ra")));
			(info->ra)++;
		}
		else
		{
			p(ps->A, ps->B);
			ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("pb")));
			if (info->Spivot < *(ps->B->back))
			{
				r(ps->B);
				ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("rb")));
				(info->rb)++;
			}
		}
	}
}

void	B_to_A_move(t_ps *ps, int size, t_info *info)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (info->Spivot >= *(ps->B->back))
		{
			r(ps->B);
			ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("rb")));
			(info->rb)++;
		}
		else
		{
			p(ps->B, ps->A);
			ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("pa")));
			if (info->Lpivot >= *(ps->A->back))
			{
				r(ps->A);
				ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("ra")));
				(info->ra)++;
			}
		}
	}
}

void	rewind(t_ps *ps, int ra, int rb)
{
	int	i;

	i = 0;
	while (i < ra && i < rb && (ra != ps->A->size) && (rb != ps->B->size))
	{
		rr(ps->A);
		rr(ps->B);
		ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("rrr")));
		i++;
	}
	while (i < ra || i < rb)
	{
		if (i < ra && (ra != ps->A->size))
		{
			rr(ps->A);
			ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("rra")));
		}
		if (i < rb && (rb != ps->B->size))
		{
			rr(ps->B);
			ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("rrb")));
		}
		i++;
	}
}

int	A_to_B_base(t_ps *ps, int size)
{
	if (ps->A->size == 3 && size == 3)
		threeA(ps, *(ps->A->back), *(ps->A->back - 1), *(ps->A->back - 2));
	if (size == 2)
		twoA(ps, *(ps->A->back), *(ps->A->back - 1));
	if (size == 1 || isDescending(ps->A->content + ps->A->size - size, size))
		return (1);
	return (0);
}

int	B_to_A_base(t_ps *ps, int size)
{
	int	i;

	if (ps->B->size == 3 && size == 3)
		threeB(ps, *(ps->B->back), *(ps->B->back - 1), *(ps->B->back - 2));
	if (size == 2)
		twoB(ps, *(ps->B->back), *(ps->B->back - 1));
	if (size == 1 || isAscending(ps->B->content + ps->B->size - size, size))
	{
		i = -1;
		while (++i < size)
		{
			p(ps->B, ps->A);
			ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("pa")));
		}
		return (1);
	}
	return (0);
}
