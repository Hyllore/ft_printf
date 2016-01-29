/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 14:42:25 by droly             #+#    #+#             */
/*   Updated: 2016/01/29 16:01:57 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*p_adress(va_list ap)
{
	unsigned int  adr;
	char          *base;
	char          res[12];
	int           i;

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
	
}

char	*take_type2(t_printf *lst, char *str, va_list argptr)
{
	if (ft_strchr("Ss", lst->type))
		str = va_arg(*argptr, char*);
	if (ft_strchr("cC", lst->type))
		str = va_arg(*argptr, char);
	if (lst->type == 'p')
		str 
}
