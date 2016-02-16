/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_types2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 18:06:14 by droly             #+#    #+#             */
/*   Updated: 2016/02/16 17:30:15 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
char		*apply_precision_str(t_printf *lst, char *str)
{
	int		i;
	char	*tmp;

	tmp = NULL;
	i = 0;
	if (ft_strchr("sS", lst->type) != NULL)
	{
		if (ft_strlen(str) > (size_t)lst->precision)
		{
			lst->precision = ft_strlen(str) - lst->precision;
			while (lst->precision > 0)
			{
				i = 0;
				tmp = ft_memalloc(ft_strlen(str));
				ft_strcpy(tmp, str);
				str = ft_memalloc(ft_strlen(tmp));
				ft_strcpy(str, tmp);
				while (str[i + 1] != '\0')
					i++;
				str[i] = '\0';
				lst->precision -= 1;
			}
		}
	}
	return (str);
}

char		*apply_precision_num(t_printf *lst, char *str, int i)
{
	char	c[2];

	ft_bzero(c, 2);
	if (ft_strchr("oO", lst->type) != NULL)
		i++;
	if (i < lst->precision)
	{
		lst->precision = ((lst->precision) - i);
		if (str[0] == '-')
		{
			c[0] = str[0];
			str[0] = '0';
		}
		while (lst->precision > 0)
		{
			str = ft_strjoin("0", str);
			lst->precision = ((lst->precision) - 1);
		}
		if (c[0] != 0)
			str = ft_strjoin(c, str);
	}
	return (str);
}

char		*len_modif_d_i(t_printf *lst, char *str, va_list argptr)
{
	long long i;
	int i2;

	i2 = 0;
	i = 0;
//	i = ft_atoi(str);
	ft_putchar('e');
//	printf("%d" , (int)i);
//	if (i < 0)
//	{
//		i2 = 1;
//		i = i * -1;
//	}
	if (lst->len_modif[0] == 'h' && lst->len_modif[1] == 'h')
	{
		ft_putchar('a');
		str = ft_utoa(va_arg(argptr, int));
	}
	else if (ft_strchr("h", lst->len_modif[0]) != NULL)
	{
		ft_putchar('b');
		str = ft_utoa((short)va_arg(argptr, int));
	}
	else if (lst->len_modif[0] == 'l' && lst->len_modif[1] == 'l')
	{
		ft_putchar('c');
		str = ft_utoa(va_arg(argptr, long long));
	}
	else if (ft_strchr("l", lst->len_modif[0]) != NULL)
	{
		ft_putchar('d');
		str = ft_utoa(va_arg(argptr, long));
	}
	else if (ft_strchr("j", lst->len_modif[0]) != NULL)
	{
		ft_putchar('e');
		str = ft_utoa(va_arg(argptr, intmax_t));
	}
	else if (ft_strchr("z", lst->len_modif[0]) != NULL)
	{
		ft_putchar('f');
		str = ft_utoa(va_arg(argptr, int));
	}
	if (i2 == 1)
		str = ft_strjoin("-", str);
	return (str);
}

char		*len_modif_o_u(t_printf *lst, char *str, va_list argptr)
{

}

char		*apply_len_modif(t_printf *lst, char *str, va_list argptr)
{
	if (ft_strchr("dDi", lst->type) != NULL)
		str = len_modif_d_i(lst, str, argptr);
	if (ft_strchr("oOuUxX", lst->type) != NULL)
		str = len_modif_o_u(lst, str, argptr);
	return (str);
}
