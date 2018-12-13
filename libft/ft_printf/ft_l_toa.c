/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_l_toa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 00:17:18 by sde-spie          #+#    #+#             */
/*   Updated: 2018/09/13 00:17:34 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digits(long n, int count)
{
	if (n > 9)
		return (count_digits(n / 10, count + 1));
	return (count + 1);
}

static char	*allocate_memory(long n)
{
	char	*str;
	int		i;

	if (n < 0)
	{
		n = -n;
		str = ft_strnew(count_digits(n, 0) + 1);
		if (str == NULL)
			return (NULL);
	}
	else
	{
		str = ft_strnew(count_digits(n, 0));
		if (str == NULL)
			return (NULL);
	}
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

char		*ft_l_toa(intmax_t n)
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
	n = (n < 0) ? -n : n;
	while (n)
	{
		*iterate = (n % 10) + '0';
		n /= 10;
		iterate--;
	}
	return (str_new);
}
