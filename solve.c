/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 11:22:55 by sde-spie          #+#    #+#             */
/*   Updated: 2018/12/13 18:25:33 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			is_sorted(t_pile a, t_pile c)
{
	int	i;

	i = 0;
	while (i < c.size)
	{
		if (a.pile[i] != c.pile[i])
			return (0);
		i++;
	}
	return (1);
}

static int	sort(t_pile *a, t_pile *b, t_pile *c, t_data *data)
{
	int	check;

	if (is_sorted(*a, *c))
		return (0);
	check = 0;
	if (a->pile[0] == c->pile[data->pos] && ++data->pos && ++check)
		sort_ft(a, b, data, "ra");
	else if (a->pile[1] == c->pile[data->pos] && ++data->pos && ++check)
	{
		sort_ft(a, b, data, "sa");
		sort_ft(a, b, data, "ra");
	}
	else if (b->pile[0] == c->pile[data->pos] && ++data->pos && ++check)
	{
		sort_ft(a, b, data, "pa");
		sort_ft(a, b, data, "ra");
	}
	else if (b->pile[1] == c->pile[data->pos] && ++data->pos && ++check)
	{
		sort_ft(a, b, data, "sb");
		sort_ft(a, b, data, "pa");
		sort_ft(a, b, data, "ra");
	}
	return (check);
}

static void	quick_sort_a(t_pile *a, t_pile *b, t_pile *c, t_data *data)
{
	int	i;
	int	max;
	int	nbr_ra;

	nbr_ra = 0;
	i = -1;
	printf("===============================\n");
	data->pivot = data->pos + data->nbr / 2;
	max = c->pile[data->pos + data->nbr];
	printf("pivot = %d (", data->pivot);
	printf("pos = %d + ", data->pos);
	printf("nbr = %d / 2) \n", data->nbr);
	printf("val pivot = %d\n", c->pile[data->pos]);
	printf("max = %d\n\n", max);
	while (++i < data->nbr * 1.1 && !(data->pos && a->pile[0] == c->pile[0])
			&& a->pile[0] <= max && need_more_a(a, c, data, nbr_ra))
	{
		if (a->pile[0] <= c->pile[data->pivot])
			sort_ft(a, b, data, "pb");
		else
		{
			sort_ft(a, b, data, "ra");
			nbr_ra++;
		}
	}
	if (data->pos)
		while (a->pile[a->size - 1] != c->pile[data->pos - 1])
			sort_ft(a, b, data, "rra");
	if (b->size)
		quick_sort_b(a, b, c, data);
}

void		quick_sort_b(t_pile *a, t_pile *b, t_pile *c, t_data *data)
{
	int	i;
	int	size;
	int	nb_pa;
	int	nb_rb;

	nb_pa = 0;
	nb_rb = 0;
	size = b->size;
	i = -1;
	data->pivot2 = size / 2 + data->pos;
	while (++i < size)
	{
		while (sort(a, b, c, data))
			;
		if (b->pile[0] >= c->pile[data->pivot2] && ++nb_pa)
			sort_ft(a, b, data, "pa");
		else if (++nb_rb)
			sort_ft(a, b, data, "rb");
	}
	if (b->size)
		quick_sort_b(a, b, c, data);
	data->nbr = nb_pa;
	quick_sort_a(a, b, c, data);
	data->nbr = nb_rb;
	quick_sort_a(a, b, c, data);
}

void		solve(t_pile *a, t_pile *b, t_pile *c, t_data *data)
{
	if (is_sorted(*a, *c))
		return ;
	if (!is_sorted(*a, *c))
	{
		if (data->size_max <= 3)
			sort_short(a, b, c, data);
		else if (data->size_max <= 10)
			mini_sort(a, b, c, data);
		else if (!is_sorted(*a, *c))
		{
			printf("lets go quick a\n");
			quick_sort_a(a, b, c, data);
			data->nbr = data->nbr2 / 2;
			data->nbr2 = data->nbr;
			solve(a, b, c, data);
		}
	}
}
