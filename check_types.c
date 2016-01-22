/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 14:36:14 by droly             #+#    #+#             */
/*   Updated: 2016/01/22 16:52:48 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		percent_int(const char *format, int i, int ret)
{
	if (format[i] == 'd' || format[i] == 'D' || format[i] == 'i')
		ret = 1;
	if (format[i] == 'u' || format[i] == 'U')
		ret = 2;
	if (format[i] == 'o' || format[i] == 'O')
		ret = 3;
	if (format[i] == 'x')
		ret = 4;
	if (format[i] == 'X')
		ret = 5;
	return (ret);
}

int		percent_char_str_ptr(const char *format, int i, int ret)
{
	if (format[i] == 'c' || format[i] == 'C')
		ret = 6;
	if (format[i] == 's' || format[i] == 'S')
		ret = 7;
	if (format[i] == 'p')
		ret = 8;
	return (ret);
}

void	p_adress(va_list ap)
{
	unsigned int  adr;
	char          *base;
	char          res[9];
	int           i;

	adr = va_arg(ap, unsigned int);
	base = "0123456789abcdef";
	i = 8;
	while ((adr / 16) > 0)
	{
		res[i] = base[(adr % 16)];
		adr /= 16;
		i--;
	}
	res[i] = base[(adr % 16)];
	ft_putstr("0x10");
	while (i < 9)
		ft_putchar(res[i++]);
}
