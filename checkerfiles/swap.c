/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:47:52 by obouadel          #+#    #+#             */
/*   Updated: 2021/12/20 15:25:18 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap_a(t_data *data)
{
	int	i;
	int	j;
	int	temp;

	i = data->amaxsize - 1;
	j = data->amaxsize - 2;
	temp = data->alist[i];
	data->alist[i] = data->alist[j];
	data->alist[j] = temp;
}

static void	swap_b(t_data *data)
{
	int	i;
	int	j;
	int	temp;

	i = data->bmaxsize - 1;
	j = data->bmaxsize - 2;
	temp = data->blist[i];
	data->blist[i] = data->blist[j];
	data->blist[j] = temp;
}

void	sa(t_data *data)
{
	if (data->alist && data->amaxsize >= 2)
		swap_a(data);
}

void	sb(t_data *data)
{
	if (data->blist && data->bmaxsize >= 2)
		swap_b(data);
}
