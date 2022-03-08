/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   giving_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:29:45 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/03/08 16:29:55 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int compare(t_list *stack, int data)
{
	t_list	*tmp;
	int		index;

	index = 0;
	tmp = stack->next;
	if (tmp->data == data)
		return (-1);
	if (tmp->data < data)
		index++;
	tmp = tmp->next;
	while (tmp != stack)
	{
		if (tmp->data == data)
			return (-1);
		if (tmp->data < data)
			index++;
		tmp = tmp->next;
	}
	return (index);
}

void	give_index(t_list **stack, long long int *check)
{
	t_list	*tmp;
	int		index;

	tmp = (*stack)->next;
	index = compare(tmp, tmp->data);
	tmp->index = index;
	tmp = tmp->next;
	while (tmp != (*stack)->next)
	{
		index = compare(tmp, tmp->data);
		if (index == -1)
		{
			*check = index;
			return ;
		}
		tmp->index = index;
		tmp = tmp->next;
	}
}
