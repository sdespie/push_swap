/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 19:14:28 by sde-spie          #+#    #+#             */
/*   Updated: 2018/06/23 19:53:35 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strrchr(const char *str, int c)
{
	size_t			i;

	i = ft_strlen(str) + 1;
	while (i--)
		if (*(str + i) == (char)c)
			return ((char *)str + i);
	return (NULL);
}
