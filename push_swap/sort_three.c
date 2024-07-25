/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 09:25:06 by bmakhama          #+#    #+#             */
/*   Updated: 2024/07/14 13:06:10 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	t_stack	*highest;

	if (*stack == NULL)
		return ;
	highest = find_max(*stack);
	if ((*stack) == highest)
		ft_ra(stack);
	else if ((*stack)->next == highest)
		ft_rra(stack);
	if ((*stack)->nb > (*stack)->next->nb)
		ft_sa(stack);
}
