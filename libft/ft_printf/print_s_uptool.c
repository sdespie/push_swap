/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s_uptool.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 21:15:03 by sde-spie          #+#    #+#             */
/*   Updated: 2018/09/23 15:26:26 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_getlenwstr2(wchar_t *str)
{
	size_t	l;

	l = 0;
	while (*str)
	{
		if (*str <= 0x7F)
			l++;
		else if (*str <= 0x7FF)
			l += 2;
		else if (*str <= 0xFFFF)
			l += 3;
		else if (*str <= 0x10FFFF)
			l += 4;
		str++;
	}
	return (l);
}

int			ft_maxcharpossible(wchar_t *str, size_t len)
{
	size_t	i;
	int		j;
	int		k;

	k = 0;
	i = 0;
	while (*str && i <= len)
	{
		j = 0;
		if (*str <= 0x7F)
			i++;
		else if (*str <= 0x7FF)
			i += 2;
		else if (*str <= 0xFFFF)
			i += 3;
		else if (*str <= 0x10FFFF)
			i += 4;
		j = i - k;
		k = i;
	}
	return (k - j);
}

void		ft_putnwstr2(const wchar_t *str, size_t len, int *nb)
{
	size_t	i;
	int		j;
	int		k;

	k = 0;
	i = 0;
	while (*str && i < len)
	{
		j = 0;
		if (*str <= 0x7F)
			i++;
		else if (*str <= 0x7FF)
			i += 2;
		else if (*str <= 0xFFFF)
			i += 3;
		else if (*str <= 0x10FFFF)
			i += 4;
		j = (int)i - k;
		k = i;
		if (i <= len)
		{
			ft_putwchar(*str++);
			*nb += j;
		}
	}
}

void		ft_wstrwlen2(t_conv *conv, size_t l, wchar_t *str, int *nb)
{
	char	*sb;

	sb = ft_strnew(conv->width > 0 ? conv->width - l : 0);
	sb = ft_memset(sb, !conv->minus && conv->zero ? '0' : ' ', conv->width - l);
	if (conv->minus)
	{
		ft_putnwstr2(str, l, nb);
		write(1, sb, ft_strlen(sb));
	}
	else
	{
		write(1, sb, ft_strlen(sb));
		ft_putnwstr2(str, l, nb);
	}
	ft_strdel(&sb);
}
