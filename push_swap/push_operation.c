/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:46:28 by bmakhama          #+#    #+#             */
/*   Updated: 2024/07/24 14:16:38 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **src, t_stack **dest)
{
	t_stack	*temp;

	if (*src == NULL)
		return ;
	temp = *src;
	if (*src == (*src)->next)
		*src = NULL;
	else
	{
		*src = (*src)->next;
		(*src)->prev = temp->prev;
		temp->prev->next = *src;
	}
	if (*dest == NULL)
	{
		temp->next = temp;
		temp->prev = temp;
	}
	else
	{
		temp->next = *dest;
		temp->prev = (*dest)->prev;
		(*dest)->prev->next = temp;
		(*dest)->prev = temp;
	}
	*dest = temp;
}

void	ft_pa(t_stack **stack_b, t_stack **stack_a)
{
	ft_push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
