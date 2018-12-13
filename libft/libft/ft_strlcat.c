/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 15:16:08 by sde-spie          #+#    #+#             */
/*   Updated: 2018/06/23 19:49:50 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, char const *src, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	j;

	j = 0;
	dest_len = ft_strlen(dest);
	i = dest_len;
	if (size < dest_len + 1)
		return (ft_strlen(src) + size);
	if (size > dest_len + 1)
	{
		while (i < size - 1)
			*(dest + i++) = *(src + j++);
		*(dest + i) = '\0';
	}
	return (dest_len + ft_strlen(src));
}
