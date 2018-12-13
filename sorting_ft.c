/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_ft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 17:02:03 by sde-spie          #+#    #+#             */
/*   Updated: 2018/12/13 14:15:56 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_pile *a, t_pile *b)
{
	int	i;

	if (!b->size)
		return ;
	i = a->size;
	a->size++;
	while (i > 0)
	{
		a->pile[i] = a->pile[i - 1];
		i--;
	}
	a->pile[0] = b->pile[0];
	i = 0;
	while (i < b->size - 1)
	{
		b->pile[i] = b->pile[i + 1];
		i++;
	}
	b->size--;
}

void	swap(t_pile *a)
{
	if (a->size >= 2)
		ft_swap(&(a->pile[0]), &(a->pile[1]));
	else
		return ;
}

void	rotate(t_pile *a)
{
	int	i;
	int	tmp;

	if (!a->size)
		return ;
	i = 0;
	tmp = a->pile[0];
	while (i < a->size)
	{
		a->pile[i] = a->pile[i + 1];
		i++;
	}
	a->pile[i - 1] = tmp;
}

void	rev_rotate(t_pile *a)
{
	int	i;
	int	tmp;

	if (!a->size)
		return ;
	i = a->size - 1;
	tmp = a->pile[i];
	while (i > 0)
	{
		a->pile[i] = a->pile[i - 1];
		i--;
	}
	a->pile[i] = tmp;
}

void	sort_ft(t_pile *a, t_pile *b, t_data *data, char *mode)
{
	int check;

	check = 0;
	if ((!ft_strcmp(mode, "pa") || !ft_strcmp(mode, "pb")) && ++check)
		!ft_strcmp(mode, "pa") ? push(a, b) : push(b, a);
	else if ((!ft_strcmp(mode, "sa") || !ft_strcmp(mode, "sb")) && ++check)
		!ft_strcmp(mode, "sa") ? swap(a) : swap(b);
	else if ((!ft_strcmp(mode, "ra") || !ft_strcmp(mode, "rb")) && ++check)
		!ft_strcmp(mode, "ra") ? rotate(a) : rotate(b);
	else if (!ft_strcmp(mode, "rr") && ++check)
		rotate(a);
	if ((!ft_strcmp(mode, "rr")) && ++check)
		rotate(b);
	else if ((!ft_strcmp(mode, "ss")) && ++check)
		swap(a);
	if ((!ft_strcmp(mode, "ss")) && ++check)
		swap(b);
	else if ((!ft_strcmp(mode, "rra") || !ft_strcmp(mode, "rrb")) && ++check)
		!ft_strcmp(mode, "rra") ? rev_rotate(a) : rev_rotate(b);
	else if (!ft_strcmp(mode, "rrr") && ++check)
		rev_rotate(a);
	!ft_strcmp(mode, "rrr") && ++check ? rev_rotate(b) : 0;
	data->option == 0 ? ft_printf("%s\n", mode) : p_color(a, b, data);
	check == 0 ? data->error_c++ : 0;
}
