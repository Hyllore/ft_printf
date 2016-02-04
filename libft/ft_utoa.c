/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 13:47:04 by droly             #+#    #+#             */
/*   Updated: 2016/02/04 16:35:04 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_num(unsigned int num)
{
	int	i;

	if (num == 0)
		return (1);
	i = 0;
	while (num)
	{
		num /= 10;
		i += 1;
	}
	return (i);
}

static char			*ft_num_in_str(unsigned int n, char *str, int i)
{
	while (i >= 0)
	{
		str[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	return (str);
}

char				*ft_utoa(unsigned int n)
{
	char			*str;
	int				i;

	i = ft_strlen_num(n);
	if (!(str = (char *)malloc(sizeof(char) * (1 + i))))
		return (NULL);
	str[i] = '\0';
	return (ft_num_in_str(n, str, i - 1));
}
