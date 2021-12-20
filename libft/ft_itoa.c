/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 20:40:33 by obouadel          #+#    #+#             */
/*   Updated: 2021/11/06 21:20:56 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_abs(int n)
{
	unsigned int	nb;

	nb = 0;
	if (n < 0)
		nb = -n;
	else
		nb = n;
	return (nb);
}

static int	ft_numlen(int n)
{
	int	count;

	count = 0;
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char	*ft_reverse(char *str)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = 0;
	while (str[j])
		j++;
	j--;
	while (i <= j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	len;
	int				sign;
	int				i;

	sign = (n < 0);
	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	str = (char *)ft_calloc((ft_numlen(n) + sign + 1), sizeof(char));
	if (!str)
		return (0);
	if (n == 0)
		str[0] = '0';
	len = ft_abs(n);
	while (len)
	{
		str[i] = len % 10 + '0';
		len = len / 10;
		i++;
	}
	if (sign)
		str[i] = '-';
	str = ft_reverse(str);
	return (str);
}
