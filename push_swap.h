#include <unistd.h>
#include <stdlib.h>

struct s_list
{
	int	data;
	int	index;
	struct s_list	*next;
	struct s_list	*prev;
};
typedef struct s_list t_list;
int	ft_atoi(const char *str);
int	rotate(t_list **stack);
int count_len(t_list *stack);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
int push(t_list **from, t_list **to);
