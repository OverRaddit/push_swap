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

int getPivot(int *arr, int size);
void A_to_B(t_ps *ps, int size);
void B_to_A(t_ps *ps, int size);
void three(t_ps *ps, int a, int b, int c);
void print_deque(t_deque *src);

#endif