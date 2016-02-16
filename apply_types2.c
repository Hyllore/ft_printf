/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_types2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 18:06:14 by droly             #+#    #+#             */
/*   Updated: 2016/02/16 14:12:01 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

char		*len_modif_d_i(t_printf *lst, char *str)
{
	long long i;

	i = 0;
	i = (long long)ft_atoi(str);
	if ((ft_strchr("h", lst->len_modif[0]) != NULL) &&
			(ft_strchr("h", lst->len_modif[1]) != NULL))
		str = ft_utoa((char)i);
	else if (ft_strchr("h", lst->len_modif[0]) != NULL)
		str = ft_utoa((short)i);
	else if (ft_strchr("l", lst->len_modif[0]) != NULL)
		str = ft_utoa((long)i);
	else if ((ft_strchr("l", lst->len_modif[0]) != NULL) &&
			(ft_strchr("l", lst->len_modif[1]) != NULL))
		str = ft_utoa((long long)i);
	else if (ft_strchr("j", lst->len_modif[0]) != NULL)
		str = ft_utoa((intmax_t)i);
	else if (ft_strchr("z", lst->len_modif[0]) != NULL)
		str = ft_utoa(i);
	return (str);
}

char		*len_modif_o_u(t_printf *lst, char *str)
{

}

char		*apply_len_modif(t_printf *lst, char *str)
{
	if (ft_strchr("dDi", lst->type) != NULL)
		str = len_modif_d_i(lst, str);
	if (ft_strchr("oOuUxX", lst->type) != NULL)
		str = len_modif_o_u(lst, str);
	return (str);
}
