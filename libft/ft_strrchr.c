/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:52:18 by obouadel          #+#    #+#             */
/*   Updated: 2021/11/06 21:13:32 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr;
	int		isfound;
	int		save;

	isfound = 0;
	ptr = (char *)s;
	i = 0;
	while (ptr[i])
	{
		if (ptr[i] == (char)c)
		{
			save = i;
			isfound = 1;
		}
		i++;
	}
	if (isfound)
		return (&ptr[save]);
	if (ptr[i] == (char)c)
		return (&ptr[i]);
	return (0);
}
