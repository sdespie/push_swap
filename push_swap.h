/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 16:28:16 by sde-spie          #+#    #+#             */
/*   Updated: 2018/12/17 10:14:42 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define BUFF_SIZE 32
# include <string.h>
# include "./libft/ft_printf/ft_printf.h"
# include "./libft/libft/libft.h"
# include <stdio.h>
# include <limits.h>
# include <time.h>

typedef struct	s_pile
{
	int		*pile;
	int		size;
}				t_pile;

typedef struct	s_data
{
	int		mediane;
	int		size_max;
	int		pos;
	int		pivot;
	int		pivot2;
	int		sorted;
	int		max_val;
	int		nbr;
	int		nbr2;
	int		error_p;
	int		error_c;
	int		error_sign;
	int		option;
	int		color;
	int		start_index;
	int		m;
	int		speed;
	int		p_max;
	int		mode;
	int		eval1;
	int		eval2;
	char	**argv;
}				t_data;

int				init_struct(t_pile *a, t_pile *b, t_pile *c, t_data *data);
void			fill_pile(t_pile *a, t_pile *c, t_data *data);
void			easy_order(t_pile *c, t_data *data);
void			ft_swap(int *a, int *b);
int				ft_atoi(const char *c);
void			solve(t_pile *a, t_pile *b, t_pile *c, t_data *data);
void			push(t_pile *a, t_pile *b);
void			sort_ft(t_pile *a, t_pile *b, t_data *data, char *mode);
void			get_data(t_pile *a, t_pile *c, t_data *data);
void			solve_short(t_pile *a, t_pile *b, t_pile *c, t_data *data);
int				is_sorted(t_pile a, t_pile c);
void			sort_short(t_pile *a, t_pile *b, t_pile *c, t_data *data);
void			quick_sort_b(t_pile *a, t_pile *b, t_pile *c, t_data *data);
int				get_next_line(const int fd, char **line);
int				diff(int x, int y);
int				ft_atoi2(char *str, t_data *data);
long			ft_atol2(char *str, t_data *data);
int				ft_free(t_pile *a, t_pile *b, t_pile *c, t_data *data);
int				ft_free_end(t_pile *a, t_pile *b, t_pile *c, t_data *data);
int				mini_sort(t_pile *a, t_pile *b, t_pile *c, t_data *data);
void			print_piles(t_pile *a, t_pile *b);
void			p_color(t_pile *a, t_pile *b, t_data *data);
int				need_more_a(t_pile *a, t_pile *c, t_data *data, int nbr_ra);
int				need_more_b(t_pile *a, t_pile *c, t_data *data, int pivot);
void			s_rra(t_pile *a, t_pile *b, t_pile *c, t_data *data);
void			s_rra2(t_pile *a, t_pile *b, t_pile *c, t_data *data);
void			smart_ra1(t_pile *a, t_pile *b, t_data *data, int md);
void			smart_ra2(t_pile *a, t_pile *b, t_data *data, int md);
void			solve2(t_pile *a, t_pile *b, t_pile *c, t_data *data);
int				while_mode(t_pile *a, t_pile *b, t_pile *c, t_data *data);
void			print_mode(t_pile *a, t_pile *b, t_data *data, char *mode);
void			pbsara(t_pile *a, t_pile *b, t_data *data);
#endif
