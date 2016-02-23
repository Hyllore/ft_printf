/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 14:36:14 by droly             #+#    #+#             */
/*   Updated: 2016/02/23 16:36:51 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf		seek_len_modif_types(t_printf *lst, const char *format, int i)
{
	int			i2;

	i2 = 0;
	lst->len_modif = malloc(sizeof(char) * 2);
	while ((ft_strchr("hljz", format[i])) != NULL)
	{
		lst->len_modif[i2] = format[i];
		i++;
		i2++;
	}
	lst->len_modif[i2] = '\0';
	if ((ft_strchr("sSpdDioOuUxXcC", format[i])) != NULL)
	{
		lst->type = format[i];
		i++;
	}
	return (*lst);
}

t_printf		seek_field_precision(t_printf *lst, const char *format, int i,
		va_list argptr)
{
	lst->field = -1;
	lst->precision = -1;
	if (format[i] >= '0' && format[i] <= '9')
		lst->field = ft_atoi((char*)&format[i]);
	if (format[i] == '*')
	{
		lst->field = va_arg(argptr, int);
		i++;
	}
	while (format[i] >= '0' && format[i] <= '9')
		i++;
	if (format[i] == '.' && format[i + 1] >= '0' && format[i + 1] <= '9')
	{
		i++;
		lst->precision = ft_atoi((char*)&format[i]);
	}
	while (format[i] >= '0' && format[i] <= '9')
		i++;
	if (format[i] == '.' && format[i + 1] == '*')
	{
		lst->precision = va_arg(argptr, int);
		i++;
	}
	return (*lst);
}

t_flags			seek_flags(t_flags *lst2, char *t)
{
	if (t[0] == '#')
		lst2->diese = 1;
	if (t[0] == '-')
		lst2->minus = 1;
	if (t[0] == '+')
		lst2->plus = 1;
	if (t[0] == ' ')
		lst2->space = 1;
	if (t[0] == '0')
		lst2->zero = 1;
	return (*lst2);
}

t_printf		write_C(t_printf *lst, va_list argptr, t_flags *lst2)
{
	if (lst2->minus == 1 && lst->field != -1)
	{
		lst->field -= 1;
		ft_putwchar(va_arg(argptr, wchar_t));
		lst->i2 += 2;
		while (lst->field > 1)
		{
			ft_putchar(' ');
			lst->field--;
			lst->i2++;
		}
	}
	if (lst->field != -1 && lst2->minus != 1)
	{
		lst->field--;
		while (lst->field > 1)
		{
			ft_putchar(' ');
			lst->field--;
			lst->i2++;
		}
		ft_putwchar(va_arg(argptr, wchar_t));
		lst->i2 += 2;
	}
	return (*lst);
}

t_printf		seek_types(t_printf *lst, const char *format, va_list argptr)
{
	t_flags		*lst2;
	char		*t;

	lst2 = (t_flags*)malloc(sizeof(t_flags));
	t = (char*)malloc(sizeof(char) * 2);
	while ((t = ft_strchr("#-+ 0", format[lst->i])) != NULL)
	{
		*lst2 = seek_flags(lst2, t);
		lst->i++;
	}
	free(t);
	*lst = seek_field_precision(lst, format, lst->i, argptr);
	while ((format[lst->i] >= '0' && format[lst->i] <= '9')
			|| format[lst->i] == '*' || format[lst->i] == '.')
		lst->i++;
	*lst = seek_len_modif_types(lst, format, lst->i);
	while ((ft_strchr("hljzsSpdDioOuUxXcC", format[lst->i])) != NULL
			&& format[lst->i] != '\0')
		lst->i++;
	if (ft_strchr("spdDioOuUxXc", lst->type) != NULL)
		*lst = apply_flags(lst, lst2, argptr, NULL);
	if (ft_strchr("C", lst->type) != NULL)
		*lst = write_C(lst, argptr, lst2);
	*lst = write_S(lst, argptr, lst2);
	return (*lst);
}
