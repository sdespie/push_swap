/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 19:14:19 by sde-spie          #+#    #+#             */
/*   Updated: 2018/06/22 12:02:32 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strnstr(const char *big, const char *small, size_t len)
{
	unsigned long	i;
	unsigned long	count;

	count = 0;
	if (!*small)
		return ((char*)(big));
	while (count < len && *big)
	{
		i = 0;
		while (count + i < len && small[i] == big[i] && small[i])
			i++;
		if (!small[i])
			return (char*)(big);
		count++;
		big++;
	}
	return (NULL);
}
