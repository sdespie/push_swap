/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 15:54:34 by sde-spie          #+#    #+#             */
/*   Updated: 2018/09/23 17:46:27 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_strdup_free(char *src, char *to_free)
{
	int		i;
	int		len;
	char	*str;

	len = 0;
	while (src[len])
		len++;
	str = (char*)malloc(sizeof(*str) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	ft_strdel(&to_free);
	return (str);
}

static char	*add_precis_pad(t_conv *conv, char *str, uint64_t val, bool is_zero)
{
	int		len;

	len = ft_strlen(str);
	if (val == 0 && !conv->precis && conv->dot)
		str = ft_strdup_free("", str);
	if (conv->space && conv->plus)
		conv->space = 0;
	if (conv->precis > len)
		str = l_pad(str, conv->precis, '0');
	if (conv->width && conv->minus && !conv->zero)
		str = r_pad(str, conv->width - ((!is_zero && conv->sign) ? 2 : 0), ' ');
	if (conv->width && !conv->minus && conv->zero && conv->sign && conv->dot)
		str = l_pad(str, conv->precis, '0');
	else if (conv->width && !conv->minus && conv->zero)
		str = l_pad(str, conv->width - ((!is_zero && conv->sign) ? 2 : 0),
				!conv->dot ? '0' : ' ');
	if ((conv->sign && !is_zero) && !(conv->precis == 0 && conv->dot))
		str = ft_strjoin_free("0X", str, 1);
	if (conv->width && !conv->minus)
		str = l_pad(str, conv->width, ' ');
	if (conv->width && conv->minus)
		str = r_pad(str, conv->width, ' ');
	return (str);
}

void		print_x(t_conv *conv, va_list arg, int *nb)
{
	char		*str;
	uint64_t	val;
	bool		is_zero_value;

	val = get_unsigned(conv, arg);
	if (!val && conv->precis)
		str = ft_strdup("");
	else
		str = ft_itoa_base(val, 16);
	if (conv->format_conv == 'x')
		ft_strtolower(str);
	is_zero_value = str[0] == '0' || str[0] == '\0';
	str = add_precis_pad(conv, str, val, is_zero_value);
	if (conv->format_conv == 'x')
		ft_strtolower(str);
	ft_putstr(str);
	*nb += ft_strlen(str);
	ft_strdel(&str);
}
