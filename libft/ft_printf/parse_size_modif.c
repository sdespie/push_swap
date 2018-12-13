/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_size_modif.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 20:58:12 by sde-spie          #+#    #+#             */
/*   Updated: 2018/09/13 00:23:14 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		parse_size_modif(t_conv *conv, char **format, char **size_modif)
{
	char	*tmp;
	int		i;

	tmp = ft_strdup(*format);
	i = 0;
	while (!is_conv(tmp[i]) && is_len_modif(&tmp[i]))
	{
		if (tmp[i] == 'h' && tmp[i + 1] == 'h')
			conv->size_modif[0] = 1;
		else if (tmp[i] == 'h' && conv->size_modif[0] == 0)
			conv->size_modif[1] = 1;
		else if (tmp[i] == 'l' && tmp[i + 1] == 'l')
			conv->size_modif[2] = 1;
		else if (tmp[i] == 'l' && conv->size_modif[2] == 0)
			conv->size_modif[3] = 1;
		else if (tmp[i] == 'j')
			conv->size_modif[4] = 1;
		else if (tmp[i] == 'z')
			conv->size_modif[5] = 1;
		i++;
	}
	free(tmp);
	*format = &(*format)[i];
}
