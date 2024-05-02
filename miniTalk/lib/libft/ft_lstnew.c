/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:09:07 by bmakhama          #+#    #+#             */
/*   Updated: 2024/01/22 12:45:54 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstnew(void *content)
{
	t_list  *node1;

	node1 = malloc(sizeof(t_list));
	if (!node1)
		return (0);
	node1.content = content;
	node1.next = NULL;
	return (node1);
}
