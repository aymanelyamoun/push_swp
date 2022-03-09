/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:06:31 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/03/09 18:08:32 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_smaller_high(t_list *stack, int num)
{
	t_list	*tmp;
	int		index;

	index = 1;
	tmp = stack->next;
	if (tmp->index < num)
		return (index);
	tmp = tmp->next;
	index++;
	while (tmp != stack->next)
	{
		if (tmp->index < num)
			return (index);
		tmp = tmp->next;
		index++;
	}
	return (0);
}

int	has_bite_1(t_list *stack, int b_num)
{
	t_list	*tmp;

	tmp = stack->next;
	if ((tmp->index & b_num))
		return (1);
	tmp = tmp->next;
	while (tmp != stack->next)
	{
		if ((tmp->index & b_num))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	find_the_smallest(t_list *stack)
{
	t_list	*tmp;
	int		largest;

	if (stack != NULL)
	{
		tmp = stack->next;
		largest = tmp->index;
		tmp = tmp->next;
		while (tmp != stack->next)
		{
			if (tmp->index < largest)
				largest = tmp->index;
			tmp = tmp->next;
		}
		return (largest);
	}
	else
		return (-1);
}

int	find_the_bigest(t_list *stack)
{
	t_list	*tmp;
	int		largest;

	if (stack != NULL)
	{
		tmp = stack->next;
		largest = tmp->index;
		tmp = tmp->next;
		while (tmp != stack->next)
		{
			if (tmp->index > largest)
				largest = tmp->index;
			tmp = tmp->next;
		}
		return (largest);
	}
	else
		return (-1);
}

int	stack_is_sorted(t_list **stack)
{
	t_list	*tmp;

	tmp = (*stack)->next;
	while (tmp != *stack)
	{
		if (tmp->index > tmp->next->index)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
