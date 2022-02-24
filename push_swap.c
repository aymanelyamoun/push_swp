#include "push_swap.h"

int *helper_small(t_list *stack)
{
	int len;
	int chunck_len;
	int *arr;
	int i = 0;
	int prev = 0;

	arr = (int *)malloc(sizeof(int)*5);
	len = count_len(stack);
	chunck_len = len / 5;
	while (i < 4)
	{
		prev += chunck_len;
		arr[i] = prev;
		i++;
	}
	arr[i] = 0;
	return arr;
}

int has_smaller_high(t_list *stack, int num)
{
	t_list *tmp;
	int index;

	index = 0;
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
	return -1;
}
int has_smaller_low(t_list *stack, int num)
{
	t_list *tmp;
	int index;

	tmp = stack;
	index = 0;
	if (tmp->index < num)
		return index;
	tmp = tmp->prev;
	index++;
	while (tmp != stack)
	{
		if (tmp->index < num)
			return index;
		tmp = tmp->prev;
		index++;
	}
	return -1;
}

void push_swap(t_list **stack_a, t_list **stack_b)
{
	int incrementer;
	int	*arr;
	int i;
	// static int counter = 1;

	i = 0;
	arr = helper_small((*stack_a));
	while (arr[i])
	{
		while (has_smaller_high(*stack_a, arr[i]) != -1)
		{
			if (has_smaller_high(*stack_a, arr[i]) < has_smaller_low(*stack_a, arr[i]))
			{
				while((*stack_a)->next->index >= arr[i])
					ra(stack_a);
				pb(stack_a, stack_b);
			}
			else
			{
				while((*stack_a)->next->index >= arr[i])
					rra(stack_a);
				pb(stack_a, stack_b);
			}
		}
		i++;
	}
	
}