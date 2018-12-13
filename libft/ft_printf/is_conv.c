/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 22:40:43 by sde-spie          #+#    #+#             */
/*   Updated: 2018/09/13 00:19:39 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool		is_conv(char c)
{
	char	*conv_list;

	conv_list = "sSpdDioOuUxXcC%";
	while (*conv_list)
	{
		if (c == *conv_list)
			return (1);
		conv_list++;
	}
	return (0);
}
