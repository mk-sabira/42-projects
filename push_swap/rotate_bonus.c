#include "checker_bonus.h"

void	ft_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (*stack == NULL || (*stack)->next == *stack)
		return ;
	first = *stack;
	second = (*stack)->next;
	last = first->prev;
	first->prev = last;
	first->next = second;
	second->prev = first;
	last->next = first;
	*stack = second;
}

void	ft_ra(t_stack **stack_a)
{
	ft_rotate(stack_a);
}

void	ft_rb(t_stack **stack_b)
{
	ft_rotate(stack_b);
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
}