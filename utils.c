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

int		need_more_b(t_pile *b, t_pile *c, t_data *data, int pivot)
{
	int i;
	int	check;

	check = 0;
	i = -1;
	while (++i < b->size)
		if (b->pile[i] >= pivot)
		{
			check++;
			break;
		}
	return (check);
}

void	smart_rra(t_pile *a, t_pile *b, t_pile *c, t_data *data)
{
	if (b->pile[b->size - 1] > data->pivot2)
		sort_ft(a, b, data, "rrr");
	else
		sort_ft(a, b, data, "rra");
}

void	smart_rra2(t_pile *a, t_pile *b, t_pile *c, t_data *data)
{
	if (b->pile[b->size - 1] < data->pivot2)
		sort_ft(a, b, data, "rrr");
	else
		sort_ft(a, b, data, "rra");
}

void	smart_ra1(t_pile *a, t_pile *b, t_pile *c, t_data *data, int pivot)
{
	if (b->pile[0] > c->pile[pivot])
		sort_ft(a, b, data, "rr");
	else
		sort_ft(a, b, data, "ra");
}

void	smart_ra2(t_pile *a, t_pile *b, t_pile *c, t_data *data, int pivot)
{
	if (b->pile[0] < c->pile[pivot])
		sort_ft(a, b, data, "rr");
	else
		sort_ft(a, b, data, "ra");
}
