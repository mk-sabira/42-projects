#include "checker_bonus.h"


void	ft_reverse_rotate(t_stack **stack)
{
	if (*stack == NULL || (*stack)->next == *stack)
		return ;
	*stack = (*stack)->prev;
}

void	ft_rra(t_stack **stack_a)
{
	ft_reverse_rotate(stack_a);
}

void	ft_rrb(t_stack **stack_b)
{
	ft_reverse_rotate(stack_b);
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
}