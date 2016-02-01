/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 14:42:25 by droly             #+#    #+#             */
/*   Updated: 2016/02/01 16:26:24 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//char	*put_in_maj(char *str)
//{
//	int i;
//
//	i = 0;
//	while (str[i] != '\0')
//	{
//		if (str[i] >= 'a' && str[i] <= 'z')
//		{
//			str[i] -= 32;
//		}
//		i++;
//	}
//	return (str);
//}

char	*hexa_adress(va_list ap)
{
	unsigned int  adr;
	char          *base;
	char          *res;
	int           i;

	i = 0;
	res = malloc(sizeof(char) * 12);
	adr = va_arg(ap, unsigned int);
	base = "0123456789abcdef";
	i = 8;
	res[0] = '0';
	res[1] = 'x';
	res[2] = '1';
	res[3] = '0';
	while ((adr / 16) > 4)
	{
		res[i] = base[(adr % 16)];
		adr /= 16;
		i--;
	}
	res[i] = base[(adr % 16)];
	res[11] = '\0';
	return (res);
}

char	*take_type1(t_printf *lst, char *str, va_list argptr)
{
	if ((ft_strchr("dDi", lst->type)) != NULL)
		str = ft_itoa(va_arg(argptr, int));
//	if ((ft_strchr("x", lst->type)) != NULL)
//		str = hexa(argptr);
//	if ((ft_strchr("X", lst->type)) != NULL)
//	{
//		str = hexa(argptr);
//		str = put_in_maj(str);
	}
}

char	*take_type2(t_printf *lst, char *str, va_list argptr)
{
	if ((ft_strchr("Ss", lst->type)) != NULL)
		str = va_arg(argptr, char*);
	if ((ft_strchr("cC", lst->type)) != NULL)
		*str = va_arg(argptr, int);
	if (lst->type == 'p')
		str = hexa_adress(argptr);
}
