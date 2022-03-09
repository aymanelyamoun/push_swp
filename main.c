/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:45:33 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/03/09 14:36:18 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check(t_list **stack_a, int argc, char **argv)
{
	long long	check;

	*stack_a = creat_stack(argc, argv, &check);
	if ((*stack_a == NULL && check == -1))
		return (1);
	give_index(stack_a, &check);
	if (check == -1)
		return (1);
	return (0);
}

void	free_stack(t_list **stack)
{
	t_list	*delete;

	while (*stack != NULL)
	{
		if (count_len(*stack) == 1)
		{
			free(*stack);
			*stack = NULL;
		}
		else
		{
			delete = (*stack)->next;
			(*stack)->next = delete->next;
			free(delete);
		}
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		*arr;
	int		i;

	i = 0;
	if (argc > 1)
	{
		if (check(&stack_a, argc, argv) == 1)
		{
			write(2, "error\n", 6);
			free_stack(&stack_a);
		}
		else if (!stack_is_sorted(&stack_a) && (count_len(stack_a) > 1))
		{
			if (count_len(stack_a) == 3)
				three_nums_sort(&stack_a);
			else if (count_len(stack_a) <= 5)
				sort_pushing_the_smallest(&stack_a, &stack_b);
			else
				sort_using_radix(&stack_a, &stack_b);
			free_stack(&stack_a);
		}
	}
	return (0);
}
