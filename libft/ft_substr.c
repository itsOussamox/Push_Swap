/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:22:38 by obouadel          #+#    #+#             */
/*   Updated: 2021/11/11 16:11:13 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
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
	if (len <= ft_strlen(s) - start)
		sub = (char *)malloc(len + 1);
	else
		sub = (char *)malloc((ft_strlen(s) - start + 1));
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
