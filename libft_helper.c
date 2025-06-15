/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogo <diogo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 19:40:26 by diogo             #+#    #+#             */
/*   Updated: 2025/06/15 19:46:59 by diogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	unsigned char	*c;

	c = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		c[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;

	if (size == 0 || nmemb == 0)
		return (malloc(0));
	if (size > INT_MAX / nmemb)
		return (NULL);
	s = malloc(nmemb * size);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, (nmemb * size));
	return (s);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(src);
	i = 0;
	if (len + 1 < size)
	{
		while (src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	else if (size != 0)
	{
		while (i < size -1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (i[s])
		i++;
	return (i);
}

