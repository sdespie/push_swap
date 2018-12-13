/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:19:01 by sde-spie          #+#    #+#             */
/*   Updated: 2018/12/13 17:34:16 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		need_more_a(t_pile *a, t_pile *c, t_data *data, int nbr_ra)
{
	int i;
	int	check;

	check = 0;
	i = -1;
	while (++i < a->size - data->pos - nbr_ra)
		if (a->pile[i] < c->pile[data->pivot])
		{
			check++;
			//printf("pivot = %d, pos = %d, found = %d\n", c->pile[data->pivot], data->pos, a->pile[i]);
			break;
		}
	return (check);
}
