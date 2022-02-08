/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 19:09:59 by gshim             #+#    #+#             */
/*   Updated: 2022/02/08 21:55:53 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int isAscending(int *arr, int size)
{
	int i;

	i = -1;
	while(++i < size - 1)
	{
		if (arr[i] > arr[i + 1])
			return 0;
	}
	return 1;
}

int isDescending(int *arr, int size)
{
	int i;

	i = -1;
	while(++i < size - 1)
	{
		if (arr[i] < arr[i + 1])
			return 0;
	}
	return 1;
}

int terminate(t_ps *ps){
	deq_clear(ps->A);
	printf("A스택을 free합니다.\n");
	deq_clear(ps->B);
	printf("B스택을 free합니다.\n");
	ft_lstclear(&(ps->opcode), free);
	printf("opcode free합니다.\n");

	exit(1);
}

int myinput(int argc, char *argv[]){
	int i;
	char ** temp;

	temp = ft_split(argv, ' ');
	if (!temp)
		return (-1);
	i = -1;
	while(temp[++i]){
		//printf("[%s]\n", temp[i]);
		deq_push_back(ps->A, ft_atoi(temp[i]));
	}
	free(temp);
	return (0);
}

int input(t_ps *ps, char *argv){
	int i;
	char ** temp;

	temp = ft_split(argv, ' ');
	if (!temp)
		return (-1);
	i = -1;
	while(temp[++i]){
		deq_push_back(ps->A, ft_atoi(temp[i]));
	}
	free(temp);
	return (0);
}
