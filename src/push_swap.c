#include "push_swap.h"
#include "deque.h"

void	getPivot_extend(t_ps *ps, int *arr, int size, t_info *info)
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
	info->Spivot = sort[(size / 3) - (size % 3 == 0)];
	info->Lpivot = sort[(size / 3) * 2 - (size % 3 == 0)];
	free(sort);
}

void	A_to_B_extend(t_ps *ps, int size)
{
	t_info info;

	// [BASE CASE]
	if (A_to_B_base(ps, size))
		return ;
	// [MOVE] 모든 A에 대해 A,B로 이동시키기.
	getPivot_extend(ps, ps->A->content + ps->A->size - size, size, &info);
	info.ra = 0;
	info.rb = 0;
	A_to_B_move(ps, size, &info);

	// [REWIND] 수행
	rewind(ps, info.ra, info.rb);

	// [RECURSION] 수행
	A_to_B_extend(ps, info.ra);
	B_to_A_extend(ps, info.rb);
	B_to_A_extend(ps, size - info.ra - info.rb);
}

void B_to_A_extend(t_ps *ps, int size)
{
	t_info info;

	// [BASE CASE]
	if (B_to_A_base(ps, size))
		return ;
	// [MOVE] 모든 B에 대해 A,B로 이동시키기.
	getPivot_extend(ps, ps->B->content + ps->B->size - size, size, &info);
	info.ra = 0;
	info.rb = 0;
	B_to_A_move(ps, size, &info);
	A_to_B_extend(ps, size - info.ra - info.rb);
	// [REWIND] 수행
	rewind(ps, info.ra, info.rb);
	// [RECURSION] 수행
	A_to_B_extend(ps, info.ra);
	B_to_A_extend(ps, info.rb);
}
/*
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

int		getPivot(t_ps *ps, int *arr, int size)
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
*/

/*
command

ARG="2 1 0"; ./push_swap $ARG | wc -l
ARG="1 5 2 4 3"; ./push_swap $ARG | ./checker_OS $ARG

*/
