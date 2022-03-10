/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:28:04 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/03/10 22:15:57 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_list *stack)
{
	t_list	*tmp;

	if (stack == NULL)
		return ;
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
	t_list	*tmp;

	if (stack == NULL)
		return ;
	tmp = stack;
	printf("%d\n", tmp->data);
	tmp = tmp->prev;
	while (tmp != stack)
	{
		printf("%d\n", tmp->data);
		tmp = tmp->prev;
	}
}
