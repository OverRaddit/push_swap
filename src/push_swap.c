
#include "push_swap.h"

void print_deque(t_deque *src){
	printf("===========================\n");
	for(int i=0;i<src->size;i++)
		printf("%d ",src->content[i]);
	printf("\n");
	printf("===========================\n");
}

void three(t_ps *ps, int a, int b, int c)
{

	if (ps->A->size == 2 && a < b)
		s(ps->A);
	else if (ps->A->size == 3)
	{
		if(a < b && b > c && a < c)
		{
			s(ps->A);
			r(ps->A);
		}
		else if(a > b && b < c && a < c)
			s(ps->A);
		else if(a < b && b > c && a > c)
			rr(ps->A);
		else if(a > b && b < c && a > c)
			r(ps->A);
		else if(a > b && b > c && a > c)
		{
			s(ps->A);
			rr(ps->A);
		}
	}
}

void A_to_B(t_ps *ps, int size)
{
	int count;
	int temp;
	int pivot;

	count = 0;
	// 현재 옮겨야 될 원소의 수가 3이하.
	// if(size <= 3)
	// {
	// 	three(ps, ps->A->content[2], ps->A->content[1], ps->A->content[0]);
	// 	return ;
	// }
	if (size == 1)
		return;

	// 새로운 피벗값을 잡는다.
	pivot = getPivot(ps->A->content + ps->A->size - size, size);
	printf("A's pivot : %d \n", pivot);
	// size개에 대하여 B로 옮기거나 A에서 회전시킨다.
	while(size--)
	{
		if(pivot < *(ps->A->back))
		{
			r(ps->A);
			count++;
		}
		else
			p(ps->A, ps->B);
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

	count = 0;
	// if(size <= 3)
	// {
	// 	three(ps, ps->B->content[2], ps->B->content[1], ps->B->content[0]);
	// 	return ;
	// }
	if (size == 1)
	{
		p(ps->B, ps->A);
		return;
	}
	pivot = getPivot(ps->B->content + ps->B->size - size, size);
	printf("B's pivot : %d \n", pivot);
	while(size--)
	{
		if(pivot < *(ps->B->back))
		{
			r(ps->B);
			count++;
		}
		else
			p(ps->B, ps->A);
	}
	temp = count;
	while(count--)
		rr(ps->B);
	B_to_A(ps, temp);
	A_to_B(ps, size - temp);
}


int getPivot(int *arr, int size)
{
	int i;
	int j;
	int temp;
	int *sort;

	// 할당
	sort = malloc(size);
	if (!arr)	// 이대로 -1을 반환하면 안된다.,  EXIT함수
		return -1;

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
		{
			if(sort[j] > sort[j+1])
			{
				temp = sort[j];
				sort[j] = sort[j+1];
				sort[j+1] = temp;
			}
		}
	}
	free(sort);
	return sort[size / 2];
}
