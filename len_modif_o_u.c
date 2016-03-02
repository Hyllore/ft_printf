/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_modif_o_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 14:31:35 by droly             #+#    #+#             */
/*   Updated: 2016/03/02 18:12:23 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	write_S(t_printf *lst, va_list argptr, t_flags *lst2)
{
	wchar_t c;

	if ((lst->field == -1 && lst2->minus == 0 && lst->type == 'C') ||
			(lst->type == 'c' && lst->len_modif[0] == 'l'))
	{
		c = va_arg(argptr, wchar_t);
		ft_putwchar(c);
		lst->i2 += 3;
		if (c == 0)
			lst->i2 -= 2;
	}
	if (ft_strchr("S", lst->type) != NULL)
	{
		if (lst2->minus == 1 && lst->field != -1)
			*lst = minus_1(lst, argptr);
		if (lst2->minus != 1 && lst->field != -1)
			*lst = minus_0(lst, argptr);
		if (lst->field == -1 && lst2->minus == 0 &&
				ft_strchr("S", lst->type) != NULL)
			lst->i2 += ft_putwstr(va_arg(argptr, wchar_t*));
	}
	return (*lst);
}

t_printf	countdmrd2(t_printf *lst, char *str, va_list argptr)
{
	wchar_t	c;

	lst->tmp = 0;
	c = va_arg(argptr, wchar_t);
	*lst = countQ(lst , c);
	while (lst->tmp > 0 || *str)
	{
		ft_putchar(*str++);
		lst->tmp--;
		lst->i2++;
	}
	ft_putwchar(c);
	return (*lst);
}

char		*db2(unsigned long long i, char *str)
{
//	i = plus(i);
	str = ft_utoa(i);
	return (str);
}

char				*len_modif_h_j2(t_printf *lst, char *str, va_list argptr,
		unsigned long long i)
{
	if (lst->len_modif[0] == 'h' && lst->len_modif[1] == 'h')
	{
		i = (unsigned char)va_arg(argptr, unsigned int);
		str = db2(i, str);
	}
	else if (ft_strchr("h", lst->len_modif[0]) != NULL)
	{
		i = (unsigned short)va_arg(argptr, unsigned int);
		str = db2(i, str);
	}
	else if (ft_strchr("j", lst->len_modif[0]) != NULL)
	{
		i = (uintmax_t)va_arg(argptr, uintmax_t);
		if (lst->type == 'o' || lst->type == 'O')
			str = ft_itoa_base_ull(i, 8);
		else
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
		if (lst->type == 'o')
			str = ft_itoa_base_ull(i, 8);
		else
			str = db2(i, str);
	}
	else if (ft_strchr("l", lst->len_modif[0]) != NULL && lst->type == 'o')
		str = ft_itoa_base_ull((unsigned long)va_arg(argptr, unsigned long), 8);
	else if (ft_strchr("l", lst->len_modif[0]) != NULL)
	{
		i = (unsigned long)va_arg(argptr, unsigned long);
		str = db2(i, str);
	}
	else if (ft_strchr("z", lst->len_modif[0]) != NULL)
	{
		i = (size_t)va_arg(argptr, size_t);
		str = db2(i, str);
	}
	if (lst->type == 'o' && str[0] == '0' && str[1] == '\0'
			&& lst->len_modif[0] == 'l' && (lst->precision == 0 ||
				lst->precision == -2))
		str[0] = '\0';
	return (str);
}
