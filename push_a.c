/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:16:50 by marvin            #+#    #+#             */
/*   Updated: 2021/12/20 15:42:58 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_a(t_data *data)
{
	int	*newbie;
	int	i;

	i = 0;
	newbie = malloc((data->amaxsize + 1) * sizeof(int));
	if (!newbie)
		end_program(data);
	if (data->alist)
	{
		while (i < data->amaxsize)
		{	
			newbie[i] = data->alist[i];
			i++;
		}
		free(data->alist);
	}
	newbie[i] = data->blist[data->bmaxsize - 1];
	data->amaxsize++;
	data->alist = newbie;
	data->atop = data->blist[data->bmaxsize - 1];
}

static void	del_b(t_data *data)
{
	int	*newbie;
	int	i;

	if (data->bmaxsize == 1)
	{
		free(data->blist);
		data->blist = NULL;
		data->bmaxsize = 0;
		data->btop = 0;
		return ;
	}
	i = 0;
	newbie = malloc((data->bmaxsize - 1) * sizeof(int));
	if (!newbie)
		end_program(data);
	while (i < data->bmaxsize - 1)
	{
		newbie[i] = data->blist[i];
		i++;
	}
	free(data->blist);
	data->blist = newbie;
	data->bmaxsize--;
	data->btop = data->blist[data->bmaxsize - 1];
}

void	pa(t_data *data)
{
	if (data->bmaxsize)
	{
		add_a(data);
		del_b(data);
		write(1, "pa\n", 3);
	}
}
