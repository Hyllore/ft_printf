/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 11:53:32 by droly             #+#    #+#             */
/*   Updated: 2016/02/19 15:28:24 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>

t_printf		apply_flags(t_printf *lst, t_flags *lst2, va_list argptr,
		char *str)
{
	if ((ft_strchr("dDioOuUxX", lst->type)) != NULL && (lst->len_modif[0] != 'h'
				&& lst->len_modif[0] != 'l' && lst->len_modif[0] != 'j' &&
				lst->len_modif[0] != 'z'))
		str = take_type1(lst, lst2, str, argptr);
	if ((ft_strchr("sSpc", lst->type)) != NULL)
		str = take_type2(lst, str, argptr);
	if (lst->len_modif[0] == 'h' || lst->len_modif[0] == 'l' ||
			lst->len_modif[0] == 'j' || lst->len_modif[0] == 'z')
		str = apply_len_modif(lst, str, argptr, lst2);
	if (lst->field != -1 && lst2->zero == 1)
		str = apply_field_zero(lst, lst2, str, ft_strlen(str));
	if (lst->precision != -1 && (ft_strchr("dDioOuUxX", lst->type)) != NULL)
		str = apply_precision_num(lst, str, ft_strlen(str));
	if (lst2->diese == 1)
		str = apply_diese(lst, str);
	if (lst2->plus == 1)
		str = apply_plus(str);
	if (lst->precision != -1 && (ft_strchr("sS", lst->type)) != NULL)
		str = apply_precision_str(lst, str);
	if (lst->field != -1 && lst2->zero != 1)
		str = apply_field_space(lst, lst2, str, ft_strlen(str));
	if (lst2->space == 1)
		str = apply_space(str);
	return (write_char(lst, str, 0));
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
		lst->i++;
		*lst = seek_types(lst, format, argptr);
		lst->i--;
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
//	free(lst);
	return (lst->i2);
}
/*
int				main(void)
{
	char		*ptr;

	ptr = "hey"; 
	char* l = setlocale(LC_ALL, "");
	if (l == NULL) {
		printf("Locale not set\n");
	} else {
		printf("Locale set to %s\n", l);
	}
	printf("%C\n", 945);
	printf("\n%C\n" , 40000);
	ft_printf("\nd %10C %+19.19D o %#18.19o x %#12.20x X %-12.20lX d %+12.20hd d %+12.20hd u %12.20u %%%%%%",945, 42, 1234567, -1, 4294967296, (short)-922337203685477580,(short)42, 1234567);
	printf("\nd %10C %+19.19D o %#18.19o x %#12.20x X %-12.20lX d %+12.20hd d %+12.20hd u %12.20u %%%%%%",945, 42, 1234567, -1, 4294967296, (short)-922337203685477580,(short)42, 1234567);

}*/
