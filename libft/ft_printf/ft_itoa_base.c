/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 20:26:51 by sde-spie          #+#    #+#             */
/*   Updated: 2018/09/23 16:23:45 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		len_nbr_base(uint64_t value, int base)
{
	int			len;

	len = 0;
	while (value)
	{
		len += 1;
		value /= base;
	}
	return (len);
}

char			*ft_itoa_base(uint64_t n, int base)
{
	int			len;
	uint64_t	value;
	char		*ptr;
	char		*b;

	len = len_nbr_base(n, base);
	value = n;
	if (value == 0)
		return (ft_strdup("0"));
	if (!(ptr = ft_strnew(len)))
		return (NULL);
	if (!(b = ft_strdup("0123456789ABCDEF")))
	{
		ft_strdel(&ptr);
		return (NULL);
	}
	while (value)
	{
		ptr[--len] = b[value % base];
		value /= base;
	}
	ft_strdel(&b);
	return (ptr);
}
