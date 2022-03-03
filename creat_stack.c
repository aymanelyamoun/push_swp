#include <stdio.h>
#include "push_swap.h"

t_list *creat_node(int data)
{
	t_list *node;
	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
		return 0;
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	node->index = -1;
	return node;
}

int count_len(t_list *stack)
{
	int i;
	t_list *tmp;
	tmp = stack;

	i = 0;
	if (stack != NULL)
	{
		tmp = tmp->next;
		tmp = tmp->next;
		i++;
		while (tmp != stack->next)
		{
			tmp = tmp->next;
			i++;
		}
	}
	return i;
}

void	add_at_end(t_list **stack, int data)
{
	t_list *tmp;
	t_list *end;

	if (*stack == NULL)
	{
		*stack = creat_node(data);
		(*stack)->next = *stack;
		//night time code
		(*stack)->prev = *stack;
	}
	else
	{
		tmp = creat_node(data);
		tmp->next = (*stack)->next;
		(*stack)->next = tmp;
		tmp->prev = (*stack);
		(*stack) = tmp;
		tmp->next->prev = tmp;
	}
}

t_list *creat_stack(int argc, char **argv)
{
	t_list *stack;
	int i = 1;

	stack = NULL;
	//change this line 
	if (argc > 1)
	{
		while (i < argc)
		{
			add_at_end(&stack, ft_atoi(argv[i]));
			i++;
		}
	}

	return stack;
}

void	print_stack(t_list *stack)
{
	t_list *tmp;

	if (stack == NULL)
		return;
	tmp = stack->next;
	printf("%d ----> index: %d\n", tmp->data, tmp->index);
	tmp = tmp->next;
	while (tmp != stack->next)
	{
		printf("%d ----> index: %d\n", tmp->data, tmp->index);
		tmp = tmp->next;
	}
}
void	print_stack_prev(t_list *stack)
{
	t_list *tmp;

	if (stack == NULL)
		return;
	tmp = stack;
	printf("%d\n", tmp->data);
	tmp = tmp->prev;
	while (tmp != stack)
	{
		printf("%d\n", tmp->data);
		tmp = tmp->prev;
	}
}

int compare(t_list *stack, int data)
{
	t_list *tmp;
	int index;

	index = 0;
	tmp = stack->next;
	if (tmp->data < data)
		index++;
	tmp = tmp->next;
	while (tmp != stack->next)
	{
		if (tmp->data < data)
			index++;
		tmp = tmp->next;
	}
	return index;
}

void give_index(t_list **stack)
{
	t_list *tmp;
	int index;

	tmp = (*stack)->next;
	index = compare(tmp, tmp->data);
	tmp->index = index;
	tmp = tmp->next;
	while (tmp != (*stack)->next)
	{
		index = compare(tmp, tmp->data);
		tmp->index = index;
		tmp = tmp->next;
	}
}



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

	mid = count_len(*stack_a)/2;
	while(!stack_is_sorted(stack_a) && *stack_a != NULL)
	{
		len = count_len(*stack_a);
		if (len == 3)
			three_nums_sort(stack_a);
		while(has_smaller_high(*stack_a, mid))
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

int is_the_smallest(t_list *stack_a, t_list *stack_b)
{
	if (has_smaller_high(stack_a, (stack_b)->next->index))
		return 0;
	else 
		return 1;
}
int is_the_largest(t_list *stack_a, t_list *stack_b)
{
	if (has_larger_high(stack_a, (stack_b)->next->index))
		return 0;
	else 
		return 1;
}
void five_nums_sort(t_list **stack_a, t_list **stack_b)
{
	int smaller;

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	three_nums_sort(stack_a);
	while ((*stack_b) != NULL)
	{
		if (is_the_smallest(*stack_a, *stack_b))
			pa(stack_b, stack_a);
		if (is_the_largest(*stack_a, *stack_b))
		{
			if ((*stack_a)->index == find_the_bigest(*stack_a))
			{
				pa(stack_b, stack_a);
				ra(stack_a);
			}
		}
		else
		{
			while(((*stack_a)->next->index > (*stack_b)->next->index) || ((*stack_a)->next->next->index < (*stack_b)->next->index))
				ra(stack_a);
			ra(stack_a);
			pa(stack_b, stack_a);
		}
	}
	while((*stack_a)->next->index != find_the_smallest(*stack_a))
		rra(stack_a);
	
	

}

int	main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;
	stack_a = creat_stack(argc, argv);
	int *arr;
	int i = 0;

	// if (stack_is_sorted(&stack_a))
	// 	return 0;
	give_index(&stack_a);
	// five_nums_sort(&stack_a, &stack_b);
	// three_num_sort(&stack_a, &stack_b);
	sort_pushing_the_smallest(&stack_a, &stack_b);
	// sort_using_radix(&stack_a, &stack_b);
}
