/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 09:28:25 by bmakhama          #+#    #+#             */
/*   Updated: 2024/02/10 15:10:13 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read(int fd, char *line)
{
	char	*get_buff;
	ssize_t	bytes_read;

	if (line == NULL)
	{
		line = (char *)malloc(1 * sizeof(char));
		if (!line)
			return (NULL);
		line[0] = '\0';
	}
	get_buff = (char *) malloc((ssize_t)BUFFER_SIZE + 1);
	if (!get_buff)
		return (free(line), NULL);
	bytes_read = 1;
	while (!ft_strchr(line, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, get_buff, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free (get_buff), free(line), NULL);
		get_buff[bytes_read] = '\0';
		line = ft_strjoin(line, get_buff);
	}
	return (free(get_buff), line);
}

char	*ft_get_line(char *left_str)
{
	char	*str;
	int		i;

	i = 0;
	if (!left_str[i])
		return (NULL);
	while (left_str[i] && left_str[i] != '\n' && left_str[i] != '\0')
		i++;
	if (left_str[i] == '\n')
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (left_str[i] && left_str[i] != '\n' && left_str[i] != '\0')
	{
		str[i] = left_str[i];
		i++;
	}
	if (left_str[i] == '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	return (str[i] = '\0', str);
}

char	*ft_get_remain(char *left_str)
{
	int		i;	
	int		j;
	char	*str;

	i = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (!left_str[i])
		return (free(left_str), NULL);
	str = (char *) malloc(sizeof(char) * (ft_strlen(left_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (left_str[i] != 0)
		str[j++] = left_str[i++];
	str[j] = '\0';
	return (free(left_str), str);
}

char	*get_next_line(int fd)
{
	char		*full_line;
	static char	*left_line[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	left_line[fd] = ft_read(fd, left_line[fd]);
	if (!left_line[fd])
		return (NULL);
	full_line = ft_get_line(left_line[fd]);
	left_line[fd] = ft_get_remain(left_line[fd]);
	return (full_line);
}
