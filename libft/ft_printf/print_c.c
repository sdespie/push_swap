/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 12:45:03 by sde-spie          #+#    #+#             */
/*   Updated: 2018/09/27 12:20:40 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_null(t_conv *conv, int *nb)
{
	char		c;

	c = 0;
	if (!conv->minus)
	{
		while (--(conv->width) > 0 && ++(*nb))
			ft_putchar(conv->zero ? '0' : ' ');
		ft_putchar(c);
		(*nb)++;
	}
	else if (conv->minus)
	{
		ft_putchar(c);
		(*nb)++;
		while (--(conv->width) > 0 && ++(*nb))
			ft_putchar(' ');
	}
}

static void		handle_width(char **str_new, uintmax_t c, char pad, t_conv *cv)
{
	*str_new = ft_strjoin_free(*str_new, to_str(c), 2);
	*str_new = l_pad(*str_new, cv->width, pad);
}

static void		handle_minus(char **str_new, uintmax_t c, char pad, t_conv *cv)
{
	*str_new = ft_strjoin_free(*str_new, to_str(c), 2);
	*str_new = r_pad(*str_new, cv->width, pad);
}

void			print_c(t_conv *conv, va_list arg, int *nb)
{
	uintmax_t	c;
	char		char_pad;
	char		*str_new;

	conv->zero = (conv->zero && conv->minus) ? 0 : conv->zero;
	char_pad = conv->zero ? '0' : ' ';
	str_new = ft_strdup("");
	if (conv->format_conv == 'C' || conv->size_modif[2] || conv->size_modif[3])
		c = va_arg(arg, wchar_t);
	else
		c = (char)va_arg(arg, void *);
	if (!c)
	{
		print_null(conv, nb);
		return ;
	}
	if (conv->minus && conv->width)
		handle_minus(&str_new, c, char_pad, conv);
	else if (conv->width)
		handle_width(&str_new, c, char_pad, conv);
	else
		str_new = to_str_free(c, str_new);
	*nb += ft_strlen(str_new);
	write(1, str_new, ft_strlen(str_new));
	ft_strdel(&str_new);
}
