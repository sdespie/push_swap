/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 10:17:39 by sde-spie          #+#    #+#             */
/*   Updated: 2018/11/30 11:46:41 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_free(t_pile *a, t_pile *b, t_pile *c, t_data *data)
{
	if (a->pile)
		free(a->pile);
	if (b->pile)
		free(b->pile);
	if (c->pile)
		free(c->pile);
	if (a)
		free(a);
	if (b)
		free(b);
	if (c)
		free(c);
	if (data)
		free(data);
	return (ft_printf("Error\n"));
}

int	ft_free_end(t_pile *a, t_pile *b, t_pile *c, t_data *data)
{
	if (a->pile)
		free(a->pile);
	if (b->pile)
		free(b->pile);
	if (c->pile)
		free(c->pile);
	if (a)
		free(a);
	if (b)
		free(b);
	if (c)
		free(c);
	if (data)
		free(data);
	return (0);
}
