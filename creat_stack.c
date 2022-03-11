/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:21:54 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/03/11 18:04:20 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

t_list	*creat_node(int data)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	node->index = -1;
	return (node);
}

int	count_len(t_list *stack)
{
	int		i;
	t_list	*tmp;

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
	return (i);
}

void	add_at_end(t_list **stack, int data)
{
	t_list	*tmp;

	if (*stack == NULL)
	{
		*stack = creat_node(data);
		(*stack)->next = *stack;
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

t_list	*creat_stack(int argc, char **argv, long long int *check)
{
	t_list	*stack;
	int		i;

	i = 1;
	stack = NULL;
	if (argc > 1)
	{
		while (i < argc)
		{
			*check = ft_atoi(argv[i]);
			if (*check < INT_MIN || *check > INT_MAX)
			{
				*check = -1;
				return (stack);
			}
			i++;
		}
		i = 1;
		while (i < argc)
		{
			add_at_end(&stack, ft_atoi(argv[i]));
			i++;
		}
	}
	return (stack);
}
