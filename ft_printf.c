/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 11:53:32 by droly             #+#    #+#             */
/*   Updated: 2016/02/16 17:30:13 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void		apply_flags(t_printf *lst, t_flags *lst2, va_list argptr)
{
	char	*str;

	str = NULL;
	if ((ft_strchr("dDioOuUxX", lst->type)) != NULL && lst->len_modif == NULL)
	{
		str = take_type1(lst, lst2, str, argptr);
//		ft_putchar('1');
	}
	if ((ft_strchr("oOuUxX", lst->type)) != NULL)
	{
		str = take_type1(lst, lst2, str, argptr);
//		ft_putchar('1');
	}
	if ((ft_strchr("sSpcC", lst->type)) != NULL)
	{
		str = take_type2(lst, str, argptr);
//		ft_putchar('2');
	}
//	ft_putstr(str);
	if (lst->len_modif[0] == 'h' || lst->len_modif[0] == 'l' || lst->len_modif[0] == 'j' || lst->len_modif[0] == 'z')
	{
		str = apply_len_modif(lst, str, argptr);
//		ft_putchar('3');
	}
	if (lst->field != -1 && lst2->zero == 1)
	{
		str = apply_field_zero(lst, lst2, str, ft_strlen(str));
//		ft_putchar('4');
	}
	if (lst->precision != -1 && (ft_strchr("dDioOuUxX", lst->type)) != NULL)
	{
		str = apply_precision_num(lst, str, ft_strlen(str));
//		ft_putchar('5');
	}
	if (lst2->diese == 1)
	{
		str = apply_diese(lst, str);
//		ft_putchar('6');
	}
	if (lst2->plus == 1)
	{
		str = apply_plus(str);
//		ft_putchar('7');
	}
	if (lst->precision != -1 && (ft_strchr("sS", lst->type)) != NULL)
	{
		str = apply_precision_str(lst, str);
//		ft_putchar('8');
	}
	if (lst->field != -1 && lst2->zero != 1)
	{
		str = apply_field_space(lst, lst2, str, ft_strlen(str));
//		ft_putchar('9');
	}
	if (lst2->space == 1)
	{
		str = apply_space(str);
//		ft_putchar('0');
	}
	ft_putstr(str);
}

int			ft_printf(const char *format, ...)
{
	va_list	argptr;
	int		i;

	i = 0;
	va_start(argptr, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] == '%')
		{
			ft_putchar('%');
			i++;
		}
		else if (format[i] == '%')
		{
			i = seek_types(++i, format, argptr);
			i--;
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	return (/*nombre de caractere imprime*/0);
}

int			main(void)
{
	char *ptr;

	ptr = "hey";
	ft_printf("%12p bonjour %+20.20ld je m'appelle %12C dorian %12.3s %#18.19o %#12.20x %-12.20X %+12.20hd %12.20u %%%%%%", ptr, (long)2147483648, 'f', "merci", 1234567, -1, 1234567, (short)32768, 1234567);
	printf("\n%12p bonjour %+20.20ld je m'appelle %12C dorian %12.3s %#18.19o %#12.20x %-12.20X %+12.20hd %12.20u %%%%%%", ptr, (long)2147483648, 'f', "merci", 1234567, -1, 1234567, (short)32768, 1234567);
}
