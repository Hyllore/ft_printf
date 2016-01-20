/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 14:36:14 by droly             #+#    #+#             */
/*   Updated: 2016/01/20 16:52:39 by droly            ###   ########.fr       */
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
