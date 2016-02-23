/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 15:37:20 by droly             #+#    #+#             */
/*   Updated: 2016/02/23 17:22:51 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		count(wchar_t *str)
{
	int i;

	i = 0;
	while (*str)
	{
		ft_unicode(*str++);
		i += 3;
	}
	return (i);
}

t_printf	minus_1(t_printf *lst, va_list argptr)
{
	int		i;
	wchar_t	*str;

	i = 0;
	str = va_arg(argptr, wchar_t*);
	i = count(str);
	ft_putwstr(str);
	lst->field = lst->field - i + 1;
	lst->i2 += i;
	while (lst->field > 1)
	{
		ft_putchar(' ');
		lst->field--;
		lst->i2++;
	}
	return (*lst);
}

t_printf	minus_0(t_printf *lst, va_list argptr)
{
	int i;
	wchar_t *str;

	i = 0;
	str = va_arg(argptr, wchar_t*);
	i = count(str);
	lst->field = lst->field - i + 1;
	while (lst->field > 1)
	{
		ft_putchar(' ');
		lst->field--;
		lst->i2++;
	}
	ft_putwstr(str);
	lst->i2 += i;
	return (*lst);
}
