/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:29:00 by bmakhama          #+#    #+#             */
/*   Updated: 2024/07/24 14:35:06 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	*fill_data_struct(void)
{
	t_data	*data;

	data = (t_data *) malloc (sizeof(t_data));
	if (!data)
	{
		write(1, "Error allocating memory data\n", 29);
		exit (1);
	}
	data->size_a = 0;
	data->size_b = 0;
	data->moves = INT_MAX;
	return (data);
}
