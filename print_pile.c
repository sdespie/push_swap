/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 16:34:21 by sde-spie          #+#    #+#             */
/*   Updated: 2018/12/17 10:16:16 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define ABS(x) ((x < 0) ? -x : x)
#define R "\x1b[41m"
#define G "\x1b[42m"
#define Y "\x1b[43m"
#define LY "\x1b[103m"
#define B "\x1b[44m"
#define L "\x1b[104m"
#define M "\x1b[45m"
#define CYAN "\x1b[46m"
#define LC "\x1b[106m"
#define RES "\x1b[0m"

static char		*set_color(t_pile *a, t_data *data, int mode, int i)
{
	if (mode == 0)
	{
		if (data->m && a->pile[i] == data->pivot)
			return (data->color == 1 ? R : G);
		if (a->pile[i] < 0 && data->color == 1)
			return (LC);
		if (a->pile[i] >= 0 && data->color == 1)
			return (CYAN);
		return (a->pile[i] < 0 ? M : R);
	}
	if (mode == 1)
	{
		if (data->m && a->pile[i] == data->pivot2)
			return (data->color == 1 ? R : G);
		if (a->pile[i] < 0 && data->color == 1)
			return (LY);
		if (a->pile[i] >= 0 && data->color == 1)
			return (Y);
		return (a->pile[i] < 0 ? L : B);
	}
	return (0);
}

void			p_color(t_pile *a, t_pile *b, t_data *data)
{
	int		i;
	char	*ca;
	char	*cb;

	usleep(15000 * ((10 - data->speed) * (10 - data->speed)));
	system("clear");
	i = 0;
	printf("\n");
	while (i < a->size || i < b->size)
	{
		ca = set_color(a, data, 0, i);
		cb = set_color(b, data, 1, i);
		if (i >= a->size && i < b->size)
			printf("%*s  %s%*d%s\n", data->p_max + 9, cb, "", ABS(b->pile[i]),
			b->pile[i], RES);
		else if (i >= b->size && i < a->size)
			printf("%s%*d%s    %s%*s%s\n", ca, ABS(a->pile[i]), a->pile[i],
				RES, cb, 0, "", RES);
		else
			printf("%s%*d%s  %*s  %s%*d%s\n", ca, ABS(a->pile[i]), a->pile[i],
			RES, data->p_max - ABS(a->pile[i]) - ((a->pile[i] > -2 &&
			a->pile[i] < 1) ? 1 : 0), "", cb, ABS(b->pile[i]), b->pile[i], RES);
		i++;
	}
}
