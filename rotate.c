/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:58:39 by obouadel          #+#    #+#             */
/*   Updated: 2021/12/20 15:44:10 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_a(t_data *data)
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
		newlist[i] = data->alist[j];
		if (data->amaxsize - 1 == j)
			j = 0;
		else
			j++;
		i++;
	}
	free(data->alist);
	data->alist = newlist;
	data->atop = data->alist[data->amaxsize - 1];
	write(1, "ra\n", 3);
}

static void	rotate_b(t_data *data)
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
		newlist[i] = data->blist[j];
		if (data->bmaxsize - 1 == j)
			j = 0;
		else
			j++;
		i++;
	}
	free(data->blist);
	data->blist = newlist;
	data->btop = data->blist[data->bmaxsize - 1];
	write(1, "rb\n", 3);
}

void	ra(t_data *data)
{
	if (data->alist)
		rotate_a(data);
}

void	rb(t_data *data)
{
	if (data->blist)
		rotate_b(data);
}
