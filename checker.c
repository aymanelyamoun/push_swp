/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 12:01:15 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/03/11 12:02:20 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line/get_next_line.h"

static int	com_op(const char *compare, const char *to)
{
	int	i;

	i = 0;
	while (compare[i] || to[i])
	{
		if (compare[i] != to[i])
			return (0);
		i++;
	}
	return (1);
}

int	aplly_op(char *op, t_list **stack_a, t_list **stack_b)
{
	if (com_op(op, "pa\n"))
		ch_pa(stack_a, stack_b);
	else if (com_op(op, "pb\n"))
		ch_pb(stack_a, stack_b);
	else if (com_op(op, "ra\n"))
		ch_ra(stack_a);
	else if (com_op(op, "rb\n"))
		ch_rb(stack_b);
	else if (com_op(op, "rra\n"))
		ch_rra(stack_a);
	else if (com_op(op, "rrb\n"))
		ch_rrb(stack_b);
	else if (com_op(op, "sa\n"))
		ch_sa(stack_a);
	else if (com_op(op, "sb\n"))
		ch_sb(stack_b);
	else if (com_op(op, "rr\n"))
		ch_rr(stack_a, stack_b);
	else if (com_op(op, "rrr\n"))
		ch_rrr(stack_a, stack_b);
	else if (com_op(op, "ss\n"))
		ch_ss(stack_a, stack_b);
	else
		return (0);
	return (1);
}

void	checker(t_list **stack_a, t_list **stack_b, int *i)
{
	char	*op;
	int		stat;

	while (1337)
	{
		op = get_next_line(0);
		if (!op)
			break ;
		stat = aplly_op(op, stack_a, stack_b);
		if (stat == 0)
		{
			write(2, "error\n", 6);
			*i = 1;
			break ;
		}
	}
}

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
			write(2, "Error\n", 6);
			free_stack(&stack_a);
			return (0);
		}
	}
	checker(&stack_a, &stack_b, &i);
	if (i != 1)
	{
		if (stack_is_sorted(&stack_a))
			write(1, "======> OK <======\n", 19);
		else
			write(1, "======> KO <======\n", 19);
	}
	return (0);
}
