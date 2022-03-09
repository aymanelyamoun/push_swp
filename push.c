/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:53:51 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/03/09 15:04:01 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_utils(t_list **from, t_list **to, t_list **tmp)
{
	if (count_len(*to) == 0)
	{
		(*tmp)->next = *tmp;
		(*tmp)->prev = *tmp;
		*to = *tmp;
	}
	else
	{
		(*tmp)->next = (*to)->next;
		(*tmp)->next->prev = *tmp;
		(*tmp)->prev = (*to);
		(*to)->next = *tmp;
	}
}

int	push(t_list **from, t_list **to)
{
	t_list	*tmp;

	if (*from == NULL)
		return (0);
	tmp = (*from)->next;
	if (count_len(*from) == 1)
		(*from) = NULL;
	else
	{
		(*from)->next->next->prev = (*from);
		(*from)->next = (*from)->next->next;
	}
	push_utils(from, to, &tmp);
	return (1);
}

void	pa(t_list **stack_b, t_list **stack_a)
{
	if (push(stack_b, stack_a))
		write(1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_a, stack_b))
		write(1, "pb\n", 3);
}
