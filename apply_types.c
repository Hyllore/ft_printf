/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 12:37:22 by droly             #+#    #+#             */
/*   Updated: 2016/02/08 17:56:45 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*apply_diese(t_printf *lst, t_flags *lst2, char *str)
{
	if (lst->type == 'o' || lst->type == 'O')
		str = ft_strjoin("0", str);
	if (lst->type == 'x')
		str = ft_strjoin("0x", str);
	if (lst->type == 'X')
		str = ft_strjoin("0X", str);
	return (str);
}

char	*apply_plus(t_printf *lst, t_flags *lst2, char *str)
{
	if (ft_atoi(str) >= 0)
		str = ft_strjoin("+", str);
	return (str);
}

char	*apply_space(t_printf *lst, t_flags *lst2, char *str)
{
	if (ft_atoi(str) >= 0)
		str = ft_strjoin(" ", str);
	return (str);
}

char	*apply_field(t_printf *lst, t_flags *lst2, char *str)
{

}

