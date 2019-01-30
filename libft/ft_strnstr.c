/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 20:12:39 by bfalmer-          #+#    #+#             */
/*   Updated: 2018/11/26 20:12:41 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *needle, size_t len)
{
	char	*hays;
	char	*need;
	size_t	index;
	size_t	buff;

	index = 0;
	while (h[index] && index < len)
	{
		buff = index;
		hays = (char *)(h + index);
		need = (char *)needle;
		while (*need && *hays == *need && buff < len)
		{
			hays++;
			need++;
			buff++;
		}
		buff = 0;
		if (*need == '\0')
			return ((char *)(h + index));
		index++;
	}
	if (*needle == '\0')
		return ((char *)(h + index));
	return (NULL);
}
