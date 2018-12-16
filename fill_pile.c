/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 22:51:43 by sde-spie          #+#    #+#             */
/*   Updated: 2018/12/13 15:40:46 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define ABS(x) ((x < 0) ? -x : x)

static void	check_multiple(t_pile *a, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->size)
	{
		j = i + 1;
		while (j < a->size)
			if (a->pile[i] == a->pile[j++])
			{
				data->error_p++;
				return ;
			}
		i++;
	}
}

void		fill_pile(t_pile *a, t_pile *c, t_data *data)
{
	int	i;

	i = -1;
	data->p_max = ABS(ft_atoi2(data->argv[data->start_index], data));
	while (++i < a->size)
	{
		if (ft_atoi2(data->argv[i + data->start_index], data)\
			== ft_atol2(data->argv[i + data->start_index], data))
		{
			a->pile[i] = ft_atoi(data->argv[i + data->start_index]);
			c->pile[i] = a->pile[i];
			if (ABS(a->pile[i]) > data->p_max)
				data->p_max = ABS(a->pile[i]);
		}
		else
		{
			data->error_p++;
			break ;
		}
	}
	check_multiple(a, data);
}
