/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unsigned.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 20:45:52 by sde-spie          #+#    #+#             */
/*   Updated: 2018/09/13 00:19:06 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t	get_unsigned(t_conv *conv, va_list arg)
{
	uintmax_t value;

	if (conv->size_modif[3] == 1)
		return (va_arg(arg, unsigned long));
	else if (conv->size_modif[2] == 1)
		return (va_arg(arg, unsigned long long));
	else if (conv->size_modif[4] == 1)
		return (va_arg(arg, uint64_t));
	else if (conv->size_modif[5] == 1)
		return (va_arg(arg, size_t));
	value = va_arg(arg, unsigned int);
	if (conv->size_modif[0] == 1)
		value = (unsigned char)value;
	else if (conv->size_modif[1] == 1)
		value = (unsigned short)value;
	return (value);
}
