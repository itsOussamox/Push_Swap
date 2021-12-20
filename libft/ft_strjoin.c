/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:48:15 by obouadel          #+#    #+#             */
/*   Updated: 2021/11/11 17:29:52 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*table;
	int		index;
	int		len1;
	int		len2;

	if (str1 == 0)
		return (0);
	index = 0;
	table = 0;
	if (str2 == 0)
		len2 = 0;
	else
		len2 = ft_strlen((char *)str2);
	len1 = ft_strlen((char *)str1);
	table = (char *)ft_calloc(sizeof(char) * ((len1 + len2) + 1), sizeof(char));
	if (table == 0)
		return (0);
	ft_strlcat(table, str1, len1 + 1);
	ft_strlcat(table, str2, len1 + len2 + 1);
	return (table);
}
