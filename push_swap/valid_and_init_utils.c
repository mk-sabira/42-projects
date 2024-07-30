/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_and_init_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:25:08 by bmakhama          #+#    #+#             */
/*   Updated: 2024/07/29 10:34:56 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_double_pointer(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i] && ptr)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

void	error_message(char	**memory)
{
	if (!memory)
	{
		write(1, "error allocating mem\n", 21);
		exit(1);
	}
}

void	free_write(t_stack **stack)
{
	write (1, "Non digit input or dup\n", 23);
	free_stack(stack);
	exit (1);
}

int	is_valid_nb(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (i > 11)
		return (0);
	return (1);
}

int	check_duplication(t_stack *stack, int nb)
{
	t_stack	*current;
	t_stack	*start;

	if (stack == NULL)
		return (0);
	current = stack;
	start = stack;
	while (current != NULL)
	{
		if (current->nb == nb)
			return (1);
		current = current->next;
		if (current == start)
			break ;
	}
	return (0);
}
