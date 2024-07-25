/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:16:30 by bmakhama          #+#    #+#             */
/*   Updated: 2024/07/24 14:28:02 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_size(t_stack *stack)
{
	t_stack	*current;
	t_stack	*start;
	int		count;

	if (stack == NULL)
		return (0);
	current = stack;
	start = stack;
	count = 0;
	while (current != start) 
	{
		count++;
		current = current->next;
		if (current == start)
			break ;
	}
	return (count);
}

void ft_swap(t_stack **stack)
{
	int	temp;

	temp = (*stack)->nb;
	(*stack)->nb = (*stack)->next->nb;
	(*stack)->next->nb = temp;
}

void	ft_sa(t_stack **stack_a)
{
	ft_swap(stack_a);
	write(1, "sa\n", 3);
}

void	ft_sb(t_stack **stack_b)
{
	ft_swap(stack_b);
	write(1, "sb\n", 3);
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	write(1, "ss\n", 3);
}
