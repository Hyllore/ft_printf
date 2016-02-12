/*penser a generer le header*/

#include "ft_printf.h"

char	*apply_precision(t_printf *lst, t_flags *lst2, char *str)
{
	int i;
	char *tmp;

	tmp = NULL;
	i = 0;
	if (ft_strchr("sS", lst->type) != NULL)
	{
		if (ft_strlen(str) > lst->precision)
		{
			lst->precision = ft_strlen(str) - lst->precision;
			while (lst->precision > 0)
			{
				i = 0;
				ft_putchar(str[i]);
				tmp = ft_memalloc(ft_strlen(str));
				ft_strcpy(tmp, str);
				str = ft_memalloc(ft_strlen(tmp));
				ft_strcpy(str, tmp);
				while (tmp[i + 1] != '\0')
					i++;
				tmp[i] = '\0';
				ft_putchar('e');
				lst->precision -= 1;
			}
		}
	}
	return (tmp);
}
