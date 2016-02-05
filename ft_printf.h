/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 12:11:22 by droly             #+#    #+#             */
/*   Updated: 2016/02/05 12:40:22 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"

typedef struct	s_flags
{
	int			diese;
	int			zero;
	int			minus;
	int			plus;
	int			space;
}				t_flags;

typedef struct	s_printf
{
	int			field;
	int			precision;
	char		*len_modif;
	char		type;
}				t_printf;

int				ft_printf(const char *format, ...);
t_printf		seek_len_modif_types(t_printf *lst, const char *format, int i);
t_printf		seek_field_precision(t_printf *lst, const char *format,
		int i, va_list argptr);
t_flags			seek_flags(t_flags *lst2, const char *format, int i, char *lst);
int				seek_types(int i, const char *format, va_list argptr);
void			apply_flags(t_printf *lst, t_flags *lst2, va_list argptr);
char			*put_in_maj(char *str);
char			*take_type1(t_printf *lst, char *str, va_list argptr);
char			*take_type2(t_printf *lst, char *str, va_list argptr);

#endif
