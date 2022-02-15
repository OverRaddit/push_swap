
#include "push_swap.h"

void print_deque(t_deque *src){
	printf("===========================\n");
	for(int i=0;i<src->size;i++)
		printf("%d ",src->content[i]);
	printf("\n");
	printf("===========================\n");
	printf("\n");
}


void A_to_B(t_ps *ps, int size)
{
	int count;
	int temp;
	int pivot;
	int i;

	count = 0;
	// if(ps->A->size == 3 && size == 3)
	// 	threeA(ps, *(ps->A->back), *(ps->A->back + 1), *(ps->A->back + 2));
	if(size == 2)
	{
		//three(ps, *(ps->A->back), *(ps->A->back + 1), *(ps->A->back + 2));
		twoA(ps, *(ps->A->back), *(ps->A->back + 1));
	}

	//현재 정렬이 되어있다면 리턴한다.
	if (size == 1 || isDescending(ps->A->content + ps->A->size - size, size)){
		return ;
	}

	// 새로운 피벗값을 잡는다.
	print_deque(ps->A);
	pivot = getPivot(ps, ps->A->content + ps->A->size - size, size);

	// printf("After pivot\n");
	// print_deque(ps->A);
	// printf("%d \n", ps->A->capacity);
	// printf("%d \n", ps->A->size);
	// debug
		p(ps->A, ps->B);
	// debug
	print_deque(ps->A);
	printf("%d \n", ps->A->capacity);
	printf("%d \n", ps->A->size);


	// size개에 대하여 B로 옮기거나 A에서 회전시킨다.
	i = -1;
	while(++i < size)
	{
		if(pivot < *(ps->A->back))	// 피벗 초과 ->남김, 피벗이하 -> 이사
		{
			r(ps->A);
			ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("ra"))); // 연산자 우선순위 -> > &
			count++;
		}
		else{
			p(ps->A, ps->B);
			ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("pb"))); // 연산자 우선순위 -> > &
		}
	}

	temp = count;
	// DEPTH = 0일때 RRA는 필요없음.
	while(count-- && ps->A->size+ps->B->size != size){
		rr(ps->A);
		ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("rra")));
	}

	// 디버깅
	print_deque(ps->A);
	print_deque(ps->B);

	// 재귀
	A_to_B(ps, temp);
	B_to_A(ps, size - temp);
}

void B_to_A(t_ps *ps, int size)
{
	int count;
	int temp;
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
	temp = count;
	while(count--){
		rr(ps->B);
		ft_lstadd_back(&ps->opcode, ft_lstnew(ft_strdup("rrb")));
	}

	// 디버깅
	print_deque(ps->A);
	print_deque(ps->B);

	A_to_B(ps, size - temp);
	B_to_A(ps, temp);
}


int getPivot(t_ps *ps, int *arr, int size)
{
	int *sort;
	int ret;
	int i;

	// 할당
	sort = malloc(size);
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
