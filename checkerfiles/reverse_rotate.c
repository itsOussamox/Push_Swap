/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:09:52 by obouadel          #+#    #+#             */
/*   Updated: 2021/12/20 15:24:11 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rrotate_a(t_data *data)
{
	int	i;
	int	j;
	int	*newlist;

	i = 0;
	j = data->amaxsize - 1;
	newlist = malloc(data->amaxsize * sizeof(int));
	if (!newlist)
		end_program(data);
	while (i < data->amaxsize)
	{
		newlist[j] = data->alist[i];
		if (data->amaxsize - 1 == j)
			j = 0;
		else
			j++;
		i++;
	}
	free(data->alist);
	data->alist = newlist;
	data->atop = data->alist[data->amaxsize - 1];
}

void	rra(t_data *data)
{
	if (data->alist)
		rrotate_a(data);
}

static void	rrotate_b(t_data *data)
{
	int	i;
	int	j;
	int	*newlist;

	i = 0;
	j = data->bmaxsize - 1;
	newlist = malloc(data->bmaxsize * sizeof(int));
	if (!newlist)
		end_program(data);
	while (i < data->bmaxsize)
	{
		newlist[j] = data->blist[i];
		if (data->bmaxsize - 1 == j)
			j = 0;
		else
			j++;
		i++;
	}
	free(data->blist);
	data->blist = newlist;
	data->blist[data->bmaxsize - 1] = data->alist[data->amaxsize - 1];
}

void	rrb(t_data *data)
{
	if (data->blist)
		rrotate_b(data);
}
