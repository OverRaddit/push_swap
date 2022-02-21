/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:46:52 by gshim             #+#    #+#             */
/*   Updated: 2022/02/20 21:00:16 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "deque.h"

void	A_to_B_move(t_ps *ps, int size, int Spivot, int Lpivot, int *ra, int *rb)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (Lpivot < *(ps->A->back))
		{
			r(ps->A);
			ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("ra")));
			(*ra)++;
		}
		else
		{
			p(ps->A, ps->B);
			ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("pb")));
			if (Spivot < *(ps->B->back))
			{
				r(ps->B);
				ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("rb")));
				(*rb)++;
			}
		}
	}
}

void	B_to_A_move(t_ps *ps, int size, int Spivot, int Lpivot, int *ra, int *rb)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (Spivot >= *(ps->B->back))
		{
			r(ps->B);
			ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("rb")));
			(*rb)++;
		}
		else
		{
			p(ps->B, ps->A);
			ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("pa")));
			if (Lpivot >= *(ps->A->back))
			{
				r(ps->A);
				ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("ra")));
				(*ra)++;
			}
		}
	}
}

//-146 168 256 -972 135 -15 -657
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
