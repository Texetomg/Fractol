/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:53:40 by bfalmer-          #+#    #+#             */
/*   Updated: 2018/11/27 16:53:41 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		index;

	if (!s || !f)
		return (NULL);
	index = 0;
	str = ft_strdup(s);
	if (!str)
		return (NULL);
	while (s[index])
	{
		str[index] = f(s[index]);
		index++;
	}
	return (str);
}
