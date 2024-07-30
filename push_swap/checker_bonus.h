#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"

typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_data
{
	int	size_a;
	int	size_b;
	int	max_a;
	int	max_b;
	int	min_b;
	int	min_a;
	int	moves;
	int	ra;	
	int	rb;	
}	t_data;

typedef struct s_split_data
{
	char	**result;
	char	*buffer;
	int		in_quotes;
	int		j;
	int		n;
	int		i;
	int		len;
}	t_s_data;

// input validation and initialization of stack
char	**ft_split(char *str);
char	**split_reserve_quotes(char *input, int *count);
int		is_valid_nb(char *str);
int		check_duplication(t_stack *stack, int nb);
void	add_node(t_stack **head, int value);
void	valid_and_init(int arc, char **arv, t_stack **stack);

// freeing stack
void	free_stack(t_stack **stack);
void	error_message(char **memory);
void	free_write(t_stack **stack);
void	free_double_pointer(char **ptr);
void	free_stack_input(t_stack **stack, char **input);

//operations
void	ft_pa(t_stack **stack_b, t_stack **stack_a);
void	ft_pb(t_stack **stack_a, t_stack **stack_b);
void	ft_ra(t_stack **stack_a);
void	ft_rb(t_stack **stack_b);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);
void	ft_rra(t_stack **stack_a);
void	ft_rrb(t_stack **stack_b);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);
void	ft_sa(t_stack **stack_a);
void	ft_sb(t_stack **stack_b);
void	ft_ss(t_stack **stack_a, t_stack **stack_b);

// sorting
int		sorted_stack(t_stack *stack);
int		ft_count_size(t_stack *stack);
void	sort_three(t_stack **stack);
t_data	*fill_data_struct(void);
void	sort_stack(t_stack **stack_a, t_stack **stack_b, t_data *data);
t_stack	*find_max(t_stack *stack);
t_stack	*find_min(t_stack *stack);

//finding cheapest move
int		moves_a(t_data **data, int i);
int		moves_b(t_stack *stack_b, int nb_a, t_data *data);
int		ft_or(int ab);
int		total_r_rr(int ra, int rb);
void	total_move(t_stack *stack_a, t_stack *stack_b, t_data **data);
void	cheap_pb(t_stack **stack_a, t_stack **stack_b, t_data **data);
void	total_move(t_stack *stack_a, t_stack *stack_b, t_data **data);
int		max_nb(t_stack *stack);
int		min_nb(t_stack *stack);
int		do_rot_sort(t_stack **stack_a, t_data *data, int sort);

#endif