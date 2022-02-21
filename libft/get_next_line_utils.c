/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decortejohn <decortejohn@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:55:58 by decortejohn       #+#    #+#             */
/*   Updated: 2022/02/07 16:56:13 by decortejohn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (*s != '\0')
	{
		s++;
		len++;
	}
	return (len);
}

char	*ft_strdup(char *s1)
{
	char	*cpy;
	int		pos;

	cpy = (char *)malloc(ft_strlen(s1) + 1);
	if (!cpy)
		return (NULL);
	pos = 0;
	while (s1[pos])
	{
		cpy[pos] = s1[pos];
		pos++;
	}
	cpy[pos] = '\0';
	return (cpy);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		pos1;
	int		pos2;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	pos1 = 0;
	pos2 = 0;
	while (s1 != NULL && s1[pos1] != '\0')
	{
		str[pos1] = s1[pos1];
		pos1++;
	}
	while (s1 != NULL && s2[pos2] != '\0')
	{
		str[pos1 + pos2] = s2[pos2];
		pos2++;
	}
	str[pos1 + pos2] = '\0';
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	char	*str;
	char	char_c;

	str = s;
	char_c = (char) c;
	while (*str != '\0')
	{
		if (*str == char_c)
		{
			return (str);
		}
		str++;
	}
	return (NULL);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	count;

	substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	count = 0;
	while (count < len)
	{
		substr[count] = s[start + count];
		count++;
	}
	substr[count] = '\0';
	return (substr);
}
