/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_and_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 09:35:57 by bmakhama          #+#    #+#             */
/*   Updated: 2024/07/29 12:27:30 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_white_space(const char *str)
{
	while (*str)
	{
		if (!ft_isspace((unsigned char) *str))
			return (0);
		str++;
	}
	return (1);
}

void	check_empty(int arc, char **arv)
{
	int	i;

	i = 1;
	while (i < arc)
	{
		if (arv[1][0] == '\0')
		{
			write(1, "Error\n", 6);
			exit(1);
		}
		if (is_white_space(arv[i]))
		{
			write(1, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}

char	*concat_args(int arc, char **arv)
{
	char	*result;
	int		len;
	int		i;

	check_empty(arc, arv);
	len = 0;
	i = 1;
	while (i < arc)
	{
		len += ft_strlen(arv[i]) + 1;
		i++;
	}
	result = malloc(len * sizeof(char));
	error_message(&result);
	result[0] = '\0';
	i = 1;
	while (i < arc)
	{
		ft_strcat(result, arv[i]);
		if (i < arc - 1)
			ft_strcat(result, " ");
		i++;
	}
	return (result);
}

void	parsing_checking( char **input, t_stack **stack)
{
	long		nb_l;
	int			i;
	int			nb;

	i = 0;
	while (input[i] != NULL)
	{
		if (is_valid_nb(input[i]))
		{
			nb_l = ft_atoll(input[i]);
			if (nb < INT_MIN || nb > INT_MAX)
				free_stack_input(stack, input);
			nb = (int) nb_l;
		}
		else
			free_stack_input(stack, input);
		if (!check_duplication(*stack, nb))
			add_node(stack, nb);
		else
			free_stack_input(stack, input);
		i++;
	}
}

void	valid_and_init(int arc, char **arv, t_stack **stack)
{
	char	**input;
	int		count;
	char	*combined;

	input = NULL;
	if (arc == 2)
		input = ft_split(arv[1]);
	else if (arc > 2)
	{
		combined = concat_args(arc, arv);
		input = split_reserve_quotes(combined, &count);
		free(combined);
	}
	parsing_checking(input, stack);
	free_double_pointer(input);
}
