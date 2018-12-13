/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 12:22:08 by sde-spie          #+#    #+#             */
/*   Updated: 2018/09/21 15:39:44 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dest, const void *src, int c,
		size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	*ptr2;
	unsigned char	stp;

	stp = (unsigned char)c;
	ptr = (unsigned char *)dest;
	ptr2 = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		ptr[i] = ptr2[i];
		if (ptr[i] == stp)
			return (ptr + i + 1);
		i++;
	}
	return (NULL);
}
