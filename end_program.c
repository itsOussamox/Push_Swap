/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:00:54 by obouadel          #+#    #+#             */
/*   Updated: 2021/12/20 15:53:46 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	end_program(t_data *data)
{
	if (data->alist)
		free(data->alist);
	if (data->blist)
		free(data->blist);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
