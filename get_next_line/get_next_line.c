/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:47:03 by bmakhama          #+#    #+#             */
/*   Updated: 2024/01/24 20:08:16 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char *read_line;
	size_t bytes_read;
	char *buffer[BUFFER_SIZE];

    char    buffer[BUFFER_SIZE];
	fd = open("test.text", O_RDONLY);
    bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	buffer[bytes_read] = '\0';
	read_line = malloc(bytes_read + 1);
	ft_strlcpy(buffer, read_line, bytes_read);
	printf ("%s", read_line);
	return (read_line);
}

int	main(void)
{
	int fd;
	char *get_line;

	fd = open("test.txt", O_RDONLY);
	get_line = get_next_line(fd);
	
	free(get_line);
    close(fd);
    return (0);
}
