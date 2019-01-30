/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:57:55 by bfalmer-          #+#    #+#             */
/*   Updated: 2018/11/23 17:57:55 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int index;

	index = 0;
	while (s1[index])
		index++;
	while (*s2 && (n--))
	{
		s1[index] = *s2;
		index++;
		s2++;
	}
	s1[index] = '\0';
	return (s1);
}
