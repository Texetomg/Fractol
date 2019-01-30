/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:20:37 by bfalmer-          #+#    #+#             */
/*   Updated: 2018/11/27 17:20:38 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		index;

	if (!s || !f)
		return (NULL);
	str = ft_strdup(s);
	index = 0;
	if (!str)
		return (NULL);
	while (s[index])
	{
		str[index] = f(index, s[index]);
		index++;
	}
	return (str);
}
