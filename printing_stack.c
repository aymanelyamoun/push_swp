/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:28:04 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/03/11 14:59:32 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_list *stack)
{
	t_list	*tmp;

	if (stack == NULL)
		return ;
	tmp = stack->next;
	ft_printf("%d ----> index: %d\n", tmp->data, tmp->index);
	tmp = tmp->next;
	while (tmp != stack->next)
	{
		ft_printf("%d ----> index: %d\n", tmp->data, tmp->index);
		tmp = tmp->next;
	}
}

void	print_stack_prev(t_list *stack)
{
	t_list	*tmp;

	if (stack == NULL)
		return ;
	tmp = stack;
	ft_printf("%d\n", tmp->data);
	tmp = tmp->prev;
	while (tmp != stack)
	{
		ft_printf("%d\n", tmp->data);
		tmp = tmp->prev;
	}
}
