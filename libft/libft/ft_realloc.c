/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 13:35:22 by sde-spie          #+#    #+#             */
/*   Updated: 2018/06/22 13:45:53 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	char	*out;

	if ((out = malloc(size)) == NULL)
		return (NULL);
	ft_bzero(out, size);
	if (ptr != NULL)
	{
		ft_strncpy(out, ptr, ft_strlen(ptr));
		free(ptr);
	}
	return (out);
}
