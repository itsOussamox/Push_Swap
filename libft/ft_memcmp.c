/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:52:16 by obouadel          #+#    #+#             */
/*   Updated: 2021/11/07 11:53:44 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t len)
{
	size_t			i;
	unsigned char	*mys1;
	unsigned char	*mys2;

	mys1 = (unsigned char *)s1;
	mys2 = (unsigned char *)s2;
	i = 0;
	while (i < len)
	{
		if ((unsigned char)mys1[i] != (unsigned char)mys2[i])
			return ((unsigned char)mys1[i] - (unsigned char)mys2[i]);
		i++;
	}
	return (0);
}
