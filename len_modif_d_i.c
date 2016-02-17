/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_modif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 14:03:51 by droly             #+#    #+#             */
/*   Updated: 2016/02/17 14:33:12 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long	plus(long long i)
{
	if (i < 0)
		i = i * -1;
	return (i);
}

static char	*db(long long i, char *str)
{
	int i2;

	i2 = 0;
	if (i < 0)
		i2 = 1;
	i = plus(i);
	str = ft_utoa(i);
	if (i2 == 1)
		str = ft_strjoin("-", str);
	return (str);
}

char	*len_modif_h_j(t_printf *lst, char *str, va_list argptr, long long i)
{
	if (lst->len_modif[0] == 'h' && lst->len_modif[1] == 'h')
	{
		ft_putchar('a');
		i = (short)va_arg(argptr, int);
		str = db(i, str);
	}
	else if (ft_strchr("h", lst->len_modif[0]) != NULL)
	{
		ft_putchar('b');
		i = va_arg(argptr, int);
		str = db(i, str);
	}
	else if (ft_strchr("j", lst->len_modif[0]) != NULL)
	{
		ft_putchar('e');
		i = va_arg(argptr, intmax_t);
		str = db(i, str);
	}
	return (str);
}

char	*len_modif_l_z(t_printf *lst, char *str, va_list argptr, long long i)
{
	if (lst->len_modif[0] == 'l' && lst->len_modif[1] == 'l')
	{
		ft_putchar('c');
		i = va_arg(argptr, long long);
		str = db(i, str);
	}
	else if (ft_strchr("l", lst->len_modif[0]) != NULL)
	{
		ft_putchar('d');
		i = va_arg(argptr, long);
		str = db(i, str);
	}
	else if (ft_strchr("z", lst->len_modif[0]) != NULL)
	{
		i = va_arg(argptr, size_t);
		str = db(i, str);
	}
	return (str);
}

char		*len_modif_d_i(t_printf *lst, char *str, va_list argptr)
{
	long long i;

	i = 0;
	if (ft_strchr("hj", lst->len_modif[0]))
			str = len_modif_h_j(lst, str, argptr, i);
	if (ft_strchr("lz", lst->len_modif[0]))
			str = len_modif_l_z(lst, str, argptr, i);
	return (str);
}
