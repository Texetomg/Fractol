/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 22:50:19 by bfalmer-          #+#    #+#             */
/*   Updated: 2018/11/28 22:50:20 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb < 0 && nb * -1 != nb)
	{
		ft_putchar_fd('-', fd);
		nb *= -1;
	}
	if (nb % 10 != nb)
		ft_putnbr_fd(nb / 10, fd);
	if (nb % 10 > 0)
		ft_putchar_fd(nb % 10 + '0', fd);
	else
		ft_putchar_fd(nb % 10 * (-1) + '0', fd);
}
