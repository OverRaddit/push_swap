
#include "push_swap.h"
#include "deque.h"

void print_deque(t_deque *src){
	printf("===========================\n");
	for(int i=0;i<src->size;i++)
		printf("%d ",src->content[i]);
	printf("\n");
	printf("===========================\n");
	printf("\n");
}

t_list	*my_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = 0;
	return (new);
}

void A_to_B(t_ps *ps, int size, int depth)
{
	int count;
	int pivot;
	int i;

	count = 0;
	// if(ps->A->size == 3 && size == 3)
	// 	threeA(ps, *(ps->A->back), *(ps->A->back + 1), *(ps->A->back + 2));
	if(size == 2)
	{
		//three(ps, *(ps->A->back), *(ps->A->back + 1), *(ps->A->back + 2));
		twoA(ps, *(ps->A->back), *(ps->A->back - 1));
	}

	//현재 정렬이 되어있다면 리턴한다.
	if (size == 1 || isDescending(ps->A->content + ps->A->size - size, size)){
		return ;
	}

	pivot = getPivot(ps, ps->A->content + ps->A->size - size, size);

	printf("A_to_B depth %d\n", depth);

	// size개에 대하여 B로 옮기거나 A에서 회전시킨다.
	i = -1;
	while(++i < size)
	{
		// 피벗 초과값들은 현재스택에서 뒤로 넘긴다.
		if(pivot < *(ps->A->back))	// 피벗 초과 ->남김, 피벗이하 -> 이사
		{
			r(ps->A);
			ft_lstadd_back(&ps->opcode, my_lstnew(ft_strdup("ra")));
			count++;
		}
		// 피벗 이하값들은 반대스택으로 넘긴다.
		else{
			p(ps->A, ps->B);
			ft_lstadd_back(&ps->opcode, my_lstnew(ft_strdup("pb")));
		}
	}

	// REWIND
	i = -1;
	while(++i < count && depth != 0){
		rr(ps->A);
		ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("rra")));
	}

	// 디버깅
	// print_deque(ps->A);
	// print_deque(ps->B);

	// 재귀
	A_to_B(ps, count, depth + 1);
	B_to_A(ps, size - count, depth + 1);
}

void B_to_A(t_ps *ps, int size, int depth)
{
	int count;
	int pivot;
	int i;

	count = 0;
	if(size == 2)
	{
		//three(ps, ps->B->content[2], ps->B->content[1], ps->B->content[0]);
		twoB(ps, *(ps->B->back), *(ps->B->back + 1));
	}
	//현재 정렬이 되어있다면 리턴한다.
	if (size == 1 || isAscending(ps->B->content + ps->B->size - size, size))
	{
		i = -1;
		while(++i < size){
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
		else{
			p(ps->B, ps->A);
			ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("pa")));
		}
	}
	i = -1;
	while(++i < count && depth != 1){
		rr(ps->B);
		ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("rrb")));
	}

	// 디버깅
	// print_deque(ps->A);
	// print_deque(ps->B);

	A_to_B(ps, size - count, depth + 1);
	B_to_A(ps, count, depth + 1);
}


int getPivot(t_ps *ps, int *arr, int size)
{
	int *sort;
	int ret;
	int i;

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


/*
command

ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG

*/
