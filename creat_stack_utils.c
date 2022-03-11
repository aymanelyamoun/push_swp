/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_stack_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:49:03 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/03/11 12:02:58 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoi(const char *str)
{
	long long	res;
	int			sign;
	int			i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\r' || str[i] == ' '
		|| str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	if (str[i])
	{
		while (str[i] >= '0' && str[i] <= '9' && str[i])
			res = res * 10 + (str[i++] - '0');
		if (str[i])
			return (2147483650);
	}
	return (res * sign);
}

int	check(t_list **stack_a, int argc, char **argv)
{
	long long	check;

	*stack_a = creat_stack(argc, argv, &check);
	if ((*stack_a == NULL && check == -1))
		return (1);
	give_index(stack_a, &check);
	if (check == -1)
		return (1);
	return (0);
}

void	free_stack(t_list **stack)
{
	t_list	*delete;

	while (*stack != NULL)
	{
		if (count_len(*stack) == 1)
		{
			free(*stack);
			*stack = NULL;
		}
		else
		{
			delete = (*stack)->next;
			(*stack)->next = delete->next;
			free(delete);
		}
	}
}
