/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:04:18 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/03/09 18:11:15 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_trues(t_list **stack_a, t_list **stack_b, int b_num, int i)
{
	int	index;
	int	rotate_a;

	b_num <<= 1;
	i++;
	rotate_a = 0;
	while (has_bite_1(*stack_b, b_num))
	{
		if ((*stack_b)->next->index & b_num)
			pa(stack_b, stack_a);
		else
			rb(stack_b);
	}
	while ((*stack_b)->index != find_the_smallest(*stack_b))
	{
		if (((index >> i) & 1) == 1)
		{
			index = (*stack_a)->next->index;
			rr(stack_a, stack_b);
			rotate_a++;
		}
		else
			rb(stack_b);
	}
	return (rotate_a);
}

void	push_all_to_a(t_list **stack_a, t_list **stack_b)
{
	while (*stack_b != NULL)
		pa(stack_b, stack_a);
}
