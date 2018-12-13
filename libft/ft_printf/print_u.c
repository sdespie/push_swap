/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 18:21:04 by sde-spie          #+#    #+#             */
/*   Updated: 2018/09/23 15:26:45 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*print_u_precis(t_conv *conv, char *str)
{
	if (conv->dot)
	{
		if (!conv->precis && nb_cmp(str, "0") == 0)
		{
			ft_strdel(&str);
			str = ft_strdup("");
			return (str);
		}
		if (nb_cmp(str, "0") < 0)
		{
			str++;
			str = l_pad(str, conv->precis, '0');
			str = ft_strjoin_free("-", str, 1);
		}
		else
			str = l_pad(str, conv->precis, '0');
		conv->zero = 0;
	}
	return (str);
}

static	char		*print_u_width(t_conv *conv, char *str)
{
	char		pad_char;

	pad_char = ' ';
	if (conv->width)
	{
		if (conv->zero)
			pad_char = '0';
		if (!conv->minus && nb_cmp(str, ""))
			str = l_pad(str, conv->width, pad_char);
		else
			str = r_pad(str, conv->width, ' ');
		if (ft_strchr(str, '+') && conv->zero)
			str[0] = '+';
		if (ft_strchr(str, '-') && conv->zero)
			str[0] = '-';
		conv->minus = 0;
	}
	return (str);
}

static	void		str_process(t_conv *conv, char **str)
{
	*str = print_u_precis(conv, *str);
	*str = print_u_width(conv, *str);
}

static intmax_t		handle_else(va_list arg, t_conv *conv)
{
	intmax_t	val;

	val = va_arg(arg, unsigned int);
	if (conv->size_modif[0] == 1)
		return ((unsigned char)val);
	else if (conv->size_modif[1] == 1)
		return ((unsigned short)val);
	return (val);
}

void				print_u(t_conv *conv, va_list arg, int *nb)
{
	intmax_t	val;
	char		*str_new;

	if (conv->format_conv == 'U')
		conv->size_modif[3] = 1;
	if (conv->size_modif[2] == 1)
		val = va_arg(arg, unsigned long long);
	else if (conv->size_modif[3] == 1)
		val = va_arg(arg, unsigned long int);
	else if (conv->size_modif[4] == 1)
		val = va_arg(arg, uintmax_t);
	else if (conv->size_modif[5] == 1)
		val = va_arg(arg, size_t);
	else
		val = handle_else(arg, conv);
	if (val < 0)
		str_new = ft_uintmax_toa(val);
	else
		str_new = ft_intmax_toa(val);
	str_process(conv, &str_new);
	(*nb) += ft_strlen(str_new);
	write(1, str_new, ft_strlen(str_new));
	ft_strdel(&str_new);
}
