/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:45:33 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/03/11 12:05:46 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
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
