/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 09:45:25 by sde-spie          #+#    #+#             */
/*   Updated: 2018/12/17 10:03:49 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		pbsara(t_pile *a, t_pile *b, t_data *data)
{
	sort_ft(a, b, data, "pb");
	sort_ft(a, b, data, "sa");
	sort_ft(a, b, data, "ra");
}

void		s_rra(t_pile *a, t_pile *b, t_pile *c, t_data *data)
{
	if (b->pile[b->size - 1] > data->pivot2)
		sort_ft(a, b, data, "rrr");
	else
		sort_ft(a, b, data, "rra");
}

void		s_rra2(t_pile *a, t_pile *b, t_pile *c, t_data *data)
{
	if (b->pile[b->size - 1] < data->pivot2)
		sort_ft(a, b, data, "rrr");
	else
		sort_ft(a, b, data, "rra");
}
