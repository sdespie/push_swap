/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 15:46:59 by sde-spie          #+#    #+#             */
/*   Updated: 2018/09/23 17:13:38 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	apply_flags_p(intmax_t val, char *s, t_conv *conv, int *nb)
{
	if (conv->space && conv->plus)
		conv->space = 0;
	if (!val && conv->dot && !conv->precis)
	{
		ft_strdel(&s);
		s = ft_strdup("");
	}
	if (conv->precis && conv->zero)
		s = l_pad(s, conv->precis + (conv->plus ? 1 : 0), '0');
	if (conv->width && !conv->dot && conv->zero && !conv->minus)
		s = l_pad(s, conv->width - 2, '0');
	else if (conv->precis)
		s = l_pad(s, conv->precis, '0');
	if (conv->sign && val)
		s = l_pad(s, ft_strlen(s) + 1, '0');
	if (val < 0)
		s = l_pad(s, ft_strlen(s) + 1, '-');
	s = ft_strjoin_free("0x", s, 1);
	if (conv->width && !conv->minus)
		s = l_pad(s, conv->width, ' ');
	else if (conv->width && conv->minus)
		s = r_pad(s, conv->width, ' ');
	write(1, s, ft_strlen(s));
	*nb += ft_strlen(s);
	ft_strdel(&s);
}

void		print_p(t_conv *conv, va_list arg, int *nb)
{
	char				*str;
	unsigned long int	val;

	val = va_arg(arg, unsigned long int);
	str = ft_itoa_base(val, 16);
	str = ft_strtolower(str);
	apply_flags_p(val, str, conv, nb);
}
