/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 12:11:22 by droly             #+#    #+#             */
/*   Updated: 2016/02/01 11:36:29 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"

typedef	struct		s_flags
{
	int			diese;
	int			zero;
	int			minus;
	int			plus;
	int			space;
}					t_flags;

typedef	struct		s_printf
{
	int			field;
	int			precision;
	char*		len_modif;
	char		type;
}					t_printf;

int	ft_printf(const char *format, ...);
int	percent_int(const char *format, int i, int ret);
int	percent_char_str_ptr(const char *format, int i, int ret);
char	*p_adress(va_list ap);

#endif
