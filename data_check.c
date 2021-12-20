/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:18:11 by obouadel          #+#    #+#             */
/*   Updated: 2021/12/20 17:44:56 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_limit(int ac, char **av, t_data *data)
{
	long long	n;
	int			i;

	i = 1;
	while (i < ac)
	{
		n = atoll(av[i++]);
		if (n > 2147483647 || n < -2147483648)
			end_program(data);
	}
}

static void	check_numeric(int ac, char **av, t_data *data)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		if (av[i][j] == '\0')
			end_program(data);
		while (av[i][j])
		{
			if (av[i][j] == '-')
				j++;
			if (!ft_isdigit(av[i][j]))
				end_program(data);
			j++;
		}
		i++;
	}
}

void	check_duplicate(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->amaxsize)
	{
		j = i + 1;
		while (j < data->amaxsize)
		{
			if (data->alist[j] == data->alist[i])
				end_program(data);
			j++;
		}
		i++;
	}
}

void	data_check(int ac, char **av, t_data *data)
{
	check_numeric(ac, av, data);
	check_limit(ac, av, data);
}
