/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 09:51:37 by bmakhama          #+#    #+#             */
/*   Updated: 2024/02/11 09:54:28 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int fd1 = open("test1.txt", O_RDONLY);
	int fd2 = open("test2.txt", O_RDONLY);
	int fd3 = open("test3.txt", O_RDONLY);
	int fd4 = open("test4.txt", O_RDONLY);
	int fd5 = open("test5.txt", O_RDONLY);
	// int fd1 = 0;
	// int fd2 = 0;
	char *line1 = NULL;
	char *line2 = NULL;
	char *line3 = NULL;
	char *line4 = NULL;
	char *line5 = "hello";

	while (line5)
	{
		line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);
		line3 = get_next_line(fd3);
		line4 = get_next_line(fd4);
		line5 = get_next_line(fd5);
		if (line1 != NULL)
		{
			printf("line1: %s\n", line1);
			free(line1);
		}
		if (line2 != NULL)
		{
			printf("LINE2:%s\n", line2);
			free(line2);
		}
		if (line3 != NULL)
		{
			printf("LINE3:%s\n", line3);
			free(line3);
		}
		if (line4 != NULL)
		{
			printf("LINE4:%s\n", line4);
			free(line4);
		}
		if (line5 != NULL)
		{
			printf("LINE5:%s\n", line5);
			free(line5);
		}
	}
	if (line1)
		free(line1);
	if (line2)
		free(line2);
	if (line3)
		free(line3);
	if (line4)
		free(line4);
	if (line5)
		free(line5);
	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	close(fd5);
	return (0);
}
