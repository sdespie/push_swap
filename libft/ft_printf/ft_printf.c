/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 16:38:22 by sde-spie          #+#    #+#             */
/*   Updated: 2018/09/13 00:58:14 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *format, ...)
{
	va_list	arg;
	int		tot_char;

	tot_char = 0;
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
			manage_pc(&format, arg, &tot_char);
		else
		{
			ft_putchar(*format);
			tot_char++;
			format++;
		}
	}
	va_end(arg);
	return (tot_char);
}
