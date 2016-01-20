/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 12:11:22 by droly             #+#    #+#             */
/*   Updated: 2016/01/20 15:02:12 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"

typedef	struct		s_printf
{
	char			*content;
	struct s_printf	*next;
}					t_printf;

int	ft_printf(const char *format, ...);
int	percent_int(const char *format, int i, int ret);
int	percent_char_str_ptr(const char *format, int i, int ret);

#endif
