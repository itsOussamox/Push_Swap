/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:27:20 by obouadel          #+#    #+#             */
/*   Updated: 2021/12/20 15:46:23 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	big_sort(t_data *data)
{
	int	maxshift;
	int	i;
	int	j;
	int	max;

	i = -1;
	maxshift = 0;
	max = data->amaxsize;
	while ((data->max_number >> maxshift) != 0)
		maxshift++;
	while (++i < maxshift)
	{
		j = -1;
		while (++j < max)
		{
			if (((data->atop >> i) & 1) == 1)
				ra(data);
			else
				pb(data);
		}
		while (data->blist)
			pa(data);
	}
}

static void	lilsort(t_data *data)
{
	int	*tab;

	tab = data->alist;
	if (tab[2] > tab[1] && tab[1] < tab[0] && tab[2] > tab[0])
		ra(data);
	if (tab[2] > tab[1] && tab[1] > tab[0] && tab[2] > tab[0])
	{
		ra(data);
		sa(data);
	}
	if (tab[2] > tab[1] && tab[1] < tab[0] && tab[2] < tab[0])
		sa(data);
	if (tab[2] < tab[1] && tab[1] > tab[0] && tab[2] > tab[0])
		rra(data);
	if (tab[2] < tab[1] && tab[1] > tab[0] && tab[2] < tab[0])
	{
		sa(data);
		ra(data);
	}
}

static void	low_sort(t_data *data)
{
	int	max;
	int	mid;
	int	i;

	i = -1;
	max = data->amaxsize;
	mid = data->max_number / 2;
	if (data->max_number % 2)
		mid = data->max_number / 2 + 1;
	while (++i < max && max > 3)
	{
		if (data->alist[data->amaxsize - 1] < mid)
			pb(data);
		else
			ra(data);
	}
	lilsort(data);
	if (data->bmaxsize == 2)
		if (data->blist[data->bmaxsize - 1] < data->blist[data->bmaxsize - 2])
			sb(data);
	while (data->blist)
		pa(data);
}

int	main(int ac, char **av)
{
	t_data	data;

	data.alist = NULL;
	if (ac < 2)
		return (0);
	data_check(ac, av, &data);
	data_init(&data, ac);
	data_fill(&data, av);
	if (is_asorted(data))
	{
		free(data.alist);
		return (0);
	}
	else if (data.amaxsize == 2)
		sa(&data);
	else if (data.amaxsize <= 5)
		low_sort(&data);
	else
		big_sort(&data);
	if (data.alist)
		free(data.alist);
	return (0);
}
