/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:34:00 by obouadel          #+#    #+#             */
/*   Updated: 2021/12/20 15:53:43 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	getpos(t_data *data)
{
	int	i;
	int	j;
	int	pos;
	int	*ptr;

	i = 0;
	ptr = malloc((data->amaxsize) * sizeof(int));
	if (!ptr)
		end_program(data);
	while (i < data->amaxsize)
	{
		j = 0;
		pos = 0;
		while (j < data->amaxsize)
		{
			if (data->alist[i] > data->alist[j])
				pos++;
			j++;
		}
		ptr[i] = pos + 1;
		i++;
	}
	free(data->alist);
	data->alist = ptr;
}

int	get_max(t_data *data)
{
	int	i;
	int	biggest;

	i = 0;
	biggest = 0;
	while (i < data->amaxsize)
	{
		if (data->alist[i] > biggest)
			biggest = data->alist[i];
		i++;
	}
	return (biggest);
}

void	data_init(t_data *data, int ac)
{
	data->amaxsize = ac - 1;
	data->alist = malloc(data->amaxsize * sizeof(int));
	data->atop = 0;
	data->max_number = 0;
	data->bmaxsize = 0;
	data->blist = NULL;
	data->btop = 0;
}

void	data_fill(t_data *data, char **av)
{
	int	i;
	int	j;

	i = data->amaxsize - 1;
	j = 0;
	while (i >= 0)
	{
		data->alist[i] = atoi(av[j + 1]);
		j++;
		i--;
	}
	check_duplicate(data);
	getpos(data);
	data->atop = data->alist[data->amaxsize - 1];
	data->max_number = get_max(data);
}
