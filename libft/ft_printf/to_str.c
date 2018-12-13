/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 21:31:21 by sde-spie          #+#    #+#             */
/*   Updated: 2018/09/23 20:16:04 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*to_str(char c)
{
	char	*str_new;

	str_new = ft_strnew(1);
	str_new[0] = c;
	return (str_new);
}

char	*to_str_free(char c, char *src)
{
	char	*str_new;

	ft_strdel(&src);
	str_new = ft_strnew(1);
	str_new[0] = c;
	return (str_new);
}
