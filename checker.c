#include "push_swap.h"
#include "get_next_line/get_next_line.h"
#include "stdio.h"
long long	ft_atoi(const char *str)
{
	long long	res;
	int			sign;
	int			i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\r' || str[i] == ' '
		|| str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	if (str[i])
	{
		while (str[i] >= '0' && str[i] <= '9' && str[i])
			res = res * 10 + (str[i++] - '0');
		if (str[i])
			return (2147483650);
	}
	return (res * sign);
}
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

int	com_op(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	char	*st1;
	char	*st2;

	i = 0;
	st1 = (char *)s1;
	st2 = (char *)s2;
	while (i < n && st1[i] && st2[i] && st1[i] == st2[i])
		i++;
	if (i == n || st2[i] == st1[i])
		return (0);
	return (1);
}
int aplly_op(char *op, t_list **stack_a, t_list **stack_b)
{
	if (com_op(op, "pa\n", ft_strlen(op)))
		pa(stack_a, stack_b);
	if (com_op(op, "pb\n", ft_strlen(op)))
		pb(stack_b, stack_a);
	if (com_op(op, "ra\n", ft_strlen(op)))
		ra(stack_a);
	if (com_op(op, "rb\n", ft_strlen(op)))
		rb(stack_b);
	if (com_op(op, "rra\n", ft_strlen(op)))
		rra(stack_a);
	if (com_op(op, "rrb\n", ft_strlen(op)))
		rrb(stack_b);
	if (com_op(op, "sa\n", ft_strlen(op)))
		sa(stack_a);
	if (com_op(op, "sb\n", ft_strlen(op)))
		sb(stack_b);
	if (com_op(op, "rr\n", ft_strlen(op)))
		rr(stack_a, stack_b);
	if (com_op(op, "rrr\n", ft_strlen(op)))
		rrr(stack_a, stack_b);
	if (com_op(op, "ss\n", ft_strlen(op)))
		ss(stack_a, stack_b);
	else
		return (0);
	return (1);
}

// void	checker(t_list **stack_a, t_list **stack_b)
// {

// }

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*op;
	int		stat;
	int		i;

	i = 0;
	if (argc > 1)
	{
		if (check(&stack_a, argc, argv) == 1)
		{
			write(2, "Error\n", 6);
			// free_stack(&stack_a);
			return 0;
		}
	}
	while (1337)
	{
		op = get_next_line(0);
		if (!op)
			break ;
		aplly_op(op, &stack_a, &stack_b);
		// if (stat == 0)
		// {
		// 	write(2, "error\n", 6);
		// 	break ;
		// }
	}
	// checker(&stack_a, &stack_b);
	if (stack_is_sorted(&stack_a))
		write(1, "======> OK <======\n", 19);
	else
		write(1, "======> KO <======\n", 19);
	// print_stack(stack_a);
	return (0);
}