/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 21:50:01 by sde-spie          #+#    #+#             */
/*   Updated: 2018/12/17 10:24:56 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	apply_inst(t_pile *a, t_pile *b, t_data *data)
{
	char *line;

	while (get_next_line(0, &line) == 1)
	{
		sort_ft(a, b, data, line);
		free(line);
	}
}

int			main(int argc, char **argv)
{
	t_pile	*a;
	t_pile	*b;
	t_pile	*c;
	t_data	*data;

	a = malloc(sizeof(t_pile));
	b = malloc(sizeof(t_pile));
	c = malloc(sizeof(t_pile));
	data = malloc(sizeof(t_data));
	if (!(a && b && c && data))
		return (ft_free(a, b, c, data));
	data->size_max = argc - 1;
	if (!init_struct(a, b, c, data))
		return (ft_free(a, b, c, data));
	data->argv = argv;
	fill_pile(a, c, data);
	easy_order(c, data);
	if (argc > 1)
	{
		apply_inst(a, b, data);
		if (data->error_c != 0 || data->error_p != 0)
			return (ft_free(a, b, c, data));
		is_sorted(*a, *c) ? ft_printf("OK\n") : ft_printf("KO\n");
	}
	return (ft_free_end(a, b, c, data));
}
