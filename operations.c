#include "push_swap.h"

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/+++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/+++++++++++++++++   ROTATION   ++++++++++++++++++++++++++
/+++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/+++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

int	rotate(t_list **stack)
{
	if (*stack == NULL)
		return 0;
	if (count_len(*stack) == 1)
		return 0;
	*stack = (*stack)->next;
	return 1;
}

void	ra(t_list **stack_a)
{
	if (rotate(stack_a))
		write(1, "ra\n", 3);
}

void	rb(t_list **stack_b)
{
	if(rotate(stack_b))
		write(1, "rb\n", 3);
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/+++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/+++++++++++++++++  REVERS ROTATION   ++++++++++++++++++++
/+++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/+++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

int	r_rotate(t_list **stack)
{
	if (*stack == NULL)
		return 0;
	if (count_len(*stack) == 1)
		return 0;
		//make sure to change the prev in all the listes
	*stack = (*stack)->prev;
	return 1;
}

void	rra(t_list **stack_a)
{
	if (r_rotate(stack_a))
		write(1, "rra\n", 4);
}

void	rrb(t_list **stack_b)
{
	if(r_rotate(stack_b))
		write(1, "rrb\n", 4);
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/+++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/++++++++++++++++++   PUSHING   ++++++++++++++++++++++++++
/+++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/+++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

int push(t_list **from, t_list **to)
{
	t_list *tmp;

	if (*from == NULL)
		return 0;
	tmp = (*from)->next;
	if (count_len(*from) == 1)
		(*from) = NULL;
	else
	{
		(*from)->next->next->prev = (*from);
		(*from)->next = (*from)->next->next;
	}
	if (count_len(*to) == 0)
	{
		tmp->next = tmp;
		tmp->prev = tmp;
		*to = tmp;
	}
	else
	{
		tmp->next = (*to)->next;
		tmp->next->prev = tmp;
		tmp->prev = (*to);
		(*to)->next = tmp;
	}
	return 1;
}











/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/+++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/++++++++++++++++++   PUSHING   ++++++++++++++++++++++++++
/+++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/+++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/