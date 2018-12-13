/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 16:28:16 by sde-spie          #+#    #+#             */
/*   Updated: 2018/10/02 21:13:47 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define HEXA_UP "0123456789ABCDEF"
# define HEXA_LO "0123456789abcdef"
# define OCT "01234567"
# include <stdarg.h>
# include <string.h>
# include <stdbool.h>
# include "../libft/libft.h"
# include <locale.h>
# include <stdio.h>
# include <limits.h>

typedef struct	s_conv
{
	bool		sign;
	bool		zero;
	bool		plus;
	bool		minus;
	bool		dot;
	bool		space;
	int			size_modif[6];
	char		format_conv;
	int			width;
	int			precis;
}				t_conv;

int				ft_printf(char *format, ...);
void			manage_pc(char **format, va_list arg, int *nb);
void			init_conv(t_conv *conv);
int				**init_size_modif(void);
void			parse_size_modif(t_conv *conv, char **format,
		char **size_modif);
void			set_flags(t_conv *conv, char f);
bool			flags(t_conv *conv, char f);
bool			is_width(char c);
bool			is_precis(char c);
bool			is_conv(char c);
bool			is_len_modif(char *p_len_modif);
void			print_conv(t_conv *conv, va_list arg, int *nb);
void			print_s(t_conv *conv, va_list arg, int *nb);
void			print_s_upper(t_conv *conv, va_list arg, int *nb);
void			print_d(t_conv *conv, va_list arg, int *nb);
char			*l_pad(char *str, int width, char c);
char			*r_pad(char *str, int width, char c);
char			*l_cut(char *str, int n_cut);
char			*r_cut(char *str, int n_cut);
char			*to_str(char c);
char			*ft_intmax_toa(intmax_t val);
void			print_c(t_conv *conv, va_list arg, int *nb);
void			print_p(t_conv *conv, va_list arg, int *nb);
void			print_x(t_conv *conv, va_list arg, int *nb);
void			print_o(t_conv *conv, va_list arg, int *nb);
void			print_u(t_conv *conv, va_list arg, int *nb);
void			print_pc(t_conv *conv, int *nb);
char			*ft_uintmax_toa(uintmax_t n);
char			*ft_intmax_toa(intmax_t n);
char			*ft_int_toa(intmax_t n);
void			truncate_zeros(char **str);
bool			zeroed(char *str);
char			*ft_itoa_base(uint64_t n, int base);
uintmax_t		get_unsigned(t_conv *conv, va_list arg);
char			*ft_strtolower(char *str);
void			print_chars(intmax_t val, char *str, t_conv *conv, int *nb);
void			ft_putnwstr(const wchar_t *str, size_t len);
void			print_wchar(t_conv *conv, va_list arg, int *nb);
void			ft_putwchar(wchar_t c);
int				nb_cmp(char *s1, char *s2);
size_t			ft_getlenwstr2(wchar_t *str);
int				ft_maxcharpossible(wchar_t *str, size_t len);
void			ft_putnwstr2(const wchar_t *str, size_t len, int *nb);
char			*to_str_free(char c, char *src);

#endif
