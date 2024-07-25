/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_and_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 09:35:57 by bmakhama          #+#    #+#             */
/*   Updated: 2024/07/25 12:34:55 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*concat_args(int arc, char **arv)
{
	char	*result;
	int		len;
	int		i;

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
	int			nb;
	long long	nb_ll;
	int			i;

	i = 0;
	while (input[i] != NULL)
	{
		if (is_valid_nb(input[i]))
		{
			nb_ll = ft_atoi(input[i]);
			if (nb_ll < INT_MIN || nb_ll > INT_MAX)
			{
				write(1, "Input out of INT range\n", 23);
				if (*stack)
					free(stack);
				exit (1);
			}
			nb = (int) nb_ll;
		}
		else
			free_write(stack);
		if (!check_duplication(*stack, nb))
			add_node(stack, nb);
		else
			free_write(stack);
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
	{
		input = ft_split(arv[1]);
		error_message(input);
	}
	else if (arc > 2)
	{
		combined = concat_args(arc, arv);
		input = split_reserve_quotes(combined, &count);
		free(combined);
	}
	parsing_checking(input, stack);
	free_double_pointer(input);
}
