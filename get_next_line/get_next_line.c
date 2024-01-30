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
		if (bytes_read == -1)
			return (free (tmp), NULL);
		tmp[bytes_read] = '\0';
		left_str = ft_strjoin(left_str, tmp);
		if (!left_str)
			return (free(tmp), free(left_str), NULL);
	}
	free(tmp);
	if (bytes_read == 0 && left_str[0] == '\0' )
		return (free(left_str), NULL);
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
	str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
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
	char		*full_line;
	static char	*left_line;
	int i;
	int j;
	char *str;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	left_line = ft_read_line(fd, left_line);
	if (!left_line)
		return (NULL);
	full_line = ft_left_line(left_line);
	// if (full_line == 0)
	// 	return (NULL);
	i = 0;
	while (left_line[i] && left_line[i] != '\n')
		i++;
	if (!left_line[i])
	{
		free(left_line);
		return (NULL);
	}
	str = (char *) malloc(sizeof(char) * (ft_strlen(left_line) - i + 1));
	if (str == NULL)
		return (NULL);
	i++;
	j = 0;
	while (left_line[i])
	{
		str[j++] = left_line[i++];
	}
	str[j] = '\0';
	left_line = str;
	if (left_line == NULL)
		return (NULL);
	return (full_line);
}

// int	main(void)
// {
// 	int		fd;
// 	// char	*line;
// 	fd = open("test.txt", O_RDONLY);
	
// 	printf("get_next_line1: %s", get_next_line(fd));
// 	printf("get_next_line2: %s", get_next_line(fd));

// 	close(fd);
// 	return (0);
// }
