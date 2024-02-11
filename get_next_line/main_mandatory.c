/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_mandatory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 09:48:16 by bmakhama          #+#    #+#             */
/*   Updated: 2024/02/11 09:51:12 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	// int fd = 1;
	line = "hello";
	while (line != NULL)
	{
		line = get_next_line(1);
		printf("%s", line);
		free(line);
	}
	if (line)
		free(line);
	close(fd);
	return (0);
}
