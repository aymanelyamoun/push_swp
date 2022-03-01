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
/*/////////////////////////////*/
int	find_the_smallest(t_list *stack)
{
	t_list *tmp;
	int	largest;

	if (stack != NULL)
	{
		tmp = stack->next;
		largest = tmp->index;
		tmp = tmp->next;
		while(tmp != stack->next)
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

int	find_the_smallest_high(t_list *stack)
{
	t_list *tmp;
	int	largest;
	int index;

	if (stack != NULL)
	{
		index = 0;
		tmp = stack->next;
		largest = tmp->index;
		tmp = tmp->next;
		while(tmp != stack->next)
		{
			if (tmp->index < largest)
			{
				largest = tmp->index;
			}
			index++;
			tmp = tmp->next;
		}
		return index;
	}
	else
		return -1;
}

int	find_the_smallest_low(t_list *stack)
{
	t_list *tmp;
	int	largest;
	int index;

	if (stack != NULL)
	{
		index = 1;
		tmp = stack;
		largest = tmp->index;
		tmp = tmp->prev;
		while(tmp != stack)
		{
			if (tmp->index < largest)
			{
				largest = tmp->index;
			}
			index++;
			tmp = tmp->prev;
		}
		return index;
	}
	else
		return -1;
}
/*/////////////////////////////*/
int	find_the_bigest(t_list *stack)
{
	t_list *tmp;
	int	largest;

	if (stack != NULL)
	{
		tmp = stack->next;
		largest = tmp->index;
		tmp = tmp->next;
		while(tmp != stack->next)
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

int	find_the_bigest_high(t_list *stack)
{
	t_list *tmp;
	int	largest;
	int index;

	if (stack != NULL)
	{
		index = 0;
		tmp = stack->next;
		largest = tmp->index;
		tmp = tmp->next;
		while(tmp != stack->next)
		{
			if (tmp->index > largest)
			{
				largest = tmp->index;
				index++;
			}
			tmp = tmp->next;
		}
		return index;
	}
	else
		return -1;
}

int	find_the_bigest_low(t_list *stack)
{
	t_list *tmp;
	int	largest;
	int index;

	if (stack != NULL)
	{
		index = 0;
		tmp = stack;
		largest = tmp->index;
		tmp = tmp->prev;
		while(tmp != stack)
		{
			if (tmp->index > largest)
			{
				largest = tmp->index;
				index++;
			}
			tmp = tmp->prev;
		}
		return index;
	}
	else
		return -1;
}
/*//////////////////////////////*/

int has_smaller_low(t_list *stack, int num)
{
	t_list *tmp;
	int index;

	tmp = stack;
	index = count_len(stack);
	if (tmp->index < num)
		return index;
	tmp = tmp->prev;
	index--;
	while (tmp != stack)
	{
		if (tmp->index < num)
			return index;
		tmp = tmp->prev;
		index--;
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
	while (i < 4)
	{
		while (has_smaller_high(*stack_a, arr[i]) != -1)
		{
			// claculat from the bottom;
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
void sort_last_in_a(t_list **stack_a, t_list **stack_b)
{
	int largest;

	while(*stack_a != NULL)
	{
		largest = find_the_smallest(*stack_a);
		while((*stack_a)->next->index != largest)
		{
			if (find_the_smallest_high(*stack_a) < find_the_smallest_low(*stack_b))
			{
				while((*stack_a)->next->index != largest)
				{
					ra(stack_a);
				}
			}
			else
			{
				while((*stack_a)->next->index != largest)
				{
					rra(stack_a);
				}
			}
		}
		pb(stack_a, stack_b);
	}
}
//kinda sus
void sort_to_a(t_list **stack_b, t_list **stack_a)
{
	int largest;

	while(*stack_b != NULL)
	{
		largest = find_the_bigest(*stack_b);
		while((*stack_b)->next->index != largest)
		{
			if (find_the_bigest_high(*stack_b) < find_the_bigest_low(*stack_b))
			{
				while((*stack_b)->next->index != largest)
				{
					rb(stack_b);
				}
			}
			else
			{
				while((*stack_b)->next->index != largest)
				{
					rrb(stack_b);
				}
			}
		}
		pa(stack_b, stack_a);
	}
}

///// check the find biggest return value

/////// sorting with radix;

int stop_looping(t_list *stack, int b_num)
{
	t_list *tmp;

	tmp = stack->next;
	if ((tmp->index & b_num))
		return 1;
	tmp = tmp->next;
	while(tmp != stack->next)
	{
		if ((tmp->index & b_num))
			return 1;
		tmp = tmp->next;
	}

	return 0;
}

// int has_bite(t_list *stack, int b_num)
// {
// 	t_list *tmp;

// 	tmp = stack->next;
// 	if (!((tmp->index >> b_num) & 1))
// 		return 1;
// 	tmp = tmp->next;
// 	while(tmp != stack->next)
// 	{
// 		if (!((tmp->index >> b_num) & 1))
// 			return 1;
// 		tmp = tmp->next;
// 	}
// 	return 0;
// }

int has_bite(t_list *stack, int b_num)
{
	t_list *tmp;

	tmp = stack->next;
	if ((tmp->index & b_num))
		return 1;
	tmp = tmp->next;
	while(tmp != stack->next)
	{
		if ((tmp->index & b_num))
			return 1;
		tmp = tmp->next;
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
	while(tmp != stack->next)
	{
		if ((tmp->index & b_num))
			return 1;
		tmp = tmp->next;
	}
	return 0;
}

// int top_non_pushed(t_list *stack, int b_num)
// {
// 	t_list *tmp;

// 	tmp = stack->next;
// 	while((has_bite_1(stack, b_num)))
// 	{
// 		if (!((stack)->next->index & b_num))
// 			return stack->next->index;
// 		stack = stack->next;
// 	}
// 	return -1;
// }
void push_all_trues_to_a(t_list **stack_a, t_list **stack_b, int b_num)
{
	t_list *tmp;
	b_num <<= 1;
	int check;
	int top;


	tmp = (*stack_b)->next;
	check = 0;
	while((has_bite_1(*stack_b, b_num)))
	{
		if ((*stack_b)->next->index & b_num)
			pa(stack_b, stack_a);
		else
		{
			if (check == 0)
			{
				top = (*stack_b)->next->index;
				check = 1;
			}
			rb(stack_b);
		}
	}
	// while((*stack_b)->next->index != top)
	// 	rrb(stack_b);
	while((*stack_b)->index != find_the_smallest(*stack_b))
	{
		if (find_the_smallest_high(*stack_b) < find_the_smallest_low(*stack_b))
			rb(stack_b);
		else
			rrb(stack_b);
	}
}

int stack_is_sorted(t_list **stack)
{
	t_list *tmp;

	tmp = (*stack)->next;
	while(tmp != *stack)
	{
		if (tmp->index > tmp->next->index)
			return 0;
		tmp = tmp->next;
	}
	return 1;
}

void push_all_to_a(t_list **stack_a,t_list **stack_b)
{
	while(*stack_b != NULL)
	{
		pa(stack_b, stack_a);
	}
}
void sort_using_radix(t_list **stack_a, t_list **stack_b)
{
	int	index;
	int	len;
	int	bite = 0;
	int	zero_biter = 1;
	int biggest = find_the_bigest(*stack_a);
	while ((biggest >> bite))
		bite++;
	int i = 0;
		//loop over every bite.
	//find where to stop.

	//make sure you are working with the index
	while(i < bite)
	{
		len = count_len(*stack_a);
		while(len--)
		{
			index = (*stack_a)->next->index;
			if (((index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		push_all_trues_to_a(stack_a, stack_b, zero_biter);
		zero_biter <<= 1;
		i++;
	}
	push_all_to_a(stack_a, stack_b);
}




