/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_r_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:56:54 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/03/11 12:07:42 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	r_rotate(t_list **stack)
{
	if (*stack == NULL)
		return (0);
	if (count_len(*stack) == 1)
		return (0);
	*stack = (*stack)->prev;
	return (1);
}

void	rra(t_list **stack_a)
{
	if (r_rotate(stack_a))
		write(1, "rra\n", 4);
}

void	rrb(t_list **stack_b)
{
	if (r_rotate(stack_b))
		write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	int	check1;
	int	check2;

	check1 = r_rotate(stack_a);
	check2 = r_rotate(stack_b);
	if (check1 && check2)
		write(1, "rrr\n", 4);
	else if (check1)
		write(1, "rra\n", 4);
	else if (check2)
		write(1, "rrb\n", 4);
}
