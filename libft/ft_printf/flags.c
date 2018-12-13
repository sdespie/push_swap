/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 21:59:55 by sde-spie          #+#    #+#             */
/*   Updated: 2018/08/22 18:00:29 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		set_flags(t_conv *conv, char f)
{
	if (f == '#')
		conv->sign = 1;
	if (f == '-')
		conv->minus = 1;
	if (f == '+')
		conv->plus = 1;
	if (f == '0')
		conv->zero = 1;
	if (f == ' ')
		conv->space = 1;
}

bool		flags(t_conv *conv, char f)
{
	char *flag_list;

	if (conv->zero == 0)
		flag_list = "#+- 0";
	else
		flag_list = "#+- ";
	while (*flag_list)
	{
		if (f == *flag_list)
			return (1);
		flag_list++;
	}
	return (0);
}
