/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 11:53:32 by droly             #+#    #+#             */
/*   Updated: 2016/01/21 16:55:36 by droly            ###   ########.fr       */
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
		i++;
	}
	return(ret);
}

void	apply_types(int ret, va_list argptr, ...)
{
	char c;
	char *ptr;
	int num;

	num = 0;
	if (ret == 6)
	{
		c = va_arg(argptr, int);
		va_end(argptr);
		ft_putchar(c);
	}
	if (ret == 7)
	{
		ptr = va_arg(argptr, char*);
		va_end(argptr);
		ft_putstr(ptr);
	}
	if (ret == 1)
	{
		num = va_arg(argptr, int);
		va_end(argptr);
		ptr = ft_itoa(num);
		ft_putstr(ptr);
	}
}

int			ft_printf(const char *format, ...)
{
	va_list	argptr;
	int		i;
	int		ret;
	static int i2 = 0;

	ret = 0;
	i = count_percent(format);
	va_start(argptr, format);
	while (i > 0)
	{
		while (format[i2] != '%' && format[i2] != '\0')
		{
			ft_putchar(format[i2]);
			i2++;
		}
		i2 += 2;
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
	if (ft_printf("bonjour %d je m'appelle %c dorian %s" , 42, 'f', "merci") == 0)
		ft_putendl("error");
}
