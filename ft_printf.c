/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 11:53:32 by droly             #+#    #+#             */
/*   Updated: 2016/02/05 14:23:00 by droly            ###   ########.fr       */
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
/*	if (lst2->diese == 1)
		apply_diese(lst, lst2, str);
	if (lst2->zero == 1)
		apply_zero(lst, lst2, str);
	if (lst2->minus == 1)
		apply_minus(lst, lst2, str);
	if (lst2->plus == 1)
		apply_plus(lst, lst2, str);
	if (lst2->space == 1)
		apply_space(lst, lst2, str);*/
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
			i += 2;
		}
		if (format[i] == '%' && format[i + 1] != '%')
		{
			i++;
			i = seek_types(i, format, argptr);
		}
		if (format[i] != '\0')
		{
			ft_putchar(format[i]);
			i++;
		}
	}
	return (/*nombre de caractere imprime*/0);
}

int			main(void)
{
	char *ptr;

	ptr = "hey";
	ft_printf("%p bonjour %i je m'appelle %C dorian %S %o %x %X %d %u %%%%%%", ptr, 1234567, 'f', "merci", 1234567, 1234567, 1234567, 1234567, 1234567);
	printf("\n%p bonjour %i je m'appelle %C dorian %s %o %x %X %d %u %%%%%%", ptr, 1234567, 'f', "merci", 1234567, 1234567, 1234567, 1234567, 1234567);
}
