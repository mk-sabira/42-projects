/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:18:37 by bmakhama          #+#    #+#             */
/*   Updated: 2024/07/26 10:33:14 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_cheap_pb_rr(t_stack **stack_a, t_stack **stack_b, t_data **data)
{
	int	moves;
	int	copy;

	if ((*data)->ra <= (*data)->rb)
		copy = (*data)->ra;
	else
		copy = (*data)->rb;
	moves = copy;
	while (copy--)
	{
		ft_rr(stack_a, stack_b);
	}
	(*data)->ra -= moves;
	(*data)->rb -= moves;
}

void	ft_cheap_pb_rrr(t_stack **stack_a, t_stack **stack_b, t_data **data)
{
	int	moves;
	int	copy;

	if ((*data)->ra >= (*data)->rb)
		copy = ft_or((*data)->ra);
	else
		copy = ft_or((*data)->rb);
	moves = copy;
	if (copy > 0)
	{
		while (copy--)
			ft_rrr(stack_a, stack_b);
	}
	(*data)->ra += moves;
	(*data)->rb += moves;
}

void	ft_cheap_pb_ra(t_stack **stack_a, t_data **data)
{
	int	moves;

	if ((*data)->ra > 0)
	{
		moves = (*data)->ra;
		if (moves > 0)
		{
			while (moves--)
				ft_ra(stack_a);
		}
	}
	else
	{
		moves = ft_or((*data)->ra);
		if (moves > 0)
		{
			while (moves--)
				ft_rra(stack_a);
		}
	}
}

void	ft_cheap_pb_rb(t_stack **stack_b, t_data **data)
{
	int	moves;

	if ((*data)->rb > 0)
	{
		moves = ft_or((*data)->rb);
		if (moves > 0)
		{
			while (moves--)
				ft_rb(stack_b);
		}
	}
	else
	{
		moves = ft_or((*data)->rb);
		if (moves > 0)
		{
			while (moves--)
				ft_rrb(stack_b);
		}
	}
}

void	cheap_pb(t_stack **stack_a, t_stack **stack_b, t_data **data)
{
	if ((*data)->ra >= 0 && (*data)->rb >= 0)
	{
		ft_cheap_pb_rr(stack_a, stack_b, data);
	}
	else if ((*data)->ra < 0 && (*data)->rb < 0)
		ft_cheap_pb_rrr(stack_a, stack_b, data);
	ft_cheap_pb_ra(stack_a, data);
	ft_cheap_pb_rb(stack_b, data);
	ft_pb(stack_a, stack_b);
	(*data)->moves = INT_MAX;
}
