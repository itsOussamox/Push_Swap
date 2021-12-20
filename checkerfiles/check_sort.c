/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:49:36 by obouadel          #+#    #+#             */
/*   Updated: 2021/12/20 15:14:07 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_asorted(t_data data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data.amaxsize)
	{
		j = i + 1;
		while (j < data.amaxsize)
		{
			if (data.alist[i] < data.alist[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_bsorted(t_data data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data.bmaxsize)
	{
		j = i + 1;
		while (j < data.bmaxsize)
		{
			if (data.blist[i] < data.blist[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
