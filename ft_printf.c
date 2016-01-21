/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 11:53:32 by droly             #+#    #+#             */
/*   Updated: 2016/01/21 13:35:29 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			count_percent(const char *str)
{
	int		i;
	int		i2;

	i2 = 0;
	i = 0;
	while (str[i2] != '\0')
	{
		if (str[i2] == '%' && str[i2 + 1] != '%' && str[i2 - 1] != '%' && 
			str[i2 + 1] != '\0')
		{
			i++;
		}
		i2++;
	}
	return (i);
}

int			search_types(const char *format)
{
	static	int i = 0;
	int		ret;

	ret = 0;
	while (ret == 0)
	{
		if (format[i] == '%' && format[i + 1] != '%')
			{
				i++;
				ret = percent_int(format, i, ret);
				ret = percent_char_str_ptr(format, i, ret);
				i++;
			}
		if (format[i] != '%')
			ft_putchar(format[i]);
		i++;
	}
	return(ret);
}

void	apply_types(int ret, va_list argptr, ...)
{
	char ptr;
	if (ret == 6)
	{
		ptr = va_arg(argptr, int);
	}
	va_end(argptr);
	ft_putchar(ptr);
}

int			ft_printf(const char *format, ...)
{
	va_list	argptr;
	int		i;
	int		ret;

	ret = 0;
	i = count_percent(format);
	va_start(argptr, format);
	while (i > 0)
	{
		ret = 0;
		ret = search_types(format);
		if (ret == 0)
			return (0);
		apply_types(ret, argptr);
		i--;
	}
	return (1);
}

int			main(void)
{
	if (ft_printf("%c %c %c" , 'e', 'f', 'k') == 0)
		ft_putendl("error");
}
