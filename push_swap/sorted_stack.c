/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:15:20 by bmakhama          #+#    #+#             */
/*   Updated: 2024/07/24 14:21:52 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted_stack(t_stack *stack)
{
	t_stack	*current;
	t_stack	*start;

	if (stack == NULL || stack->next == stack)
		return (1);
	current = stack;
	start = stack;
	while (current->next != start)
	{
		if (current->nb > current->next->nb)
			return (0);
		current = current->next;
	}
	return (1);
}
