/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 16:34:21 by sde-spie          #+#    #+#             */
/*   Updated: 2018/12/13 15:35:22 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define ABS(x) ((x < 0) ? -x : x)
#define RED		"\x1b[41m"
#define GREEN	"\x1b[42m"
#define YELLOW	"\x1b[43m"
#define LY		"\x1b[103m"
#define BLUE	"\x1b[44m"
#define LB		"\x1b[104m"
#define MAGENTA	"\x1b[45m"
#define CYAN	"\x1b[46m"
#define LC		"\x1b[106m"
#define RESET	"\x1b[0m"

void	p_color(t_pile *a, t_pile *b, t_data *data)
{
	int i;

	usleep(10000 * (1 + (10 - data->speed + 1) * (10 - data->speed + 1) / 2));
	system("clear");
	i = 0;
	printf("\n");
	while (i < a->size || i < b->size)
	{
		if (i >= a->size && i < b->size)
            printf("%*s  %s%*d%s\n",
				 data->p_max + 9, (b->pile[i] < 0 ? LB : BLUE),
				"", ABS(b->pile[i]), b->pile[i], RESET);
        else if (i >= b->size && i < a->size)
            printf("%s%*d%s    %s%*s%s\n", (a->pile[i] < 0 ? MAGENTA : RED),
				ABS(a->pile[i]), a->pile[i], RESET, 
				(b->pile[i] < 0 ? LB : BLUE), 0, "", RESET);
        else
            printf("%s%*d%s  %*s  %s%*d%s\n", (a->pile[i] < 0 ? MAGENTA : RED),
				ABS(a->pile[i]), a->pile[i], RESET, data->p_max -
				ABS(a->pile[i]) - ((a->pile[i] > -2 && a->pile[i] < 1) ? 1
					: 0), "", (b->pile[i] < 0 ? LB : BLUE),
				ABS(b->pile[i]), b->pile[i], RESET);
		i++;
	}
}
