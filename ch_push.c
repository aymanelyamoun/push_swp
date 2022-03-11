/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 21:30:33 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/03/11 11:40:34 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ch_pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a);
}

void	ch_pb(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
}
