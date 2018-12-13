/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 22:57:44 by sde-spie          #+#    #+#             */
/*   Updated: 2018/12/13 17:57:46 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	easy_order(t_pile *c, t_data *data)
{
	int j;
	int i;

	i = 0;
	while (i < c->size)
	{
		j = i + 1;
		while (j < c->size)
		{
			if (c->pile[i] > c->pile[j])
				ft_swap(&c->pile[i], &c->pile[j]);
			j++;
		}
		i++;
	}
	data->max_val = c->pile[c->size - 1];
	data->nbr = data->size_max - 1;
	data->nbr2 = data->size_max;
	data->mediane = c->pile[data->size_max / 2];
	data->pivot = data->size_max / 2;
}
