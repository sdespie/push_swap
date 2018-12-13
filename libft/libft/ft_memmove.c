/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 19:13:04 by sde-spie          #+#    #+#             */
/*   Updated: 2018/06/21 19:13:05 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dest, const void *src, size_t len)
{
	char			*destcp;
	char			*srccp;
	size_t			i;

	i = -1;
	destcp = (char *)dest;
	srccp = (char *)src;
	if (srccp <= destcp)
		while (len--)
			((unsigned char*)destcp)[len] = ((unsigned char*)srccp)[len];
	else
		ft_memcpy(destcp, srccp, len);
	return (dest);
}
