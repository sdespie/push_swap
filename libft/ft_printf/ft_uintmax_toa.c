/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 18:50:03 by sde-spie          #+#    #+#             */
/*   Updated: 2018/09/13 00:18:55 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digits(uintmax_t n, int count)
{
	if (n > 9)
		return (count_digits(n / 10, count + 1));
	return (count + 1);
}

static char	*allocate_memory(uintmax_t n)
{
	char	*str;
	int		i;

	str = ft_strnew(count_digits(n, 0));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < count_digits(n, 0))
		str[i++] = 'X';
	return (str);
}

static char	*string_zero(void)
{
	char	*str;

	str = ft_strnew(1);
	if (str == NULL)
		return (NULL);
	str[0] = '0';
	return (str);
}

char		*ft_uintmax_toa(uintmax_t n)
{
	char	*str_new;
	char	*iterate;

	if (n == 0)
		return (string_zero());
	if (n < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	if (!(str_new = allocate_memory(n)))
		return (NULL);
	iterate = str_new;
	while (*iterate)
		iterate++;
	iterate--;
	while (n)
	{
		*iterate = (n % 10) + '0';
		n /= 10;
		iterate--;
	}
	return (str_new);
}
