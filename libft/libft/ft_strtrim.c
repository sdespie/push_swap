/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 19:17:16 by sde-spie          #+#    #+#             */
/*   Updated: 2018/06/23 19:58:02 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char	*newstr;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen(s) - 1;
	while (ft_isspace(s[i]))
		i++;
	if (i == j + 1)
		return (newstr = ft_strnew(0));
	while (ft_isspace(s[j]))
		j--;
	len = j - i + 1;
	newstr = ft_strnew(len);
	if (!newstr)
		return (NULL);
	len = 0;
	while (i <= j)
		newstr[len++] = s[i++];
	return (newstr);
}
