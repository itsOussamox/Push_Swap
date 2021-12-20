/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:43:13 by obouadel          #+#    #+#             */
/*   Updated: 2021/12/19 21:42:11 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"
# include "./gnl/get_next_line.h"

typedef struct s_data
{
	int	amaxsize;
	int	atop;
	int	*alist;
	int	max_number;
	int	bmaxsize;
	int	btop;
	int	*blist;
}	t_data;

long long	ft_atoll(const char *str);
int			is_asorted(t_data data);
int			is_bsorted(t_data data);
void		check_duplicate(t_data *data);
void		end_program(t_data *data);
void		data_init(t_data *data, int ac);
void		data_fill(t_data *data, char **av);
int			get_max(t_data *data);
void		rra(t_data *data);
void		rrb(t_data *data);
void		ra(t_data *data);
void		rb(t_data *data);
void		pa(t_data *data);
void		pb(t_data *data);
void		sa(t_data *data);
void		sb(t_data *data);
void		ss(t_data *data);
void		rr(t_data *data);
void		rrr(t_data *data);
void		data_check(int ac, char **av, t_data *data);

#endif