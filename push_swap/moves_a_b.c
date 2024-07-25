/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:18:56 by bmakhama          #+#    #+#             */
/*   Updated: 2024/07/24 14:04:04 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	moves_a(t_data **data, int i)
{
	int	ra;

	if (i <= (*data)->size_a / 2)
		ra = i;
	else
		ra = - ((*data)->size_a - i);
	return (ra);
}

int	moves_b(t_stack *stack_b, int nb_a, t_data *data)
{
	int	i;
	int	rb;

	i = 0;
	if (nb_a > data->max_b || nb_a < data->min_b)
	{
		while (stack_b->nb != data->max_b)
		{
			stack_b = stack_b->next;
			i++;
		}
	}
	else
	{
		while (!(nb_a > stack_b->nb && nb_a < stack_b->prev->nb))
		{
			stack_b = stack_b->next;
			i++;
		}
	}
	if (i <= data->size_b / 2)
		rb = i;
	else
		rb = -(data->size_b - i);
	return (rb);
}

int	total_r(int	*ra, int *rb)
{
	int	sum;

	sum = 0;
	if (*ra <= *rb)
		sum = *ra;
	else
		sum = *rb;
	*ra -= sum;
	*rb -= sum;
	return (sum);
}

int	total_rr(int *ra, int *rb)
{
	int	sum;

	sum = 0;
	if (*ra >= *rb)
		sum = -*ra;
	else
		sum = -*rb;
	*ra = *ra + sum;
	*rb = *rb + sum;
	return (sum);
}

int	total_r_rr(int ra, int rb)
{
	int	sum;
	int	moves;

	sum = 0;
	moves = 0;
	if (ra > 0 && rb > 0)
		sum = total_r(&ra, &rb);
	else if (ra < 0 && rb < 0)
		sum = total_rr(&ra, &rb);
	moves = sum;
	if (ra != 0)
		moves += ft_or(ra);
	if (rb != 0)
		moves += ft_or(rb);
	return (moves);
}
