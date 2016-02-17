/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_modif_o_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 14:31:35 by droly             #+#    #+#             */
/*   Updated: 2016/02/17 15:52:09 by droly            ###   ########.fr       */
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

char	*len_modif_h_j2(t_printf *lst, char *str, va_list argptr, long long i)
{
	if (lst->len_modif[0] == 'h' && lst->len_modif[1] == 'h')
	{
		i = va_arg(argptr, unsigned int);
		str = db(i, str);
	}
	else if (ft_strchr("h", lst->len_modif[0]) != NULL)
	{
		i = (unsigned short)va_arg(argptr, unsigned int);
		str = db(i, str);
	}
	else if (ft_strchr("j", lst->len_modif[0]) != NULL)
	{
		i = va_arg(argptr, uintmax_t);
		str = db(i, str);
	}
	return (str);
}

char	*len_modif_l_z2(t_printf *lst, char *str, va_list argptr, long long i)
{
	if (lst->len_modif[0] == 'l' && lst->len_modif[1] == 'l')
	{
		i = va_arg(argptr, unsigned long long);
		str = db(i, str);
	}
	else if (ft_strchr("l", lst->len_modif[0]) != NULL)
	{
		i = va_arg(argptr, unsigned long);
		str = db(i, str);
	}
	else if (ft_strchr("z", lst->len_modif[0]) != NULL)
	{
		i = va_arg(argptr, size_t);
		str = db(i, str);
	}
	return (str);
}
