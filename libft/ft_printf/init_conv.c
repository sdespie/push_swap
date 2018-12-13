/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 23:01:13 by sde-spie          #+#    #+#             */
/*   Updated: 2018/09/13 00:19:23 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		init_conv(t_conv *conv)
{
	conv->sign = 0;
	conv->zero = 0;
	conv->plus = 0;
	conv->minus = 0;
	conv->dot = 0;
	conv->space = 0;
	conv->format_conv = 0;
	conv->width = 0;
	conv->precis = 0;
	conv->size_modif[0] = 0;
	conv->size_modif[1] = 0;
	conv->size_modif[2] = 0;
	conv->size_modif[3] = 0;
	conv->size_modif[4] = 0;
	conv->size_modif[5] = 0;
}
