/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min_nb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:57:39 by bmakhama          #+#    #+#             */
/*   Updated: 2024/07/24 14:03:35 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_nb(t_stack *stack)
{
	t_stack	*current;
	int		max;

	if (stack == NULL)
		return (INT_MIN);
	current = stack;
	max = current->nb;
	while (current->next != stack)
	{
		current = current->next;
		if (current->nb > max)
			max = current->nb;
	}
	return (max);
}

int	min_nb(t_stack *stack)
{
	t_stack	*current;
	int		min;

	if (stack == NULL)
		return (INT_MAX);
	current = stack;
	min = current->nb;
	while (current->next != stack)
	{
		current = current->next;
		if (current->nb < min)
			min = current->nb;
	}
	return (min);
}
