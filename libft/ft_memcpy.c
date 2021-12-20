/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:31:09 by obouadel          #+#    #+#             */
/*   Updated: 2021/11/07 11:54:39 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*mydst;
	char	*mysrc;
	size_t	i;

	i = 0;
	mydst = (char *)dst;
	mysrc = (char *)src;
	if (mydst == 0 && mysrc == 0)
		return (0);
	while (n > i)
	{
		mydst[i] = mysrc[i];
		i++;
	}
	return (dst);
}
