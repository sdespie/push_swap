/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_wchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 20:59:43 by sde-spie          #+#    #+#             */
/*   Updated: 2018/09/23 20:13:39 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_getlenwstr(wchar_t str)
{
	size_t	l;

	l = 0;
	if (str <= 0x7F)
		l++;
	else if (str <= 0x7FF)
		l += 2;
	else if (str <= 0xFFFF)
		l += 3;
	else if (str <= 0x10FFFF)
		l += 4;
	return (l);
}

void	ft_wstrwlen(t_conv *conv, size_t l, wchar_t str, int *nb)
{
	char	*sb;

	sb = ft_strnew(conv->width - l);
	sb = ft_memset(sb, !conv->minus && conv->zero ? '0' : ' ', conv->width - l);
	if (conv->minus)
	{
		ft_putwchar(str);
		write(1, sb, conv->width - l);
	}
	else
	{
		write(1, sb, conv->width - l);
		ft_putwchar(str);
	}
	*nb += conv->width;
	ft_strdel(&sb);
}

void	print_wchar(t_conv *conv, va_list arg, int *nb)
{
	size_t	l;
	wchar_t	wch;

	wch = va_arg(arg, wchar_t);
	l = ft_getlenwstr(wch);
	if ((conv->dot && conv->precis < l) && wch != 0)
		return ;
	if (conv->width > l)
		ft_wstrwlen(conv, l, wch, nb);
	else
	{
		ft_putwchar(wch);
		*nb += l;
	}
}
