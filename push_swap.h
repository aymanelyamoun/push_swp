#include <unistd.h>
#include <stdlib.h>

/* /////////// LIST RELATED ///////////*/
struct s_list
{
	int	data;
	int	index;
	struct s_list	*next;
	struct s_list	*prev;
};
typedef struct s_list t_list; 
int count_len(t_list *stack);
/*///////// END LIST RELATED //////////*/

int	ft_atoi(const char *str);

/*//////////////////////////////////
///////////// OPERATIONS ///////////
//////////////////////////////////*/

/*/////////// ROTATION ///////////*/

int	rotate(t_list **stack);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
int	r_rotate(t_list **stack);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);

/*///////// END ROTATION /////////*/

/*///////// PUSHING //////////////*/

int push(t_list **from, t_list **to);
void pa(t_list **stack_b, t_list **stack_a);
void pb(t_list **stack_a, t_list **stack_b);

/*///////// END PUSHING //////////*/

/*/////// SORTING FUNCTIONS ///////*/

int compare(t_list *stack, int data);
void give_index(t_list **stack);
void push_swap(t_list **stack_a, t_list **stack_b);
void sort_last_in_a(t_list **stack_a, t_list **stack_b);
void sort_to_a(t_list **stack_b, t_list **stack_a);

/*/////////// HELPING /////////////*/
int *helper_small(t_list *stack);
int has_smaller_low(t_list *stack, int num);
int has_smaller_high(t_list *stack, int num);
int	find_the_smallest(t_list *stack);
int	find_the_smallest_high(t_list *stack);
int	find_the_smallest_low(t_list *stack);
int	find_the_bigest(t_list *stack);
int	find_the_bigest_high(t_list *stack);
int	find_the_bigest_low(t_list *stack);