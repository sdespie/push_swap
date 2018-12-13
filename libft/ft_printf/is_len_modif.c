/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_len_modif.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 23:03:20 by sde-spie          #+#    #+#             */
/*   Updated: 2018/09/13 00:20:23 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static bool	is_in_str(char c, char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

bool		is_len_modif(char *p_len_modif)
{
	while (*p_len_modif)
	{
		if (is_in_str(*p_len_modif, "hlzj"))
			return (1);
		p_len_modif++;
	}
	return (0);
}
