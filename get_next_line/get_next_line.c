/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:47:03 by bmakhama          #+#    #+#             */
/*   Updated: 2024/01/25 13:57:59 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*read_line;
	char	*tmp;
	static char	stat_var;	

	read_line = "";
	tmp = (char *) malloc(BUFFER_SIZE + 1);
	read(fd, tmp, BUFFER_SIZE);
	read_line = ft_strjoin(read_line, tmp);
	printf("1: %s\n", read_line);
	read(fd, tmp, BUFFER_SIZE);
	read_line = ft_strjoin(read_line, tmp);
	printf("2: %s\n", read_line);
	
	return (read_line);
}

int	main(void)
{
	int		fd;
	char	*get_line;

	fd = open("test.txt", O_RDONLY);
	get_line = get_next_line(fd);
	free(get_line);
	close(fd);
	return (0);
}
