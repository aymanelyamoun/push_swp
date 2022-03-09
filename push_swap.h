/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:45:10 by ael-yamo          #+#    #+#             */
/*   Updated: 2022/03/09 14:14:06 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
/* /////////// LIST RELATED ///////////*/
struct s_list
{
	int				data;
	int				index;
	struct s_list	*next;
	struct s_list	*prev;
};
typedef struct s_list	t_list;
int			count_len(t_list *stack);
t_list		*creat_stack(int argc, char **argv, long long int *check);
/*///////// END LIST RELATED //////////*/

long long	ft_atoi(const char *str);

/*//////////////////////////////////
///////////// OPERATIONS ///////////
//////////////////////////////////*/

/*/////////// ROTATION ///////////*/

int			rotate(t_list **stack);
void		ra(t_list **stack_a);
void		rb(t_list **stack_b);
void		rr(t_list **stack_a, t_list **stack_b);
int			r_rotate(t_list **stack);
void		rra(t_list **stack_a);
void		rrb(t_list **stack_b);

/*///////// END ROTATION /////////*/

/*///////// PUSHING //////////////*/

void		push_utils(t_list **from, t_list **to, t_list **tmp);
int			push(t_list **from, t_list **to);
void		pa(t_list **stack_b, t_list **stack_a);
void		pb(t_list **stack_a, t_list **stack_b);

/*///////// END PUSHING //////////*/

/*///////// SWAPING //////////////*/
int			swap(t_list **stack);
void		sa(t_list **stack_a);
void		sb(t_list **stack_b);
/*///////// END SWAPING //////////*/

/*///////// SMALL SORTS ///////////*/
void		three_nums_sort(t_list **stack_a);
void		sort_pushing_the_smallest(t_list **stack_a, t_list **stack_b);

/*/////// SORTING FUNCTIONS ///////*/
int			compare(t_list *stack, int data);
void		give_index(t_list **stack, long long int *check);
void		push_swap(t_list **stack_a, t_list **stack_b);
void		sort_last_in_a(t_list **stack_a, t_list **stack_b);
void		sort_to_a(t_list **stack_b, t_list **stack_a);

/*/////////// HELPING /////////////*/
int			*helper_small(t_list *stack);
int			has_smaller_low(t_list *stack, int num);
int			has_smaller_high(t_list *stack, int num);
int			find_the_smallest(t_list *stack);
int			find_the_smallest_high(t_list *stack);
int			find_the_smallest_low(t_list *stack);
int			find_the_bigest(t_list *stack);
int			find_the_bigest_high(t_list *stack);
int			find_the_bigest_low(t_list *stack);
void		push_all_to_a(t_list **stack_a, t_list **stack_b);
int			has_larger_high(t_list *stack, int num);

/*///////////// RADIX ///////////////*/

int			stop_looping(t_list *stack, int b_num);
int			has_bite(t_list *stack, int b_num);
int			push_trues(t_list **stack_a, t_list **stack_b, int b_num, int i);
void		sort_using_radix(t_list **stack_a, t_list **stack_b);
int			has_bite_1(t_list *stack, int b_num);
int			stack_is_sorted(t_list **stack);
#endif