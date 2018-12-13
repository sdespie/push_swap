/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 13:27:42 by sde-spie          #+#    #+#             */
/*   Updated: 2018/06/23 17:10:40 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_nbrlen(int nbr)
{
	int		i;

	i = 0;
	while (nbr > 0)
	{
		nbr /= 10;
		++i;
	}
	return (i);
}
