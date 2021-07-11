/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldaniel- <ldaniel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 11:59:02 by ldaniel-          #+#    #+#             */
/*   Updated: 2021/07/10 16:11:28 by ldaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strclen(const char *s, int c)
{
	size_t	count;

	count = 0;
	while (s[count] && s[count] != c)
		count++;
	return (count);
}

char	*ft_strchr(const char *s, int c)
{
	int	index;

	index = 0;
	while (s[index])
	{
		if (s[index] == (unsigned char)c)
			return ((char *)s + index);
		index++;
	}
	if (c == '\0')
		return ((char *)s + index);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	i;

	i = 0;
	dst = malloc((ft_strclen(s1, '\0') + 1) * sizeof(char));
	if (!dst || !s1)
		return (NULL);
	while (s1[i] != 0)
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char			*new_str;
	size_t			i;
	unsigned int	size_new;

	i = 0;
	size_new = ft_strclen(s2, '\0');
	if (s1 != NULL)
		size_new = ft_strclen(s1, '\0') + size_new;
	new_str = malloc((size_new + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		new_str[i] = s1[i];
		i++;
	}
	while (*s2 != '\0')
	{
		new_str[i] = *s2;
		s2++;
		i++;
	}
	new_str[i] = '\0';
	free(s1);
	return (new_str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substring;
	size_t			size;
	unsigned int	i;

	if (!s)
		return (NULL);
	i = 0;
	size = ft_strclen(s + start, '\0');
	if (size < len)
		len = size;
	substring = malloc((len + 1) * sizeof(char));
	if (substring == NULL)
		return (NULL);
	while ((i < len) && ((start) < ft_strclen(s, '\0')) && (s[start] != '\0'))
	{
		substring[i] = s[start];
		i++;
		start++;
	}
	substring[i] = '\0';
	return (substring);
}
