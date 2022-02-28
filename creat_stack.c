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


int	main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;
	stack_a = creat_stack(argc, argv);
	int *arr;
	int i = 0;

	// printf("___________________________\n");
	// // print_stack_prev(stack_a);
	// printf("___________________________\n");
////////////////////////////////////////////////	
////////////////////////////////////////////////	
////////////////////////////////////////////////	
////////////////////////////////////////////////	
	give_index(&stack_a);
	
	// // pb(&stack_a, &stack_b);
	// // return 0;
	// push_swap(&stack_a, &stack_b);
	// sort_last_in_a(&stack_a, &stack_b);
	// sort_to_a(&stack_b, &stack_a);
	// // print_stack(stack_a);
	
////////////////////////////////////////////////	
////////////////////////////////////////////////	
////////////////////////////////////////////////	
////////////////////////////////////////////////

	sort_using_radix(&stack_a, &stack_b);
	// print_stack(stack_a);
	print_stack(stack_b);
}
