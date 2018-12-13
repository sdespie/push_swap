/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 18:19:56 by sde-spie          #+#    #+#             */
/*   Updated: 2018/09/23 16:03:52 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_char_o(intmax_t val, char *s, t_conv *conv, int *nb)
{
	if (conv->space && conv->plus)
		conv->space = 0;
	if (!val && conv->dot)
	{
		ft_strdel(&s);
		s = ft_strdup("");
	}
	if (conv->sign && (val || conv->dot))
		s = l_pad(s, ft_strlen(s) + 1, '0');
	if (conv->precis && conv->zero)
		s = l_pad(s, conv->precis + (conv->plus ? 1 : 0), '0');
	if (conv->width && conv->dot && !conv->precis && conv->minus)
		s = r_pad(s, conv->width - (conv->sign ? 1 : 0), ' ');
	else if (conv->precis)
		s = l_pad(s, conv->precis, '0');
	if (conv->width && !conv->minus)
		s = l_pad(s, conv->width, (conv->zero && !conv->dot) ? '0' : ' ');
	else if (conv->width && conv->minus)
		s = r_pad(s, conv->width, ' ');
	write(1, s, ft_strlen(s));
	*nb += ft_strlen(s);
	ft_strdel(&s);
}

void		print_o(t_conv *conv, va_list arg, int *nb)
{
	int			len;
	char		*str;
	intmax_t	input;

	if (conv->format_conv == 'O')
	{
		conv->size_modif[3] = 1;
		conv->format_conv = 'o';
	}
	input = get_unsigned(conv, arg);
	str = ft_itoa_base(input, 8);
	if (input == 0)
	{
		str[0] = '0';
		str[1] = '\0';
	}
	print_char_o(input, str, conv, nb);
}
