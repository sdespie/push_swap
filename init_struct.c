/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 22:44:14 by sde-spie          #+#    #+#             */
/*   Updated: 2018/12/13 15:17:34 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		init_struct(t_pile *a, t_pile *b, t_pile *c, t_data *data)
{
	a->size = data->size_max;
	a->pile = malloc(sizeof(int) * data->size_max);
	b->size = 0;
	b->pile = malloc(sizeof(int) * data->size_max);
	c->size = data->size_max;
	c->pile = malloc(sizeof(int) * data->size_max);
	data->pos = 0;
	data->sorted = 0;
	data->error_p = 0;
	data->error_c = 0;
	data->error_sign = 0;
	data->nbr = 0;
	data->nbr2 = 0;
	data->option = 0;
	data->color = 0;
	data->start_index = 1;
	data->m = 0;
	data->speed = 4;
	data->eval1 = 0;
	data->eval2 = 0;
	data->mode = 0;
	if (!a->pile || !b->pile || !c->pile)
		return (ft_free(a, b, c, data));
	return (1);
}
