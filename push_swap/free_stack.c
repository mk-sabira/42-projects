/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:49:07 by bmakhama          #+#    #+#             */
/*   Updated: 2024/07/26 11:51:19 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;
	t_stack	*start;

	if (stack == NULL || *stack == NULL)
		return ;
	current = *stack;
	start = *stack;
	while (1)
	{
		next = current->next;
		free(current);
		if (next == start)
			break ;
		current = next;
	}
	*stack = NULL;
}

void	free_stack_input(t_stack **stack, char **input)
{
	write(1, "Error\n", 6);
	if (*stack)
		free_stack(stack);
	free_double_pointer(input);
	exit (1);
}
