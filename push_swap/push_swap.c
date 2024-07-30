/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 09:29:29 by bmakhama          #+#    #+#             */
/*   Updated: 2024/07/26 11:58:35 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int arc, char **arv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_data	*data;

	stack_a = NULL;
	stack_b = NULL;
	if (arc > 1)
	{
		valid_and_init(arc, arv, &stack_a);
		if (!sorted_stack(stack_a))
		{
			if (ft_count_size(stack_a) == 2)
				ft_sa(&stack_a);
			else if (ft_count_size(stack_a) == 3)
				sort_three(&stack_a);
			else
			{
				data = fill_data_struct();
				sort_stack(&stack_a, &stack_b, data);
			}
		}
	}
	if (stack_a)
		free_stack(&stack_a);
	return (0);
}
