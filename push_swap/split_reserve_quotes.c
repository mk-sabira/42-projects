/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_reserve_quotes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:08:48 by bmakhama          #+#    #+#             */
/*   Updated: 2024/07/26 10:29:38 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_input_char(char c, t_s_data *data)
{
	if (c == '"' || c == '\'')
		data->in_quotes = !(data->in_quotes);
	else if (c == ' ' && !(data->in_quotes))
	{
		if (data->j > 0)
		{
			data->buffer[data->j] = '\0';
			data->result[data->n++] = ft_strdup(data->buffer);
			data->j = 0;
		}
	}
	else
		data->buffer[data->j++] = c;
}

char	**split_reserve_quotes(char *input, int *count)
{
	t_s_data	*data;
	char		**result;

	data = malloc(sizeof(t_s_data));
	data->len = ft_strlen(input);
	data->i = 0;
	data->in_quotes = 0;
	data->j = 0;
	data->n = 0;
	data->result = malloc(sizeof(char *) * (data->len + 2));
	error_message(data->result);
	data->buffer = malloc(sizeof(char *) * (data->len + 1));
	error_message(&data->buffer);
	while (data->i < data->len)
		process_input_char(input[data->i++], data);
	if (data->j > 0)
	{
		data->buffer[data->j] = '\0';
		data->result[data->n++] = ft_strdup(data->buffer);
	}
	data->result[data->n] = NULL;
	free(data->buffer);
	*count = data->n;
	result = data->result;
	return (free(data), result);
}
