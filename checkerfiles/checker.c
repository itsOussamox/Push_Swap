/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 16:16:06 by obouadel          #+#    #+#             */
/*   Updated: 2021/12/20 16:43:28 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	check_instruct(char *instruct, t_data *data)
{
	if (!ft_strncmp("sa\n", instruct, 4))
		sa(data);
	else if (!ft_strncmp("sb\n", instruct, 4))
		sb(data);
	else if (!ft_strncmp("ss\n", instruct, 4))
		ss(data);
	else if (!ft_strncmp("ra\n", instruct, 4))
		ra(data);
	else if (!ft_strncmp("rb\n", instruct, 4))
		rb(data);
	else if (!ft_strncmp("rr\n", instruct, 4))
		rr(data);
	else if (!ft_strncmp("pa\n", instruct, 4))
		pa(data);
	else if (!ft_strncmp("pb\n", instruct, 4))
		pb(data);
	else if (!ft_strncmp("rra\n", instruct, 5))
		rra(data);
	else if (!ft_strncmp("rrb\n", instruct, 5))
		rrb(data);
	else if (!ft_strncmp("rrr\n", instruct, 5))
		rrr(data);
	else
		end_program(data);
}

static void	instruct_read(t_data *data)
{
	char	*instruct;

	while (1)
	{
		instruct = get_next_line(0);
		if (!instruct)
			break ;
		check_instruct(instruct, data);
		free(instruct);
	}
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
		write(1, "OK\n", 3);
		free(data.alist);
		return (0);
	}
	instruct_read(&data);
	if (is_asorted(data))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	if (data.alist)
		free(data.alist);
	return (0);
}
