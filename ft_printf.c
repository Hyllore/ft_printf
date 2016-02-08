/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 11:53:32 by droly             #+#    #+#             */
/*   Updated: 2016/02/08 17:56:47 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void		apply_flags(t_printf *lst, t_flags *lst2, va_list argptr)
{
	char	*str;

	str = NULL;
	if ((ft_strchr("dDioOuUxX", lst->type)) != NULL)
		str = take_type1(lst, str, argptr);
	if ((ft_strchr("sSpcC", lst->type)) != NULL)
		str = take_type2(lst, str, argptr);
	if (lst2->diese == 1)
		 str = apply_diese(lst, lst2, str);
//	if (lst2->zero == 1)
//		apply_zero(lst, lst2, str);
//	if (lst2->minus == 1)
//		apply_minus(lst, lst2, str);
	if (lst2->plus == 1)
		str = apply_plus(lst, lst2, str);
	if (lst2->space == 1)
		str = apply_space(lst, lst2, str);
	ft_putnbr(lst->field);
	ft_putchar(' ');
	ft_putnbr(lst->precision);
	if (lst->field != -1)
		apply_field(lst, lst2, str);
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
	ft_printf("%p bonjour %i je m'appelle %C dorian %s %#o %#x %#X %+02000.100d %u %%%%%%", ptr, 1234567, 'f', "merci", 1234567, 1234567, 1234567, 1234567, 1234567);
	printf("\n%p bonjour %i je m'appelle %C dorian %s %#o %#x %#X %+d %u %%%%%%", ptr, 1234567, 'f', "merci", 1234567, 1234567, 1234567, 1234567, 1234567);
}
