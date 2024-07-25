/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 09:27:14 by bmakhama          #+#    #+#             */
/*   Updated: 2024/07/24 14:28:57 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_size(t_stack *stack)
{
	t_stack *current;
	t_stack *start;
	int     count;

	if (stack == NULL)
		return (0);
	current = stack;
	start = stack;
	count = 0;
	while (current != NULL)
	{
		count++;
		current = current->next;
		if (current == start)
			break ;
	}
	return (count);
}

t_stack	*find_max(t_stack *stack)
{
	t_stack	*current;
	t_stack	*highest_node;
	int		max;

	if (stack == NULL)
		return (NULL);
	current = stack;
	highest_node = stack;
	max = current->nb;
	while (current->next != stack)
	{
		current = current->next;
		if (current->nb > max)
		{
			max = current->nb;
			highest_node = current;
		}
	}
	return (highest_node);
}

t_stack	*find_min(t_stack *stack)
{
	t_stack	*current;
	t_stack	*lowest_node;
	int		min;

	if (stack == NULL)
		return (NULL);
	current = stack;
	lowest_node = stack;
	min = current->nb;
	while (current->next != stack)
	{
		current = current->next;
		if (current->nb < min)
		{
			min = current->nb;
			lowest_node = current;
		}
	}
	return (lowest_node);
}

int	ft_or(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
