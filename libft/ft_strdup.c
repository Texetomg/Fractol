/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:38:47 by bfalmer-          #+#    #+#             */
/*   Updated: 2018/11/23 15:38:48 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		length;

	length = ft_strlen(s1) + 1;
	s2 = (char*)malloc(sizeof(char) * length);
	if (s2 == NULL)
		return (NULL);
	else
	{
		ft_strcpy(s2, s1);
		return (s2);
	}
}
