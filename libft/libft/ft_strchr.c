/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 19:13:23 by sde-spie          #+#    #+#             */
/*   Updated: 2018/06/23 19:41:57 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strchr(const char *str, int c)
{
	size_t			i;

	i = ft_strlen(str) + 1;
	while (i != 0)
	{
		if (*str == (char)c)
			return ((char*)(str));
		str++;
		i--;
	}
	return (NULL);
}
