/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 09:47:26 by obouadel          #+#    #+#             */
/*   Updated: 2021/11/07 11:44:36 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char	*str, int c)
{
	int		i;
	char	*ptr;
	char	to_find;

	to_find = (char) c;
	ptr = (char *)str;
	i = 0;
	while (ptr[i])
	{
		if (ptr[i] == to_find)
			return (&ptr[i]);
		i++;
	}
	if (ptr[i] == to_find)
		return (&ptr[i]);
	return (0);
}
