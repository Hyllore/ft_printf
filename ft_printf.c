/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 11:53:32 by droly             #+#    #+#             */
/*   Updated: 2016/02/17 17:36:50 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void		apply_flags(t_printf *lst, t_flags *lst2, va_list argptr, char *str)
{
	if ((ft_strchr("dDioOuUxX", lst->type)) != NULL && (lst->len_modif[0] != 'h'
				&& lst->len_modif[0] != 'l' && lst->len_modif[0] != 'j' &&
				lst->len_modif[0] != 'z'))
		str = take_type1(lst, lst2, str, argptr);
	if ((ft_strchr("sSpcC", lst->type)) != NULL)
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
	return (/*nombre de caractere imprime*/1);
}

/*int			main(void)
{
	char *ptr;

	ptr = "hey";
	ft_printf("\n");
}
	ft_printf("d %+19.19d o %#18.19o x %#12.20x X %-12.20lX d %+12.20hd d %+12.20hd u %12.20u %%%%%%", 42, 1234567, -1, (unsigned long)4294967296, (short)-922337203685477580,(short)42, 1234567);
	printf("\nd %+19.19d o %#18.19o x %#12.20x X %-12.20lX d %+12.20hd d %+12.20hd u %12.20u %%%%%%", 42, 1234567, -1, (unsigned long)4294967296, (short)-922337203685477580,(short)42, 1234567);
}*/
