/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 11:53:32 by droly             #+#    #+#             */
/*   Updated: 2016/03/03 19:09:42 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>
#include <limits.h>

t_printf		apply_flags(t_printf *lst, t_flags *lst2, va_list argptr,
		char *str)
{
	if ((ft_strchr("dDioOuUxX", lst->type)) != NULL && (lst->len_modif[0] != 'h'
				&& lst->len_modif[0] != 'l' && lst->len_modif[0] != 'j' &&
				lst->len_modif[0] != 'z'))
		str = take_type1(lst, lst2, str, argptr);
	if ((ft_strchr("spc", lst->type)) != NULL)
		str = take_type2(lst, str, argptr);
	if (lst->len_modif[0] == 'h' || lst->len_modif[0] == 'l' ||
			lst->len_modif[0] == 'j' || lst->len_modif[0] == 'z')
		str = apply_len_modif(lst, str, argptr, lst2);
	if (lst->field != -1 && lst2->zero == 1 && lst2->minus != 1)
		str = apply_field_zero(lst, lst2, str, ft_strlen(str));
	if (lst->precision >= 0 && (ft_strchr("dDioOuUxX", lst->type)) != NULL)
		str = apply_precision_num(lst, str, ft_strlen(str));
	if (lst2->diese == 1)
		str = apply_diese(lst, str);
	if (lst2->plus == 1)
		str = apply_plus(str);
	if (lst->precision >= 0 && (ft_strchr("sS", lst->type)) != NULL)
		str = apply_precision_str(lst, str);
	if (lst->field != -1 || lst2->zero != 1)
		str = apply_field_space(lst, lst2, str, ft_strlen(str));
	if (lst2->space == 1)
		str = apply_space(str);
	return (write_char(lst, str, 0));
}

t_printf		percent_analysis(const char *format, t_printf *lst)
{
	lst->tmp = lst->i + 1;
	lst->precision = -1;
	lst->field = -1;
	while (ft_strchr("- #*+-.0123456789hljz", format[lst->tmp]) != NULL)
		lst->tmp++;
	if (ft_strchr("%", format[lst->tmp]) != NULL)
	{
		lst->i = lst->i + 1;
		while (format[lst->i] != '%')
		{
			*lst = add_bonus(format, lst);
			lst->i++;
		}
	}
	else
	{
		lst->tmp = 0;
		return (*lst);
	}
	return (apply_percent(lst));
}

t_printf		ft_printf_bis(const char *format, va_list argptr, t_printf *lst)
{
	if (format[lst->i] == '%' && format[lst->i + 1] == '%')
	{
		ft_putchar('%');
		lst->i++;
		lst->i2++;
	}
	else if (format[lst->i] == '%')
	{
		*lst = percent_analysis(format, lst);
		if (lst->tmp == 0)
		{
			lst->i++;
			*lst = seek_types(lst, format, argptr,
					(t_flags*)malloc(sizeof(t_flags)));
			lst->i--;
		}
	}
	else
	{
		ft_putchar(format[lst->i]);
		lst->i2++;
	}
	lst->i++;
	return (*lst);
}

int				ft_printf(const char *format, ...)
{
	va_list		argptr;
	t_printf	*lst;

	lst = (t_printf*)malloc(sizeof(t_printf));
	lst->i = 0;
	lst->i2 = 0;
	va_start(argptr, format);
	while (format[lst->i] != '\0')
	{
		*lst = ft_printf_bis(format, argptr, lst);
	}
	va_end(argptr);
	return (lst->i2);
}

#include <limits.h>

int				main(void)
{
	int ret;
	int ret2;
	wchar_t		ptr;
	wchar_t		*ptr2;
	char c;

	ptr2 = (wchar_t*)malloc(sizeof(char) * 3);
	ptr2[0] = 0;
	ptr2[1] = '\0';
	ptr2[2] = '\0';
	ptr = 40000;
	ret = 0;
	ret2 = 0;
//	ptr = "hey";
	char* l = setlocale(LC_ALL, "");
	if (l == NULL) {
		printf("Locale not set\n");
	} else {
		printf("Locale set to %s\n", l);
	}
	ret2 = printf("% u|%+u", 42, 42);
	ret = ft_printf("%.o, % +i", 0, 0);
	ft_putchar('\n');
	ft_putnbr(ret);
	ft_putchar('\n');
	ft_putnbr(ret2);

//	ft_printf("\n%#8x %p d %10C %+19.19D o %#18.19o x %#12.20x X %-12.20lX d %+12.20hd d %+12.20hd u %12.20u %# +03.5hh% %-05% %   % %%%%%%",42,ptr,945, 42, 1234567, 0, 4294967296, (short)-922337203685477580,(short)42, 1234567);
//	printf("\n%#8x %p d %10C %+19.19D o %#18.19o x %#12.20x X %-12.20lX d %+12.20hd d %+12.20hd u %12.20u %# +03.5hh% %-05% %   % %%%%%%",42,ptr,945, 42, 1234567, 0, 4294967296, (short)-922337203685477580,(short)42, 1234567);

}
