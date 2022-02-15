#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../include/libft/libft.h"
# include "../include/deque/deque.h"
# include <stdio.h>

typedef struct s_ps{
	t_deque *A;
	t_deque *B;
	int *sortArr;
	int pivot;
	int size;
	t_list *opcode;
}	t_ps;

void print_deque(t_deque *src);
void A_to_B(t_ps *ps, int size);
void B_to_A(t_ps *ps, int size);
int getPivot(t_ps *ps, int *arr, int size);

void bubblesort(int *arr, int size);
int isAscending(int *arr, int size);
int isDescending(int *arr, int size);
void minimum_sort(t_ps *ps, int n, char c);
void twoA(t_ps *ps, int a, int b);
void twoB(t_ps *ps, int a, int b);
// three정렬시 stack size == 3이면 좀더 최적화가 가능
void threeA(t_ps *ps, int a, int b, int c);
//void threeB(t_ps *ps, int a, int b, int c);

int input(t_ps *ps, char *argv);


int terminate(t_ps *ps);
void replace_opcode(t_list *lst, char opcode[5]);
void flatten_opcode(t_list *lst);

#endif
