/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_modif_o_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 14:31:35 by droly             #+#    #+#             */
/*   Updated: 2016/02/19 18:31:49 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*db2(unsigned long long i, char *str)
{
	i = plus(i);
	str = ft_utoa(i);
	return (str);
}

char				*len_modif_h_j2(t_printf *lst, char *str, va_list argptr,
		unsigned long long i)
{
	if (lst->len_modif[0] == 'h' && lst->len_modif[1] == 'h')
	{
		i = va_arg(argptr, unsigned int);
		str = db2(i, str);
	}
	else if (ft_strchr("h", lst->len_modif[0]) != NULL)
	{
		i = (unsigned short)va_arg(argptr, unsigned int);
		str = db2(i, str);
	}
	else if (ft_strchr("j", lst->len_modif[0]) != NULL)
	{
		i = va_arg(argptr, uintmax_t);
		str = db2(i, str);
	}
	return (str);
}

char				*len_modif_l_z2(t_printf *lst, char *str, va_list argptr,
		unsigned long long i)
{
	if (lst->len_modif[0] == 'l' && lst->len_modif[1] == 'l')
	{
		i = va_arg(argptr, unsigned long long);
		str = db2(i, str);
	}
	else if (ft_strchr("l", lst->len_modif[0]) != NULL)
	{
		i = va_arg(argptr, unsigned long);
		str = db2(i, str);
	}
	else if (ft_strchr("z", lst->len_modif[0]) != NULL)
	{
		i = va_arg(argptr, size_t);
		str = db2(i, str);
	}
	return (str);
}
