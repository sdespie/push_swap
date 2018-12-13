/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 18:14:21 by sde-spie          #+#    #+#             */
/*   Updated: 2018/09/23 15:25:39 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_pc(t_conv *conv, int *nb)
{
	char	*str_new;

	str_new = ft_strdup("%");
	if (conv->minus)
		str_new = r_pad(str_new, conv->width, ' ');
	else if (!conv->zero)
		str_new = l_pad(str_new, conv->width, ' ');
	else if (conv->zero)
		str_new = l_pad(str_new, conv->width, '0');
	*nb += ft_strlen(str_new);
	ft_putstr(str_new);
	ft_strdel(&str_new);
}
