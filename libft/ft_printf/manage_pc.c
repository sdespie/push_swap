/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_pc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 17:01:42 by sde-spie          #+#    #+#             */
/*   Updated: 2018/09/27 13:14:57 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		apply_flags(intmax_t val, char *s, t_conv *conv, int *nb)
{
	if (conv->precis && conv->zero)
		s = l_pad(s, conv->precis + (conv->plus ? 1 : 0), '0');
	if (conv->width && !conv->precis && conv->zero && !conv->minus)
		s = l_pad(s, conv->width - (conv->plus ? 1 : 0), '0');
	if (conv->sign)
		s = l_pad(s, ft_strlen(s) + 1, '0');
	else if (conv->plus)
		s = l_pad(s, ft_strlen(s) + 1, '+');
	if (conv->width && !conv->minus)
		s = l_pad(s, conv->width, ' ');
	else if (conv->width && conv->minus)
		s = r_pad(s, conv->width, ' ');
	write(1, s, ft_strlen(s));
	*nb += ft_strlen(s);
	ft_strdel(&s);
}

static	void	read_flags(char *p_format, t_conv *conv, char **size_modif)
{
	while (flags(conv, *p_format))
	{
		set_flags(conv, *p_format);
		p_format++;
	}
	if (is_width(*p_format))
		conv->width = ft_atoi(p_format);
	while (is_width(*p_format))
		p_format++;
	if (*p_format == '.' && ++p_format)
	{
		(conv->dot) = true;
		if (is_precis(*p_format))
			conv->precis = ft_atoi(p_format);
		while (is_precis(*p_format))
			p_format++;
	}
	parse_size_modif(conv, &p_format, size_modif);
}

static	int		handle_next(char *p_format, char *str, t_conv *conv, int *nb)
{
	if (is_conv(*p_format))
		conv->format_conv = *p_format++;
	else if (*p_format)
	{
		str = ft_strnew(1);
		str[0] = *p_format++;
		apply_flags(1, str, conv, nb);
	}
	else
		return (0);
	return (1);
}

static void		handle_dot(t_conv *conv, char **p_format)
{
	conv->dot = true;
	if (is_precis(**p_format))
		conv->precis = ft_atoi(*p_format);
	while (is_precis(**p_format))
		(*p_format)++;
}

void			manage_pc(char **format, va_list arg, int *nb)
{
	char	**size_modif;
	char	*p_format;
	char	*str;
	t_conv	*conv;

	if (!(conv = malloc(sizeof(t_conv))))
		return ;
	init_conv(conv);
	p_format = ++(*format);
	while (flags(conv, *p_format))
		set_flags(conv, *p_format++);
	if (is_width(*p_format))
		conv->width = ft_atoi(p_format);
	while (is_width(*p_format))
		p_format++;
	if (*p_format == '.' && ++p_format)
		handle_dot(conv, &p_format);
	parse_size_modif(conv, &p_format, size_modif);
	if (!handle_next((p_format)++, str, conv, nb))
		return (free(conv));
	print_conv(conv, arg, nb);
	*format = p_format;
	free(conv);
}
