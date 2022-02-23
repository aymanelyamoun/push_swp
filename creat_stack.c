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
	while (argc >= 2)
	{
		add_at_end(&stack, ft_atoi(argv[--argc]));
	}
	return stack;
}

void	print_stack(t_list *stack)
{
	t_list *tmp;

	if (stack == NULL)
		return;
	tmp = stack->next;
	printf("%d\n", tmp->data);
	tmp = tmp->next;
	while (tmp != stack->next)
	{
		printf("%d\n", tmp->data);
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







int	main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;
	stack_a = creat_stack(argc, argv);
	print_stack(stack_a);
	// ra(&stack_b);
	
	printf("___________________________\n");
	print_stack(stack_a);
	printf("???????? revers ????????\n");
	print_stack_prev(stack_a);
	// push(&stack_a, &stack_b);
	// push(&stack_a, &stack_b);
	printf("___________________________\n");
	// print_stack(stack_b);

}
