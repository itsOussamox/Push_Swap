/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:41:10 by obouadel          #+#    #+#             */
/*   Updated: 2021/11/08 15:19:57 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_substrim(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (start >= ft_strlen(s))
	{
		sub = ft_strdup("");
		return (sub);
	}
	sub = (char *)malloc((len + 1));
	if (!sub)
		return (0);
	while ((i < len) && s[i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

static int	ft_setfound(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		beg;
	int		end;
	char	*trim;

	if (!s1 || !set)
		return (0);
	beg = 0;
	end = ft_strlen(s1) - 1;
	while (s1[beg] && !ft_setfound(s1[beg], set))
		beg++;
	while (beg < end && !ft_setfound(s1[end], set))
		end--;
	trim = ft_substrim(s1, beg, end - beg + 1);
	return (trim);
}
