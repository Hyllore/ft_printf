/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 16:31:16 by droly             #+#    #+#             */
/*   Updated: 2016/02/05 11:31:46 by droly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		aux_dix(int n, char *ans, int *p)
{
	if (n < -9 || 9 < n)
		aux_dix(n / 10, ans, p);
	ans[(*p)++] = '0' + ((n % 10) < 0 ? -(n % 10) : (n % 10));
}

void		aux(unsigned int n, unsigned int b, char *ans, int *p)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= b)
		aux(n / b, b, ans, p);
	ans[(*p)++] = base[n % b];
}

char		*ft_itoa_base(int value, int base)
{
	char	*ans;
	int		p;

	if (base < 2 || 16 < base
			|| !(ans = (char *)malloc(sizeof(char) * 35)))
		return (NULL);
	p = 0;
	if (base == 10 && value < 0)
		ans[p++] = '-';
	if (base == 10)
		aux_dix(value, ans, &p);
	else
		aux((unsigned int)value, (unsigned int)base, ans, &p);
	ans[p] = '\0';
	return (ans);
}
