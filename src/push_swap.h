#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../include/libft/libft.h"
# include "deque.h"

typedef struct	s_ps
{
	t_deque	*A;
	t_deque	*B;
	t_list	*opcode;
}	t_ps;

// push_swap.c
void	A_to_B(t_ps *ps, int size, int depth);
void	B_to_A(t_ps *ps, int size, int depth);
int		getPivot(t_ps *ps, int *arr, int size);
void	getPivot_extend(t_ps *ps, int *arr, int size, int *Spivot, int *Lpivot);
void	A_to_B_extend(t_ps *ps, int size, int depth);
void	B_to_A_extend(t_ps *ps, int size, int depth);

void	A_to_B_move(t_ps *ps, int size, int Spivot, int Lpivot, int *ra, int *rb);
void	B_to_A_move(t_ps *ps, int size, int Spivot, int Lpivot, int *ra, int *rb);
void	rewind(t_ps *ps, int ra, int rb);

// sort.c
void	bubblesort(int *arr, int size);
int		isAscending(int *arr, int size);
int		isDescending(int *arr, int size);
void	twoA(t_ps *ps, int a, int b);
void	twoB(t_ps *ps, int a, int b);
void	minimum_sort(t_ps *ps, int n, char c);
void	threeA(t_ps *ps, int a, int b, int c);
//void threeB(t_ps *ps, int a, int b, int c);

// input.c
int		input(t_ps *ps, char *argv);

// main.c
int		terminate(t_ps *ps);
void	replace_opcode(t_list *lst, char opcode[5]);
void	flatten_opcode(t_list *lst);

#endif
