#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (0);
	// if (c == '\0')
	// 	return ((char *)&s[ft_strlen(s)]);
	while (*s != '\0' && *s != (char)c)
		s++;
	if (*s == (char) c)
		return ((char *)s);
	else
		return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	size_t	len;
	int	i;
	int	j;

	if ((!s1) || (!s2))
		return (NULL);
	if (*s1 == '\0')
		len = ft_strlen(s2) + 1;
	else
		len = ft_strlen(s1) + ft_strlen(s2) + 1;
	ptr = (char *)malloc(sizeof(char) * len);
	if (!ptr)
		return (0);
	i = 0;
	j = 0;
	while (s1[j])
		ptr[i++] = s1[j++];
	while (*s2)
		ptr[i++] = *(s2)++;
	ptr[i] = '\0';
	free(s1);
	s1 = NULL;
	return (ptr);
}