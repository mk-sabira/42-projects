/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:47:03 by bmakhama          #+#    #+#             */
/*   Updated: 2024/02/05 12:52:01 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft/libft.h"

char	*ft_read_line(int fd, char *left_str)
{
	char	*tmp;
	ssize_t	bytes_read;

	if (left_str == NULL)
	{
		left_str = malloc(1);
		if (!left_str)
			return (NULL);
		left_str[0] = '\0';
	}
	bytes_read = 1;
	if (fd < 0 || left_str == NULL)
		return (NULL);
	tmp = (char *) malloc(BUFFER_SIZE + 1);
	if (!tmp)
	{
		free(left_str);
		left_str = NULL;
		return (NULL);
	}
	while (!ft_strchr(left_str, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, tmp, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (tmp);
			tmp = NULL;
			free(left_str);
			left_str = NULL;
			return (NULL);
		}
		tmp[bytes_read] = '\0';
		left_str = ft_strjoin(left_str, tmp);
		if (!left_str)
		{
			free(tmp);
			tmp = NULL;
			free(left_str);
			left_str = NULL;
			return (NULL);
		}
	}
	free(tmp);
	tmp = NULL;
	if (bytes_read == 0 && left_str[0] == '\0')
	{
		free(left_str);
		left_str = NULL;
		return (NULL);
	}
	return (left_str);
}

char	*ft_left_line(char *left_line)
{
	char	*str;
	int		i;

	i = 0;
	if (!left_line || !left_line[i])
		return (NULL);
	while (left_line[i] && left_line[i] != '\n' && left_line[i] != '\0')
		i++;
	i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
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

char	*ft_get_rest(char *left_line)
{
	int		i;	
	int		j;
	char	*str;

	i = 0;
	while (left_line[i] && left_line[i] != '\n')
		i++;
	if (!left_line[i])
	{
		free(left_line);
		left_line = NULL;
		return (NULL);
	}
	str = (char *) malloc(sizeof(char) * (ft_strlen(left_line) - i + 1));
	if (!str)
		return (NULL);

	i++;
	j = 0;
	while (left_line[i] != 0)
		str[j++] = left_line[i++];
	str[j] = '\0';
	free(left_line);
	left_line = NULL;
	return (str);
}

char	*get_next_line(int fd)
{
	char		*full_line;
	static char	*left_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	left_line = ft_read_line(fd, left_line);
	if (!left_line)
		return (NULL);
	full_line = ft_left_line(left_line);
	left_line = ft_get_rest(left_line);
	return (full_line);
}