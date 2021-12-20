/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:57:45 by obouadel          #+#    #+#             */
/*   Updated: 2021/11/16 16:42:24 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	s2 = (char *) malloc(ft_strlen(s1) + 1);
	if (!s2)
		return (0);
	i = 0;
	while (s1[i] != 0)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] != (char)c)
		return (0);
	return ((char *)&s[i]);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	size_t	sjoin_len;
	size_t	index;

	sjoin_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	strjoin = (char *) malloc(sjoin_len);
	if (!strjoin)
		return (NULL);
	index = 0;
	while (*s1 != '\0')
		strjoin[index++] = *s1++;
	while (*s2 != '\0')
		strjoin[index++] = *s2++;
	strjoin[index] = '\0';
	return (strjoin);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	int		n;
	size_t	slen;

	slen = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	if (start > slen)
		return (ft_strdup(""));
	if (slen - start >= len)
		substr = (char *) malloc(len + 1);
	else
		substr = (char *) malloc(slen - start + 1);
	if (!substr)
		return (NULL);
	n = 0;
	while (start < slen && len > 0 && s[start + n] != '\0')
	{
		substr[n] = s[start + n];
		n++;
		len--;
	}
	substr[n] = '\0';
	return (substr);
}
