#include "push_swap.h"
#include "deque.h"

void	A_to_B(t_ps *ps, int size, int depth)
{
	int	count;
	int	pivot;
	int	i;

	count = 0;
	if (size == 2)
		twoA(ps, *(ps->A->back), *(ps->A->back - 1));
	if (size == 1 || isDescending(ps->A->content + ps->A->size - size, size))
		return ;
	pivot = getPivot(ps, ps->A->content + ps->A->size - size, size);

	// MOVE
	i = -1;
	while (++i < size)
	{
		if (pivot < *(ps->A->back))
		{
			r(ps->A);
			ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("ra")));
			count++;
		}
		else
		{
			p(ps->A, ps->B);
			ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("pb")));
		}
	}

	// REWIND
	i = -1;
	while (++i < count && depth != 0)
	{
		rr(ps->A);
		ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("rra")));
	}

	// RECURSION
	A_to_B(ps, count, depth + 1);
	B_to_A(ps, size - count, depth + 1);
}

void	B_to_A(t_ps *ps, int size, int depth)
{
	int	count;
	int	pivot;
	int	i;

	count = 0;
	if (size == 2)
		twoB(ps, *(ps->B->back), *(ps->B->back + 1));
	//현재 정렬이 되어있다면 리턴한다.
	if (size == 1 || isAscending(ps->B->content + ps->B->size - size, size))
	{
		i = -1;
		while(++i < size)
		{
			p(ps->B, ps->A);
			ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("pa")));
		}
		return;
	}

	pivot = getPivot(ps, ps->B->content + ps->B->size - size, size);
	i = -1;
	while(++i < size)
	{
		if(pivot >= *(ps->B->back))
		{
			r(ps->B);
			ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("rb")));
			count++;
		}
		else
		{
			p(ps->B, ps->A);
			ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("pa")));
		}
	}
	i = -1;
	while(++i < count && depth != 1){
		rr(ps->B);
		ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("rrb")));
	}
	A_to_B(ps, size - count, depth + 1);
	B_to_A(ps, count, depth + 1);
}

int	getPivot(t_ps *ps, int *arr, int size)
{
	int	*sort;
	int	ret;
	int	i;

	// 할당
	sort = malloc(sizeof(int) * size);
	//sort = malloc(size);
	if (!sort)
		terminate(ps);
	// 복사
	i = -1;
	while (++i < size)
		sort[i] = arr[i];
	// 버블소트
	bubblesort(sort, size);
	ret = sort[(size / 2) - (size % 2 == 0)];
	free(sort);
	return ret;
}

void	getPivot_extend(t_ps *ps, int *arr, int size, int *Spivot, int *Lpivot)
{
	int	*sort;
	int	i;

	sort = malloc(sizeof(int) * size);
	if (!sort)
		terminate(ps);
	i = -1;
	while (++i < size)
		sort[i] = arr[i];
	bubblesort(sort, size);
	*Spivot = sort[(size / 3) - (size % 3 == 0)];
	*Lpivot = sort[(size / 3) * 2 - (size % 3 == 0)];
	free(sort);
}

void	A_to_B_extend(t_ps *ps, int size, int depth)
{
	int	ra;
	int	rb;
	int	Spivot;
	int	Lpivot;
	int	i;

	if (depth == 0 && size == 3) threeA(ps, *(ps->A->back), *(ps->A->back - 1), *(ps->A->back - 2));
	if (size == 2)
		twoA(ps, *(ps->A->back), *(ps->A->back - 1));
	if (size == 1 || isDescending(ps->A->content + ps->A->size - size, size))
		return ;
	Spivot = 0;
	Lpivot = 0;
	getPivot_extend(ps, ps->A->content + ps->A->size - size, size, &Spivot, &Lpivot);
	i = -1;
	ra = 0;
	rb = 0;
	// [MOVE] 모든 A에 대해 A,B로 이동시키기.
	A_to_B_move(ps, size, Spivot, Lpivot, &ra, &rb);

	// [REWIND] 수행
	rewind(ps, ra, rb);

	// [RECURSION] 수행
	A_to_B_extend(ps, ra, depth + 1);
	B_to_A_extend(ps, rb, depth + 1);
	B_to_A_extend(ps, size - ra - rb, depth + 1);

}

void B_to_A_extend(t_ps *ps, int size, int depth)
{
	int	ra;
	int	rb;
	int	Spivot;
	int	Lpivot;
	int	i;

	if (size == 2)
		twoB(ps, *(ps->B->back), *(ps->B->back - 1));
	if (size == 1 || isAscending(ps->B->content + ps->B->size - size, size))
	{
		i = -1;
		while (++i < size){
			p(ps->B, ps->A);
			ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("pa")));
		}
		return;
	}
	Spivot = 0;
	Lpivot = 0;
	getPivot_extend(ps, ps->B->content + ps->B->size - size, size, &Spivot, &Lpivot);
	i = -1;
	rb = 0;
	ra = 0;
	// [MOVE] 모든 B에 대해 A,B로 이동시키기.
	B_to_A_move(ps, size, Spivot, Lpivot, &ra, &rb);
	A_to_B_extend(ps, size - ra - rb, depth + 1);
	// [REWIND] 수행
	rewind(ps, ra, rb);
	// [RECURSION] 수행
	A_to_B_extend(ps, ra, depth + 1);
	B_to_A_extend(ps, rb, depth + 1);
}


/*
command

ARG="2 1 0"; ./push_swap $ARG | wc -l
ARG="1 5 2 4 3"; ./push_swap $ARG | ./checker_OS $ARG

*/
