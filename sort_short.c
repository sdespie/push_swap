/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 14:16:46 by sde-spie          #+#    #+#             */
/*   Updated: 2018/11/30 15:26:29 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	bot_is_sorted(t_pile *a, t_pile *c)
{
	int i;
	int j;

	j = c->size - 1;
	i = a->size - 1;
	while (i >= 0)
	{
		if (a->pile[i--] != c->pile[j--])
			return (0);
	}
	return (1);
}

void		sort_short(t_pile *a, t_pile *b, t_pile *c, t_data *data)
{
	if (is_sorted(*a, *c))
		return ;
	if (bot_is_sorted(a, c) && b->size)
		while (b->size)
			sort_ft(a, b, data, "pa");
	else if (a->size == 2)
		a->pile[0] > a->pile[1] ? sort_ft(a, b, data, "sa") : 0;
	else
	{
		if (a->pile[0] == c->pile[data->pos] && ++data->pos)
			sort_ft(a, b, data, "pb");
		else if (a->pile[0] > a->pile[a->size - 1])
			sort_ft(a, b, data, "ra");
		else if (a->size == 3 && a->pile[0] > a->pile[1])
			sort_ft(a, b, data, "sa");
		else if (a->pile[a->size - 1] == c->pile[data->pos] && ++data->pos)
			sort_ft(a, b, data, "rra");
		else
			sort_ft(a, b, data, "ra");
	}
	sort_short(a, b, c, data);
}
