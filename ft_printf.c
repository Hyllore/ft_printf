/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 11:53:32 by droly             #+#    #+#             */
/*   Updated: 2016/01/19 16:48:25 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_percent(const char *str)
{
	int i;
	int i2;

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

int	ft_printf(const char *format, ...)
{
	va_list argptr;
	int i;

	i = count_percent(format);
	va_start(argptr, format);
	while (i > 0)
	{
		
		i--;
	}
	return (0);
}

int	main(void)
{
	ft_printf("bonjour %d les %n %% ou%ai%");
}
