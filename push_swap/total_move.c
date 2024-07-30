/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   total_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:33:04 by bmakhama          #+#    #+#             */
/*   Updated: 2024/07/26 10:33:28 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	total_move(t_stack *stack_a, t_stack *stack_b, t_data **data)
{
	int	total_move;
	int	ra;
	int	rb;
	int	i;

	i = 0;
	while (i < (*data)->size_a)
	{
		ra = moves_a(data, i);
		rb = moves_b(stack_b, stack_a->nb, *data);
		total_move = total_r_rr(ra, rb);
		if (total_move < (*data)->moves)
		{
			(*data)->moves = total_move;
			(*data)->ra = ra;
			(*data)->rb = rb;
		}
		if (total_move == 0)
			return ;
		i++;
		stack_a = stack_a->next;
	}
}
