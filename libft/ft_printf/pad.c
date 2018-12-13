/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 20:53:00 by sde-spie          #+#    #+#             */
/*   Updated: 2018/09/22 19:56:04 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*l_pad(char *str, int width, char c)
{
	char	*str_new;
	int		i;
	int		len;
	int		j;

	len = ft_strlen(str);
	if (len >= width)
		return (str);
	str_new = ft_strnew(width);
	i = 0;
	j = 0;
	while (i < (width - len))
		str_new[i++] = c;
	while (i < width)
		str_new[i++] = str[j++];
	ft_strdel(&str);
	return (str_new);
}

char		*r_pad(char *str, int width, char c)
{
	char	*str_new;
	int		i;
	int		len;
	int		j;

	len = ft_strlen(str);
	if (len >= width)
		return (str);
	str_new = ft_strnew(width);
	i = 0;
	j = 0;
	while (i < len)
		str_new[i++] = str[j++];
	while (i < width)
		str_new[i++] = c;
	ft_strdel(&str);
	return (str_new);
}
