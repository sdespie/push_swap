/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 11:56:06 by sde-spie          #+#    #+#             */
/*   Updated: 2018/09/27 13:22:02 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_dot(char *str_new, t_conv *conv, int *nb)
{
	str_new = l_pad(str_new, conv->width, conv->zero ? '0' : ' ');
	*nb += ft_strlen(str_new);
	write(1, str_new, ft_strlen(str_new));
	ft_strdel(&str_new);
}

static void	handle_pad_cut(char *str_new, t_conv *conv, int len, int *nb)
{
	if (conv->zero && conv->minus)
		conv->zero = 0;
	if (conv->precis < len && conv->dot)
		str_new = r_cut(str_new, len - conv->precis);
	if (!conv->minus)
		str_new = l_pad(str_new, conv->width, conv->zero ? '0' : ' ');
	else
		str_new = r_pad(str_new, conv->width, conv->zero ? '0' : ' ');
	*nb += ft_strlen(str_new);
	write(1, str_new, ft_strlen(str_new));
	ft_strdel(&str_new);
}

void		print_s(t_conv *conv, va_list arg, int *nb)
{
	char	*str_arg;
	char	*str_new;
	int		i;
	int		len;
	int		j;

	j = 0;
	i = 0;
	len = 0;
	str_arg = (char *)va_arg(arg, void *);
	if (str_arg)
	{
		str_new = ft_strdup(str_arg);
		while (str_arg[i++])
			len++;
		handle_pad_cut(str_new, conv, len, nb);
	}
	else if (conv->dot)
	{
		str_new = ft_strdup("");
		handle_dot(str_new, conv, nb);
	}
	else
		*nb += ft_printf("(null)");
}

static void	apply_flags_p(wchar_t *val, t_conv *conv, int *nb, size_t len)
{
	char	*s_front;
	char	*s_back;

	s_front = ft_strnew(0);
	s_back = ft_strnew(0);
	if (conv->precis <= len && conv->dot)
		len = ft_maxcharpossible(val, conv->precis);
	if (conv->width && conv->dot && conv->precis && !conv->minus)
		s_front = l_pad(s_front, conv->width - len, conv->zero ? '0' : ' ');
	else if (conv->width && conv->dot && conv->precis && conv->minus)
		s_back = r_pad(s_back, conv->width - len, conv->zero ? '0' : ' ');
	else if (conv->width && !conv->dot && conv->minus)
		s_back = r_pad(s_back, conv->width - len, conv->zero ? '0' : ' ');
	else if (conv->width)
		s_front = l_pad(s_front, conv->width - len, conv->zero ? '0' : ' ');
	write(1, s_front, ft_strlen(s_front));
	ft_putnwstr2(val, len, nb);
	write(1, s_back, ft_strlen(s_back));
	*nb += ft_strlen(s_front) + ft_strlen(s_back);
	ft_strdel(&s_front);
	ft_strdel(&s_back);
}

void		print_s_upper(t_conv *conv, va_list arg, int *nb)
{
	wchar_t	*str_arg;
	char	*str_new;
	int		i;
	int		len;

	str_arg = (wchar_t *)va_arg(arg, void *);
	len = 0;
	i = 0;
	if (str_arg)
	{
		len = ft_getlenwstr2(str_arg);
		apply_flags_p(str_arg, conv, nb, len);
	}
	else
		*nb += ft_printf("(null)");
}
