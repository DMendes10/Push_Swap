#include "push_swap.h"

size_t	ft_count_words(const char *a, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (a[i])
	{
		while (a[i] == c)
			i++;
		if (a[i])
			count++;
		while (a[i] && a[i] != c)
			i++;
	}
	return (count);
}

char	*ft_makestring(const char *s, char c)
{
	size_t	size;
	char	*s2;

	size = 0;
	while (s[size] != c && s[size] != '\0')
		size++;
	s2 = ft_calloc (sizeof (char), size + 1);
	if (s2 == NULL)
		return (NULL);
	ft_strlcpy (s2, s, size + 1);
	return (s2);
}

void	ft_free(char **s)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (**s)
	{
		free (s[i]);
		i++;
	}
	free (s);
}

char	**ft_minisplit(char **a, char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			a[j] = ft_makestring(&s[i], c);
			if (!a[j++])
			{
				ft_free(a);
				return (NULL);
			}
			i++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	return (a);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (!s)
		return (NULL);
	array = ft_calloc (sizeof(char *), ft_count_words(s, c) + 1);
	if (array == NULL)
		return (NULL);
	ft_minisplit(array, s, c);
	return (array);
}
