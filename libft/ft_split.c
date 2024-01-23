/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmakhama <bmakhama@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:22:01 by bmakhama          #+#    #+#             */
/*   Updated: 2024/01/07 11:41:52 by bmakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nmb_ofw(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if ((s[i] != c) && (s[i] != '\0'))
			count++;
		while ((s[i] != c) && (s[i] != '\0'))
			i++;
	}
	return (count);
}

static void	ft_free(char **ptr, int k)
{
	while (k--)
		free(ptr[k]);
	free(ptr);
}

static char	*ft_putword(char const *s, int *ip, char c)
{
	int		j;
	char	*word;
	int		count;
	int		i_copy;

	count = 0;
	i_copy = *ip;
	while ((s[i_copy] != c) && (s[i_copy] != '\0'))
	{
		count++;
		i_copy++;
	}
	word = (char *)malloc(count + 1);
	if (!word)
		return (0);
	j = 0;
	while ((s[*ip] != c) && (s[*ip] != '\0'))
	{
		word[j] = s[*ip];
		(*ip)++;
		j++;
	}
	word[j] = '\0';
	return (word);
}

static char	**ft_split_iterate(char **ptr, char const *s, char c)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if ((s[i] != c) && (s[i] != '\0'))
		{
			ptr[k] = ft_putword(s, &i, c);
			if (!(ptr[k]))
			{
				ft_free(ptr, k);
				return (0);
			}
		}
		k++;
	}
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		words;

	if (!s)
		return (0);
	words = ft_nmb_ofw(s, c);
	ptr = (char **)malloc(sizeof(char *) * (words + 1));
	if (!ptr)
		return (0);
	ptr[words] = 0;
	ptr = ft_split_iterate(ptr, s, c);
	return (ptr);
}
