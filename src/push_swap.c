
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
	// 현재 옮겨야 될 원소의 수가 3이하.
	if(size <= 3)
	{
		three(ps, *(ps->A->back), *(ps->A->back + 1), *(ps->A->back + 2));
		return ;
	}

	//현재 정렬이 되어있다면 리턴한다.
	if (size == 1 || isDescending(ps->A->content + ps->A->size - size, size)){
		return ;
	}


	// if (size == 1)
	// 	return ;

	// 새로운 피벗값을 잡는다.
	pivot = getPivot(ps, ps->A->content + ps->A->size - size, size);
	printf("A's pivot : %d \n", pivot);
	// size개에 대하여 B로 옮기거나 A에서 회전시킨다.
	i = -1;
	while(++i < size)
	{
		if(pivot < *(ps->A->back))	// 피벗 초과 ->남김, 피벗이하 -> 이사
		{
			r(ps->A);
			ft_lstadd_back(&ps->opcode, ft_lstnew("rA")); // 연산자 우선순위 -> > &
			count++;
		}
		else{
			p(ps->A, ps->B);
			ft_lstadd_back(&ps->opcode, ft_lstnew("pB")); // 연산자 우선순위 -> > &
		}
	}
	temp = count;
	while(count--)
		rr(ps->A);

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
	// if(size <= 3)
	// {
	// 	three(ps, ps->B->content[2], ps->B->content[1], ps->B->content[0]);
	// 	return ;
	// }
	// 현재 정렬이 되어있다면 리턴한다.
	if (size == 1 || isAscending(ps->B->content + ps->B->size - size, size))
	{
		i = -1;
		while(++i < size){
			p(ps->B, ps->A);
			ft_lstadd_back(&ps->opcode, ft_lstnew("pA"));
		}
		return;
	}

	// if (size == 1)
	// {
	// 	p(ps->B, ps->A);
	// 	ft_lstadd_back(&ps->opcode, ft_lstnew("pA"));
	// 	return ;
	// }

	pivot = getPivot(ps, ps->B->content + ps->B->size - size, size);
	printf("B's pivot : %d \n", pivot);
	i = -1;
	while(++i < size)
	{
		if(pivot >= *(ps->B->back))
		{
			r(ps->B);
			ft_lstadd_back(&ps->opcode, ft_lstnew("rB"));
			count++;
		}
		else{
			p(ps->B, ps->A);
			ft_lstadd_back(&ps->opcode, ft_lstnew("pA"));
		}
	}
	temp = count;
	while(count--)
		rr(ps->B);

	// 디버깅
	print_deque(ps->A);
	print_deque(ps->B);

	A_to_B(ps, size - temp);
	B_to_A(ps, temp);
}


int getPivot(t_ps *ps, int *arr, int size)
{
	int i;
	int j;
	int temp;
	int *sort;

	// 할당
	sort = malloc(size);
	if (!sort)	// 이대로 -1을 반환하면 안된다.,  EXIT함수
		terminate(ps);

	// 복사
	i = -1;
	while (++i < size)
		sort[i] = arr[i];

	// 버블소트
	i = -1;
	while(++i < size - 1)
	{
		j = -1;
		while(++j < size - 1 - i)
			if(sort[j] > sort[j+1])
			{
				temp = sort[j];
				sort[j] = sort[j+1];
				sort[j+1] = temp;
			}
	}
	free(sort);
	return sort[(size / 2) - (size % 2 == 0)];
}
