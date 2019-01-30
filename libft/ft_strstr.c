/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 19:16:50 by bfalmer-          #+#    #+#             */
/*   Updated: 2018/11/26 19:16:52 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*hays;
	char	*need;
	size_t	index;

	index = 0;
	if (ft_strlen(needle) == 0)
		return ((char*)haystack);
	while (haystack[index])
	{
		hays = (char *)(haystack + index);
		need = (char *)needle;
		while (*need && *hays == *need)
		{
			hays++;
			need++;
		}
		if (*need == '\0')
			return ((char *)(haystack + index));
		index++;
	}
	if (*needle == '\0')
		return ((char *)(haystack + index));
	return (NULL);
}
