/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 11:53:32 by droly             #+#    #+#             */
/*   Updated: 2016/01/28 15:30:01 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
/*
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
	int		ret;

	if (format[0] == '%' && format[0 + 1] != '%')
	{
		ret = percent_int(format, 1, ret);
		ret = percent_char_str_ptr(format, 1, ret);
	}
	return(ret);
}

void	apply_types(int ret, va_list *argptr)
{
	char c;
	char *ptr;
	int num;
	void *ad;
	unsigned int u;

	num = 0;
	if (ret == 6)
	{
		c = va_arg(*argptr, int);
		ft_putchar(c);
	}
	if (ret == 7)
	{
		ptr = va_arg(*argptr, char*);
		ft_putstr(ptr);
	}
	if (ret == 1)
	{
		num = va_arg(*argptr, int);
		ft_putnbr(num);
	}
	if (ret == 8)
	{
		p_adress(*argptr);
	}
	if (ret == 2)
	{
		u = va_arg(*argptr, unsigned int);
		ft_putnbr_u(u);
//		ptr = ft_itoa_u(u);
//		ft_putstr(ptr);
	}
}

int			ft_printf(const char *format, ...)
{
	va_list	argptr;
	int		i;
	int		ret;
	int i2 = 0;

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
		ret = 0;
		ret = search_types(&format[i2]);
		if (ret == 0)
			return (0);
		apply_types(ret, &argptr);
		i--;
	}
	va_end(argptr);
	return (1);
}*/

int		seek_len_modif_types(t_printf *lst, const char *format, int i)
{
	char *v;
	int i2;

	i = 0;
	while ((v = strchr("hljz", format[i])) != NULL)
	{
		lst->len_modif[i2] = format[i];
		i++;
		i2++;
	}
	if ((v = strchr("sSpdDioOuUxXcC", format[i])) != NULL)
	{
		lst->type = format[i];
		i++;
	}
	return (i);
}

int		seek_field_precision(t_printf *lst, const char *format, int i, va_list argptr)
{
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
	return (i);
}

int		seek_flags(t_flags *lst2, const char *format, int  i)
{
	char *t;

	while ((t = strchr("#0-+ ", format[i])) != NULL)
	{
		lst2->diese = t[0] == '#';
		lst2->zero = t[0] == '0';
		lst2->minus = t[0] == '-';
		lst2->plus = t[0] == '+';
		lst2->space = t[0] == ' ';
		i++;
	}
	return (i);
}

int	seek_types(int i, const char *format, va_list argptr, ...)
{
	t_printf *lst;
	t_flags *lst2;
	
	i = seek_flags(lst2, format, i);
	i = seek_field_precision(lst, format, i, argptr);
	i = seek_len_modif_types(lst, format, i);
	apply_flags();
	apply_field_precision();
	apply_len_modif_types();
	return (i);
}

int			ft_printf(const char *format, ...)
{
	va_list	argptr;
	int		i;
	int		ret;
	int i2;

	i2 = 0;
	ret = 0;
	va_start(argptr, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] == '%')
		{
			ft_putchar('%');
			i += 2;
		}
		if (format[i] == '%')
		{
			i++;
			seek_types(i, format, argptr);
		}
		ft_putchar(format[i]);
		i++;
	}
	return (/*nombre de caractere imprime*/);
}

#include <limits.h>

#define aprintf(...) printf(": [%d] printf\n", printf(__VA_ARGS__));\
						printf(": [%d] ft_printf\n", ft_printf(__VA_ARGS__))

int			main(void)
{
	char *ptr;

	ptr = "hey";
//	if (ft_printf("%p bonjour %d je %u m'appelle %c dorian %s", ptr, 42, INT_MIN -1, 'f', "merci") == 0)
//		ft_putendl("error");
	aprintf("%u" , 0);
	aprintf("%u" , INT_MAX);
	aprintf("%u" , -1);
	aprintf("%u" , INT_MIN -1);
	aprintf("%d" , INT_MAX + 1);
}
