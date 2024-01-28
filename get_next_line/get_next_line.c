/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:47:03 by bmakhama          #+#    #+#             */
/*   Updated: 2024/01/28 12:53:58 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd, char *left_str)
{
	char	*tmp;
	ssize_t	bytes_read;
	int		count;

	left_str = "";
	count = 0;
	bytes_read = 1;
	tmp = (char *) malloc(BUFFER_SIZE + 1);
	while (!ft_strrchr(left_str, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, tmp, BUFFER_SIZE);
		tmp[bytes_read] = '\0';
		left_str = ft_strjoin(left_str, tmp);
		// printf("[%d]%s\n", count, left_str);
		count++;
	}
	free(tmp);
	return (left_str);
}

char	*ft_left_line(char *left_line)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * (i + 1));
	while (left_line[i] && left_line[i] != 0)
	{
		str[i] = left_line[i];
		i++;
	}
	if (left_line[i] == '\n')
	{
		str[i] = left_line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	char		*full_line;
	static char	*left_line;

	left_line = ft_read_line(fd, left_line);
	// printf("left_line: %s", left_line);
	full_line = ft_left_line(left_line);
	return (full_line);
}

int	main(void)
{
	int		fd;

	fd = open("test.txt", O_RDONLY);
	while (1)
	{
		printf("%s", get_next_line(fd));
	}
	// get_line = get_next_line(fd);
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}
