/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:33:53 by bfalmer-          #+#    #+#             */
/*   Updated: 2018/11/26 15:33:54 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	index;

	index = 0;
	while (dst[index])
		index++;
	while (*src && index + 1 < size)
	{
		dst[index] = *src;
		index++;
		src++;
	}
	dst[index] = '\0';
	if (index > size)
		return (ft_strlen(src) + size);
	else
		return (ft_strlen(src) + ft_strlen(dst));
}
