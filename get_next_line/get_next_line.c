/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:47:03 by bmakhama          #+#    #+#             */
/*   Updated: 2024/01/29 12:33:14 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd, char *left_str)
{
	char	*tmp;
	ssize_t	bytes_read;

	if (left_str == NULL)
		left_str = "";
	bytes_read = 1;
	if (fd < 0 || left_str == NULL)
		return (NULL);
	tmp = (char *) malloc(BUFFER_SIZE + 1);
	if (tmp == NULL)
		return (NULL);
	while (!ft_strchr(left_str, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, tmp, BUFFER_SIZE);
		printf("bytes_read: %zd\n", bytes_read);
		if (bytes_read == -1)
			return (free (tmp), NULL);
		tmp[bytes_read] = '\0';
		printf("tmp: %s\n", tmp);
		left_str = ft_strjoin(left_str, tmp);
		printf("ft_strjoin- left_str: %s\n%s\n", left_str, tmp);
		if (!left_str)
			return (free(tmp), free(left_str), NULL);
	}
	free(tmp);
	if (bytes_read == 0 && left_str[0] == '\0' )
		return (free(left_str), NULL);
	printf("ft_read_line- left_str: %s\n", left_str);
	return (left_str);
}

char	*ft_left_line(char *left_line)
{
	char	*str;
	int		i;

	i = 0;
	if (!left_line[i])
		return (NULL);
	while (left_line[i] && left_line[i] != '\n' && left_line[i] != '\0')
		i++;
	i++;
	printf("len: %d\n", i);
	str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	printf("str: %s\n", str);
	while (left_line[i] && left_line[i] != '\n' && left_line[i] != '\0')
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
	// printf("called get_next_line\n");
	char		*full_line;
	static char	*left_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	// printf("called get_next_line\n");
	left_line = ft_read_line(fd, left_line);
	printf("get_next_line- ft_read_line: %s\n", left_line);
	if (left_line == NULL)
		return (NULL);
	full_line = ft_left_line(left_line);
	if (full_line == NULL)
		return (NULL);
	return (full_line);
}

int	main(void)
{
	int		fd;
	// char	*line;
	fd = open("test.txt", O_RDONLY);
	while (1)
	{
		printf("%s", get_next_line(fd));
	}
	close(fd);
	return (0);
}
