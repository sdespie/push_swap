/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:19:01 by sde-spie          #+#    #+#             */
/*   Updated: 2018/12/14 14:25:34 by sde-spie         ###   ########.fr       */
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
			break;
		}
	return (check);
}

int		need_more_b(t_pile *a, t_pile *c, t_data *data, int pivot)
{
	int i;
	int	check;

	check = 0;
	i = -1;
	while (++i < a->size && ft_printf("pivot2 = %d, b->[0] = %d\n", pivot, a->pile[0]))
		if (a->pile[i] <= pivot)
		{
			ft_printf("cond\n");
			check++;
			break;
		}
	return (check);
}
