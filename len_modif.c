/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_modif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 14:03:51 by droly             #+#    #+#             */
/*   Updated: 2016/02/18 14:24:59 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*len_modif_d_i(t_printf *lst, char *str, va_list argptr)
{
	long long i;

	i = 0;
	if (ft_strchr("hj", lst->len_modif[0]))
		str = len_modif_h_j(lst, str, argptr, i);
	if (ft_strchr("lz", lst->len_modif[0]))
		str = len_modif_l_z(lst, str, argptr, i);
	return (str);
}

static char	*apply_types2(t_printf *lst, char *str, t_flags *lst2)
{
	long long i;

	i = ft_atoi(str);
	if ((ft_strchr("x", lst->type)) != NULL)
		str = ft_itoa_base(i, 16);
	if (lst2->diese == 1 && ft_strchr("xX", lst->type) != NULL)
		lst->field -= 2;
	if ((ft_strchr("X", lst->type)) != NULL)
	{
		str = ft_itoa_base(i, 16);
		str = put_in_maj(str);
	}
	if ((ft_strchr("oO", lst->type)) != NULL)
	{
		if (lst2->diese == 1)
			lst->field -= 1;
		str = ft_itoa_base(i, 8);
	}
	if ((ft_strchr("uU", lst->type)) != NULL)
		str = ft_utoa(i);
	return (str);
}

char		*len_modif_o_u(t_printf *lst, char *str, va_list argptr,
		t_flags *lst2)
{
	long long i;

	i = 0;
	if (ft_strchr("hj", lst->len_modif[0]))
		str = len_modif_h_j2(lst, str, argptr, i);
	if (ft_strchr("lz", lst->len_modif[0]))
		str = len_modif_l_z2(lst, str, argptr, i);
	str = apply_types2(lst, str, lst2);
	return (str);
}
