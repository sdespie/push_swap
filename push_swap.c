/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 18:01:37 by sde-spie          #+#    #+#             */
/*   Updated: 2018/12/14 12:08:20 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	option(t_data *data, char **argv)
{
	if (argv[1][0] == '-' && argv[1][1] == 'o')
	{
		data->start_index = 2;
		if (ft_strchr(argv[1], 'v'))
			data->option = 2;
		if (ft_strchr(argv[1], 'm'))
			data->m = 1;
		if (ft_isdigit(argv[1][2]))
			data->speed = argv[1][2] - 48;
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
	data->start_index = argv[1][0] == '-' && argv[1][1] == 'o' ? 2 : 1;
	data->size_max = argc - data->start_index;
	if (!init_struct(a, b, c, data))
		return (ft_free_end(a, b, c, data));
	data->argv = argv;
	option(data, argv);
	fill_pile(a, c, data);
	if (data->error_p != 0)
		return (ft_free(a, b, c, data));
	easy_order(c, data);
	solve2(a, b, c, data);
	ft_free_end(a, b, c, data);
	return (0);
}
