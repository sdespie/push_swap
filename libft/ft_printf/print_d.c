/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 15:59:54 by sde-spie          #+#    #+#             */
/*   Updated: 2018/09/27 12:33:08 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_strdup_free(char *src, char *to_free)
{
	int		i;
	int		len;
	char	*str;

	len = 0;
	while (src[len])
		len++;
	str = (char*)malloc(sizeof(*str) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	ft_strdel(&to_free);
	return (str);
}

static void	print_chars_finish(char *s, int *nb)
{
	write(1, s, ft_strlen(s));
	*nb += ft_strlen(s);
	ft_strdel(&s);
}

void		print_chars(intmax_t val, char *s, t_conv *conv, int *nb)
{
	if (conv->space && (conv->plus || val < 0))
		conv->space = 0;
	if (!val && conv->dot && !conv->precis)
		s = ft_strdup_free("", s);
	if (conv->precis && conv->zero)
		s = l_pad(s, conv->precis - (conv->plus ? 1 : 0), '0');
	if (conv->width && !conv->dot && conv->zero && !conv->minus)
		s = l_pad(s, conv->width - ((conv->plus || val < 0 || conv->space) ?
					1 : 0), '0');
	else if (conv->precis)
		s = l_pad(s, conv->precis, '0');
	if (val < 0)
		s = l_pad(s, ft_strlen(s) + 1, '-');
	else if (conv->plus)
		s = l_pad(s, ft_strlen(s) + 1, '+');
	if (conv->precis || conv->space)
		s = l_pad(s, ft_max2(conv->precis, ft_strlen(s) + conv->space), ' ');
	if (conv->width && !conv->minus)
		s = l_pad(s, conv->width, ' ');
	else if (conv->width && conv->minus)
		s = r_pad(s, conv->width, ' ');
	print_chars_finish(s, nb);
}

void		print_d(t_conv *conv, va_list arg, int *nb)
{
	intmax_t		val;
	char			*str_new;

	if (conv->format_conv == 'D')
		conv->size_modif[3] = 1;
	if (conv->size_modif[2] == 1)
		val = va_arg(arg, long);
	else if (conv->size_modif[3] == 1)
		val = va_arg(arg, long);
	else if (conv->size_modif[4] == 1)
		val = va_arg(arg, intmax_t);
	else if (conv->size_modif[5] == 1)
		val = va_arg(arg, long);
	else
	{
		val = va_arg(arg, int);
		if (conv->size_modif[0] == 1)
			val = (char)val;
		else if (conv->size_modif[1] == 1)
			val = (short)val;
	}
	str_new = ft_int_toa((intmax_t)val);
	print_chars(val, str_new, conv, nb);
}
