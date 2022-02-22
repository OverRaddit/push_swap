/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 19:09:59 by gshim             #+#    #+#             */
/*   Updated: 2022/02/22 15:14:23 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "deque.h"

// 중복검사하는 함수 추가할 것.

// int 범위 밖의 수를 어떻게 검출할지 생각할 것.

static int	is_num(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

static int	is_overflow(char *input)
{
	if (input[0] == '-' && ft_atoi(input) > 0)
		return (1);
	if (input[0] != '-' && ft_atoi(input) < 0)
		return (1);
	return (0);
}

static int	is_valid(char *input)
{
	int	i;
	int	len;

	i = 0;
	if (input[i] == '-' && !is_num(input[i + 1]))
		return (0);
	if (input[i] == '-' && is_num(input[i + 1]))
		i++;
	len = ft_strlen(&input[i]);
	if (len > 10)
		return (0);
	while (input[i])
	{
		if(!is_num(input[i]))
			return (0);
		i++;
	}
	if (len == 10 && is_overflow(input))
		return (0);
	return (1);
}

int	is_duplicate(t_ps *ps, int *arr, int size)
{
	int	*sort;
	int	i;
	int	ans;

	ans = 0;
	sort = malloc(sizeof(int) * size);
	if (!sort)
		terminate(ps);
	i = -1;
	while (++i < size)
		sort[i] = arr[i];
	bubblesort(sort, size);
	i = -1;
	while (++i < size - 1)
		if (sort[i] == sort[i + 1])
			ans = 1;
	free(sort);
	return (ans);
}

int	input(t_ps *ps, char *argv)
{
	int		i;
	char	**temp;

	temp = ft_split(argv, ' ');
	if (!temp)
		terminate(ps);
	i = -1;
	while (temp[++i])
	{
		if (!is_valid(temp[i]) || ft_strlen(temp[i]) == 0)
		{
			ft_putstr_fd("ERROR\n", 1);
			terminate(ps);
		}
		deq_push_back(ps->A, ft_atoi(temp[i]));
		free(temp[i]);
	}
	free(temp[i]);
	free(temp);
	return (0);
}
