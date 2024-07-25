/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_reserve_quotes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:08:48 by bmakhama          #+#    #+#             */
/*   Updated: 2024/07/25 12:18:41 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

char	**split_reserve_quotes(char *input, int *count)
{
	char	**result;
	char	*buffer;
	int		in_quotes;
	int		len;
	int		j;
	int		n;
	int		i;

	len = ft_strlen(input);
	in_quotes = 0;
	j = 0;
	n = 0;
	i = 0;
	result = malloc(sizeof(char *) * len);
	error_message(result);
	buffer = malloc(sizeof(char *) * len);
	error_message(&buffer);
	while (i < len)
	{
		if (input[i] == '"' || input[i] == '\'')
			in_quotes = !in_quotes;
		else if (input[i] == ' ' && !in_quotes)
		{
			if (j > 0)
			{
				buffer[j] = '\0';
				result[n++] = ft_strdup(buffer);
				j = 0;
			}
		}
		else
			buffer[j++] = input[i];
		i++;
	}
	if (j > 0)
	{
		buffer[j] = '\0';
		result[n++] = ft_strdup(buffer);
	}
	*count = n;
	return (result);
}
