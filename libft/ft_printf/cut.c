/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 21:17:21 by sde-spie          #+#    #+#             */
/*   Updated: 2018/09/27 13:27:47 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*l_cut(char *str, int n_cut)
{
	char	*str_new;
	int		i;
	int		len;
	int		j;

	len = ft_strlen(str);
	if (n_cut >= len)
		return (ft_strdup(""));
	str_new = ft_strnew(len - n_cut);
	while (n_cut--)
		str++;
	i = 0;
	j = 0;
	while (*str)
		str_new[i++] = str[j++];
	ft_strdel(&str);
	return (str_new);
}

char		*r_cut(char *str, int n_cut)
{
	char	*str_new;
	int		i;
	int		len;
	int		j;

	len = ft_strlen(str);
	if (n_cut >= len)
	{
		ft_strdel(&str);
		return (ft_strdup(""));
	}
	str_new = ft_strnew(len - n_cut);
	i = 0;
	j = 0;
	while (i < (len - n_cut))
		str_new[i++] = str[j++];
	ft_strdel(&str);
	return (str_new);
}
