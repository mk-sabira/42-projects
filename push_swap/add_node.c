/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:52:43 by bmakhama          #+#    #+#             */
/*   Updated: 2024/07/24 14:31:40 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
	{
		write(1, "error allocating memory\n", 24);
		exit (1);
	}
	node->nb = value;
	node->next = node;
	node->prev = node;
	return (node);
}

void	add_node(t_stack **head, int value)
{
	t_stack	*node;
	t_stack	*last;

	node = new_node(value);
	if (*head == NULL)
		*head = node;
	else
	{
		last = (*head)->prev;
		last->next = node;
		node->prev = last;
		node->next = *head;
		(*head)->prev = node;
	}
}
