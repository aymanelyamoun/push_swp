/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:55:44 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/03/11 12:09:25 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_list **stack)
{
	int		tmp_data;
	int		tmp_index;
	t_list	*tmp;

	tmp = (*stack)->next;
	if (count_len(*stack) <= 1)
		return (0);
	if (count_len(*stack) == 2)
		(*stack) = (*stack)->next;
	else
	{
		tmp_data = tmp->data;
		tmp_index = tmp->index;
		tmp->data = tmp->next->data;
		tmp->index = tmp->next->index;
		tmp->next->data = tmp_data;
		tmp->next->index = tmp_index;
	}
	return (1);
}

void	sa(t_list **stack_a)
{
	if (swap(stack_a))
		write(1, "sa\n", 3);
}

void	sb(t_list **stack_b)
{
	if (swap(stack_b))
		write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	int	check1;
	int	check2;

	check1 = swap(stack_a);
	check2 = swap(stack_b);
	if (check1 && check2)
		write(1, "ss\n", 3);
	else if (check1)
		write(1, "sa\n", 3);
	else if (check2)
		write(1, "sb\n", 3);
}
