/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 09:32:56 by bmakhama          #+#    #+#             */
/*   Updated: 2024/07/25 12:08:00 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strncpy(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (i < n && s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

int	word_count(char *str)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i] != '\0')
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i])
			words++;
		while (str[i] && str[i] != ' ')
			i++;
	}
	return (words);
}

char	**ft_split(char *str)
{
	int		i;
	char	**array_word;
	int		j;
	int		k;

	array_word = malloc (sizeof(char *) * (word_count(str) + 1));
	error_message(array_word);
	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		while (str[i] && str[i] == ' ')
			i++;
		j = i;
		while (str[i] && str[i] != ' ')
			i++;
		if (j < i)
		{
			array_word[k] = malloc (sizeof (char) * ((i - j) + 1));
			ft_strncpy(array_word[k], &str[j], i - j);
			k++;
		}
	}
	array_word[k] = NULL;
	return (array_word);
}
