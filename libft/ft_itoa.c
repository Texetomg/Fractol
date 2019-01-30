/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 21:33:55 by bfalmer-          #+#    #+#             */
/*   Updated: 2018/11/28 21:33:56 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_disch(int n)
{
	int		disch;

	disch = 1;
	n = ft_absolute(n);
	while (n >= 10)
	{
		disch++;
		n = n / 10;
	}
	return (disch);
}

char		*ft_itoa(int n)
{
	long	copy;
	int		disch;
	char	*str;
	int		neg;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	copy = n;
	neg = 0;
	if (n < 0)
		neg = 1;
	disch = ft_disch(n);
	str = ft_strnew(disch + neg);
	if (!str)
		return (NULL);
	if (neg)
		str[0] = '-';
	copy = ft_absolute(copy);
	while (disch > 0)
	{
		str[disch + neg - 1] = (copy % 10) + '0';
		disch--;
		copy = copy / 10;
	}
	return (str);
}
