/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 19:09:59 by gshim             #+#    #+#             */
/*   Updated: 2022/02/09 23:45:04 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static int is_spacenum(char *input)
{
	int i;

	i = -1;
	while(input[++i])
	{
		if ('0' <= input[i] && input[i] <= '9')
			continue;
		else if(input[i] == ' ' || input[i] == '-')
			continue;
		else
			return (0);
	}
	return (1);
}

int input(t_ps *ps, char *argv)
{
	int i;
	char ** temp;

	temp = ft_split(argv, ' ');
	if (!temp)
		terminate(ps);
	i = -1;
	while(temp[++i])
	{
		// 공백,부호,숫자가 아닌 문자가 오거나
		// 길이가 0인 문자열인 경우 ERROR
		if (!is_spacenum(temp[i]) || ft_strlen(temp[i]) == 0)
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
