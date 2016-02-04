/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 14:42:25 by droly             #+#    #+#             */
/*   Updated: 2016/02/04 17:36:29 by droly            ###   ########.fr       */
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

char	*take_type1(t_printf *lst, char *str, va_list argptr)
{
	if ((ft_strchr("dDi", lst->type)) != NULL)
		str = ft_itoa(va_arg(argptr, int));
	if ((ft_strchr("x", lst->type)) != NULL)
	{
		str = ft_itoa_base((int)va_arg(argptr, unsigned int), 16);
	}
	if ((ft_strchr("X", lst->type)) != NULL)
	{
		str = ft_itoa_base((int)va_arg(argptr, unsigned int), 16);
		str = put_in_maj(str);
	}
	if ((ft_strchr("oO", lst->type)) != NULL)
		str = ft_itoa_base((int)va_arg(argptr, unsigned int), 8);
	if ((ft_strchr("uU", lst->type)) != NULL)
		str = ft_utoa(va_arg(argptr, unsigned int));
	ft_putstr(str);
	return (NULL);
}

char	*take_type2(t_printf *lst, char *str, va_list argptr)
{
	char c;
	char *tmp;

	tmp = NULL;
	if ((ft_strchr("Ss", lst->type)) != NULL)
		str = va_arg(argptr, char*);
	if ((ft_strchr("cC", lst->type)) != NULL)
	{
		c = va_arg(argptr, int);
		str = malloc(sizeof(char));
		*str = c;
	}
	if (lst->type == 'p')
	{
		str = ft_itoa_base((int)va_arg(argptr, unsigned int), 16);
		tmp = "0x10";
		if (ft_strlen(str) != 7)
			tmp = "0x100";
		str = ft_strjoin(tmp, str);
	}
	ft_putstr(str);
	return (NULL);
}
