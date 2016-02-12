/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 14:36:14 by droly             #+#    #+#             */
/*   Updated: 2016/02/11 16:29:03 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf		seek_len_modif_types(t_printf *lst, const char *format, int i)
{
	int			i2;

	i2 = 0;
	while ((ft_strchr("hljz", format[i])) != NULL)
	{
		lst->len_modif[i2] = format[i];
		i++;
		i2++;
	}
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

t_flags			seek_flags(t_flags *lst2, const char *format, int i, char *t)
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

int				seek_types(int i, const char *format, va_list argptr)
{
	t_printf	*lst;
	t_flags		*lst2;
	char		*t;

	lst2 = (t_flags*)malloc(sizeof(t_flags));
	lst = (t_printf*)malloc(sizeof(t_printf));
	t = (char*)malloc(sizeof(char) * 2);
	while ((t = ft_strchr("#-+ 0", format[i])) != NULL)
	{
		*lst2 = seek_flags(lst2, format, i, t);
		i++;
	}
	*lst = seek_field_precision(lst, format, i, argptr);
	while ((format[i] >= '0' && format[i] <= '9') || format[i] == '*' || format[i] == '.')
		i++;
	*lst = seek_len_modif_types(lst, format, i);
	while ((ft_strchr("hljzsSpdDioOuUxXcC", format[i])) != NULL
			&& format[i] != '\0')
		i++;
	apply_flags(lst, lst2, argptr);
	return (i);
}
