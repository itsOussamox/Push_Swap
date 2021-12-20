/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:19:34 by obouadel          #+#    #+#             */
/*   Updated: 2021/11/08 20:06:17 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_lensw(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	char	*mysrc;

	mysrc = (char *)src;
	i = 0;
	while (i < dstsize - 1 && mysrc[i] != '\0' && dstsize != 0)
	{
		dst[i] = mysrc[i];
		i++;
	}
	if (dstsize != 0)
		dst[i] = '\0';
	return (ft_lensw(mysrc));
}
