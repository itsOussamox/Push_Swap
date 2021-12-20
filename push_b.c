/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:03:16 by marvin            #+#    #+#             */
/*   Updated: 2021/12/20 15:43:56 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_b(t_data *data)
{
	int	*newbie;
	int	i;

	i = 0;
	newbie = malloc((data->bmaxsize + 1) * sizeof(int));
	if (!newbie)
		end_program(data);
	if (data->blist)
	{
		while (i < data->bmaxsize)
		{	
			newbie[i] = data->blist[i];
			i++;
		}
		free(data->blist);
	}
	newbie[i] = data->atop;
	data->bmaxsize++;
	data->blist = newbie;
	data->btop = data->blist[data->bmaxsize - 1];
}

static void	del_a(t_data *data)
{
	int	*newbie;
	int	i;

	if (data->amaxsize == 1)
	{
		free(data->alist);
		data->alist = NULL;
		data->amaxsize = 0;
		data->atop = 0;
		return ;
	}
	i = 0;
	newbie = malloc((data->amaxsize - 1) * sizeof(int));
	if (!newbie)
		end_program(data);
	while (i < data->amaxsize - 1)
	{
		newbie[i] = data->alist[i];
		i++;
	}
	free(data->alist);
	data->alist = newbie;
	data->amaxsize--;
	data->atop = data->alist[data->amaxsize - 1];
}

void	pb(t_data	*data)
{
	if (data->amaxsize)
	{
		add_b(data);
		del_a(data);
		write(1, "pb\n", 3);
	}
}
