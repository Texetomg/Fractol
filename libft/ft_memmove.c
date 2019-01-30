/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:05:30 by bfalmer-          #+#    #+#             */
/*   Updated: 2018/11/22 14:05:32 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	int i;

	i = -1;
	if (src < dest)
		ft_memcpy(dest, src, len);
	else
	{
		while ((size_t)++i < len)
			((char *)dest)[i] = ((char *)src)[i];
	}
	return (dest);
}
