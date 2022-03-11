/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:52:38 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/03/11 12:08:15 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_list **stack)
{
	if (*stack == NULL)
		return (0);
	if (count_len(*stack) == 1)
		return (0);
	*stack = (*stack)->next;
	return (1);
}

void	ra(t_list **stack_a)
{
	if (rotate(stack_a))
		write(1, "ra\n", 3);
}

void	rb(t_list **stack_b)
{
	if (rotate(stack_b))
		write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	int	check1;
	int	check2;

	check1 = rotate(stack_a);
	check2 = rotate(stack_b);
	if (check1 && check2)
		write(1, "rr\n", 3);
	else if (check1)
		write(1, "ra\n", 3);
	else if (check2)
		write(1, "rb\n", 3);
}
