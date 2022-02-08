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
	t_list *opcode;
}	t_ps;

int getPivot(t_ps *ps, int *arr, int size);
void A_to_B(t_ps *ps, int size);
void B_to_A(t_ps *ps, int size);

void two(t_ps *ps, int a, int b);
void three(t_ps *ps, int a, int b, int c);
void minimum_sort(t_ps *ps, int n);

void print_deque(t_deque *src);


int isAscending(int *arr, int size);
int isDescending(int *arr, int size);
int terminate(t_ps *ps);
int input(t_ps *ps, char *argv);

#endif
