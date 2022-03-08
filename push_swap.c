/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 13:31:25 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/03/08 16:17:36 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*/////////////////////////////////////////////////////
///////////////////////////////////////////////////////
////////////////////// SORT HELPERS ///////////////////
///////////////////////////////////////////////////////
/////////////////////////////////////////////////////*/
int has_smaller_high(t_list *stack, int num)
{
	t_list *tmp;
	int index;

	index = 1;
	tmp = stack->next;
	if (tmp->index < num)
		return index;
	tmp = tmp->next;
	index++;
	while (tmp != stack->next)
	{
		if (tmp->index < num)
			return index;
		tmp = tmp->next;
		index++;
	}
	return 0;
}

int has_bite_1(t_list *stack, int b_num)
{
	t_list *tmp;

	tmp = stack->next;
	if ((tmp->index & b_num))
		return 1;
	tmp = tmp->next;
	while (tmp != stack->next)
	{
		if ((tmp->index & b_num))
			return 1;
		tmp = tmp->next;
	}
	return 0;
}

int find_the_smallest(t_list *stack)
{
	t_list *tmp;
	int largest;

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
		return largest;
	}
	else
		return -1;
}

int find_the_bigest(t_list *stack)
{
	t_list *tmp;
	int largest;

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
		return largest;
	}
	else
		return -1;
}

int stack_is_sorted(t_list **stack)
{
	t_list *tmp;

	tmp = (*stack)->next;
	while (tmp != *stack)
	{
		if (tmp->index > tmp->next->index)
			return 0;
		tmp = tmp->next;
	}
	return 1;
}

int push_trues(t_list **stack_a, t_list **stack_b, int b_num, int i)
{
	b_num <<= 1;
	int index;
	int rotate_a = 0;

	i++;
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
	return rotate_a;
}

void push_all_to_a(t_list **stack_a, t_list **stack_b)
{
	while (*stack_b != NULL)
		pa(stack_b, stack_a);
}

/*/////////////////////////////////////////////////////
///////////////////////////////////////////////////////
/////////////////// SIMPLE SORTS //////////////////////
///////////////////////////////////////////////////////
/////////////////////////////////////////////////////*/

void three_nums_sort(t_list **stack_a)
{
	int first;
	int second;
	int third;

	first = (*stack_a)->next->index;
	second = (*stack_a)->next->next->index;
	third = (*stack_a)->index;
	if (first > second && third > first)
		sa(stack_a);
	else if (first < second && first > third)
		rra(stack_a);
	else if (first > second && second > third)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (first > second && first > third && second < third)
		ra(stack_a);
	else if (first < second && second > third)
	{
		rra(stack_a);
		sa(stack_a);
	}
}

void sort_pushing_the_smallest(t_list **stack_a, t_list **stack_b)
{
	int mid;
	int len;

	mid = count_len(*stack_a) / 2;
	while (!stack_is_sorted(stack_a) && *stack_a != NULL)
	{
		len = count_len(*stack_a);
		if (len == 3)
			three_nums_sort(stack_a);
		while (has_smaller_high(*stack_a, mid))
		{
			if ((*stack_a)->next->index < mid)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
		}
	}
	if ((*stack_b)->next->index < (*stack_b)->next->next->index)
		sb(stack_b);
	push_all_to_a(stack_a, stack_b);
}
/*///////////////////////////////////*/
/*/////////// RADIX SORT ///////////*/
/*/////////////////////////////////*/

static void radix_utils(t_list **stack_a, t_list **stack_b, int bite, int len)
{
	int i;
	int zero_biter;

	i = 0;
	zero_biter = 1;
	while (i < bite)
	{
		while (len-- && (!stack_is_sorted(stack_a)))
		{
			if (((((*stack_a)->next->index >> i) & 1) == 1))
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		len = -(push_trues(stack_a, stack_b, zero_biter, i)) + count_len(*stack_a);
		zero_biter <<= 1;
		i++;
	}
}

void sort_using_radix(t_list **stack_a, t_list **stack_b)
{
	int len;
	int bite;
	int zero_biter;
	int biggest;

	bite = 0;
	zero_biter = 1;
	biggest = find_the_bigest(*stack_a);
	while ((biggest >> bite))
		bite++;
	len = count_len(*stack_a);
	radix_utils(stack_a, stack_b, bite, len);
	push_all_to_a(stack_a, stack_b);
}
