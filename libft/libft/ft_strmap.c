/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 19:16:42 by sde-spie          #+#    #+#             */
/*   Updated: 2018/06/21 19:16:43 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		len;
	char	*newstr;
	int		i;

	if (!s || !f)
		return ((char *)NULL);
	len = ft_strlen(s);
	newstr = ft_strnew(len);
	if (!newstr)
		return (NULL);
	i = -1;
	while (s[++i])
		newstr[i] = f(s[i]);
	return (newstr);
}
