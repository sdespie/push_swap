/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 13:23:51 by sde-spie          #+#    #+#             */
/*   Updated: 2018/12/13 14:20:53 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_lowest(t_pile *a, t_pile *b, t_pile *c, t_data *data)
{
	int	min;
	int	i;
	int	pos;

	min = data->max_val;
	i = -1;
	pos = 0;
	while (++i < a->size)
		if (a->pile[i] < min)
		{
			min = a->pile[i];
			pos = i;
		}
	return (pos);
}

void	sort_mini(t_pile *a, t_pile *b, t_pile *c, t_data *data)
{
	int	pos;
	int	iter;

	pos = find_lowest(a, b, c, data);
	if (pos <= a->size / 2)
	{
		iter = pos;
		while (iter-- > 0)
			sort_ft(a, b, data, "ra");
	}
	else
	{
		iter = a->size - pos;
		while (iter-- > 0)
			sort_ft(a, b, data, "rra");
	}
	sort_ft(a, b, data, "pb");
}

int		mini_sort(t_pile *a, t_pile *b, t_pile *c, t_data *data)
{
	while (a->size > 3)
		sort_mini(a, b, c, data);
	sort_short(a, b, c, data);
	while (b->size)
		sort_ft(a, b, data, "pa");
	return (1);
}
