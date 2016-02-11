/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 14:42:25 by droly             #+#    #+#             */
/*   Updated: 2016/02/11 15:54:14 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*put_in_maj(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 32;
		}
		i++;
	}
	return (str);
}

char	*take_type1(t_printf *lst, t_flags *lst2, char *str, va_list argptr)
{
	if ((ft_strchr("dDi", lst->type)) != NULL)
		str = ft_itoa(va_arg(argptr, int));
	if ((ft_strchr("x", lst->type)) != NULL)
		str = ft_itoa_base((int)va_arg(argptr, unsigned int), 16);
		if (lst2->diese == 1 && ft_strchr("xX", lst->type) != NULL)
			lst->field -= 2;
	if ((ft_strchr("X", lst->type)) != NULL)
	{
		str = ft_itoa_base((int)va_arg(argptr, unsigned int), 16);
		str = put_in_maj(str);
	}
	if ((ft_strchr("oO", lst->type)) != NULL)
	{
		if (lst2->diese == 1)
			lst->field -= 1;
		str = ft_itoa_base((int)va_arg(argptr, unsigned int), 8);
	}
	if ((ft_strchr("uU", lst->type)) != NULL)
		str = ft_utoa(va_arg(argptr, unsigned int));
	return (str);
}

char	*take_type2(t_printf *lst, char *str, va_list argptr)
{
	char *c;
	char *tmp;

	tmp = NULL;
	if ((ft_strchr("Ss", lst->type)) != NULL)
		str = va_arg(argptr, char*);
	if ((ft_strchr("cC", lst->type)) != NULL)
	{
		if (lst->field == -1)
			c = (char*)malloc(sizeof(char) * 2);
		if (lst->field != -1)
			c = (char*)malloc(sizeof(char) * (lst->field) - 1);
		c[0] = va_arg(argptr, int);
		c[1] = '\0';
		str = c;
	}
	if (lst->type == 'p')
	{
		str = ft_itoa_base((int)va_arg(argptr, unsigned int), 16);
		while (ft_strlen(str) != 8)
			str = ft_strjoin("0", str);
		str = ft_strjoin("0x1", str);
	}
	return (str);
}
