/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 22:44:14 by sde-spie          #+#    #+#             */
/*   Updated: 2018/12/17 10:16:37 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			while_mode(t_pile *a, t_pile *b, t_pile *c, t_data *data)
{
	if (a->pile[0] <= c->pile[data->pivot])
		sort_ft(a, b, data, "pb");
	else
	{
		if (data->mode == -1 || data->mode == 1)
			smart_ra1(a, b, data, c->pile[data->pos + data->nbr / 4]);
		else
			smart_ra2(a, b, data, c->pile[data->pos + data->nbr / 4]);
		return (1);
	}
	return (0);
}

void		reset_pile(t_pile *a, t_pile *b, t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->size_max)
	{
		a->pile[i] = 0;
		b->pile[i] = 0;
	}
	a->size = data->size_max;
	b->size = 0;
	data->pos = 0;
	data->sorted = 0;
	data->nbr = 0;
	data->nbr2 = 0;
}

void		solve2(t_pile *a, t_pile *b, t_pile *c, t_data *data)
{
	data->mode = -1;
	solve(a, b, c, data);
	reset_pile(a, b, data);
	fill_pile(a, b, data);
	data->mode = -2;
	solve(a, b, c, data);
	reset_pile(a, b, data);
	fill_pile(a, b, data);
	if (data->eval1 < data->eval2)
		data->mode = 1;
	else
		data->mode = 2;
	solve(a, b, c, data);
}

void		print_mode(t_pile *a, t_pile *b, t_data *data, char *mode)
{
	if (data->mode == -1)
		data->eval1++;
	else if (data->mode == -2)
		data->eval2++;
	else
		data->option == 0 ? ft_printf("%s\n", mode) : p_color(a, b, data);
}
