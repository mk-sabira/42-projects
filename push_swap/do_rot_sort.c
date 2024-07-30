/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rot_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:38:31 by bmakhama          #+#    #+#             */
/*   Updated: 2024/07/26 10:41:53 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_rot_sort(t_stack **stack_a, int i, t_data *data)
{
	int	j;

	if (i <= (data->size_a / 2))
	{
		j = 0;
		while (j < i)
		{
			ft_ra(stack_a);
			j++;
		}
	}
	else
	{
		j = 0;
		while (j < (data->size_a - i))
		{
			ft_rra(stack_a);
			j++;
		}
	}
}

int	do_rot_sort(t_stack **stack_a, t_data *data, int sort)
{
	t_stack	*current;
	int		i;

	current = *stack_a;
	i = 0;
	while (1)
	{
		if (current->nb == min_nb(*stack_a))
			break ;
		else
		{
			current = current->next;
			i++;
		}
	}
	if (sorted_stack(current) == 1 && sort == 1)
	{
		ft_sort_rot_sort(stack_a, i, data);
		return (2);
	}
	else if (sorted_stack(current) == 1)
		return (1);
	else
		return (0);
}
