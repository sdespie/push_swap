/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 19:16:37 by sde-spie          #+#    #+#             */
/*   Updated: 2018/09/21 15:37:52 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strjoin_free(char *s1, char *s2, int nb)
{
	char			*newstr;
	unsigned int	i;
	unsigned int	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	newstr = ft_strnew(len);
	if (!newstr)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		newstr[i] = s1[i];
		i++;
	}
	while (i < len)
	{
		newstr[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	(nb != 1) ? ft_strdel(&s1) : 0;
	(nb >= 1) ? ft_strdel(&s2) : 0;
	return (newstr);
}
