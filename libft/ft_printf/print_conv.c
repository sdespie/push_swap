/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 23:16:58 by sde-spie          #+#    #+#             */
/*   Updated: 2018/09/13 00:24:08 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_conv(t_conv *conv, va_list arg, int *nb)
{
	if (conv->format_conv == 's' && !(conv->size_modif[3] == 1))
		print_s(conv, arg, nb);
	else if (conv->format_conv == 'S'
			|| ((conv->size_modif[3] == 1) && conv->format_conv == 's'))
		print_s_upper(conv, arg, nb);
	else if (conv->format_conv == 'd' || conv->format_conv == 'D'
			|| conv->format_conv == 'i')
		print_d(conv, arg, nb);
	else if (conv->format_conv == 'p')
		print_p(conv, arg, nb);
	else if (conv->format_conv == 'c' && !(conv->size_modif[3] == 1))
		print_c(conv, arg, nb);
	else if (conv->format_conv == 'C'
			|| ((conv->size_modif[3]) && conv->format_conv == 'c'))
		print_wchar(conv, arg, nb);
	else if (conv->format_conv == 'o' || conv->format_conv == 'O')
		print_o(conv, arg, nb);
	else if (conv->format_conv == 'u' || conv->format_conv == 'U')
		print_u(conv, arg, nb);
	else if (conv->format_conv == 'x' || conv->format_conv == 'X')
		print_x(conv, arg, nb);
	else if (conv->format_conv == '%')
		print_pc(conv, nb);
}
