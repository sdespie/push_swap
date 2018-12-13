/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 19:14:33 by sde-spie          #+#    #+#             */
/*   Updated: 2018/06/21 19:14:34 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *big, const char *small)
{
	size_t	i;
	size_t	slen;

	slen = ft_strlen(small);
	i = 0;
	if (!ft_strlen(small) || big == small)
		return ((char *)big);
	while (*big)
	{
		if (!ft_memcmp(big, small, slen))
			return ((char *)big);
		big++;
		i++;
	}
	return (NULL);
}
