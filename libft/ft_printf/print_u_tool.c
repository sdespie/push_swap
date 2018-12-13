/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u_tool.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-spie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 14:54:42 by sde-spie          #+#    #+#             */
/*   Updated: 2018/09/23 17:25:46 by sde-spie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ret_free(char *cmp1, char *cmp2, int i)
{
	ft_strdel(&cmp1);
	ft_strdel(&cmp2);
	return (i);
}

int			nb_cmp(char *s1, char *s2)
{
	char	*cmp1;
	char	*cmp2;

	cmp1 = ft_strdup(s1);
	cmp2 = ft_strdup(s2);
	if (cmp1[0] == '-' && (zeroed(cmp2) || ft_strcmp(cmp2, "0") > 0))
		return (ret_free(cmp1, cmp2, -1));
	else if (cmp2[0] == '-' && (zeroed(cmp1) || ft_strcmp(cmp1, "0") > 0))
		return (ret_free(cmp1, cmp2, -1));
	if (cmp1[0] == '-' && cmp2[0] == '-')
	{
		if (ft_strlen(cmp2) > ft_strlen(cmp1))
			return (ret_free(cmp1, cmp2, 1));
		else if (ft_strlen(cmp2) < ft_strlen(cmp1))
			return (ret_free(cmp1, cmp2, -1));
		return (ret_free(cmp1, cmp2, -ft_strcmp(cmp1, cmp2)));
	}
	if (ft_strcmp(cmp1, cmp2) > 0 && ft_strlen(cmp2) > ft_strlen(cmp1))
		return (ret_free(cmp1, cmp2, -1));
	if (ft_strcmp(cmp1, cmp2) < 0 && ft_strlen(cmp2) < ft_strlen(cmp1))
		return (ret_free(cmp1, cmp2, 1));
	return (ret_free(cmp1, cmp2, ft_strcmp(cmp1, cmp2)));
}

bool		zeroed(char *str)
{
	while (*str)
	{
		if (*str != '0')
			return (0);
		str++;
	}
	return (1);
}

void		truncate_zeros(char **str)
{
	int			i;
	char		*tmp;
	int			sign;

	i = 0;
	if (*str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while ((*str)[i] && (*str)[i] == '0')
		i++;
	if (sign == -1)
		*str = ft_strjoin_free("-", *str + i, 1);
	else
	{
		tmp = ft_strdup(*str + i);
		ft_strdel(str);
		*str = tmp;
	}
}
