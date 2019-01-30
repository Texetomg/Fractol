/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:46:16 by bfalmer-          #+#    #+#             */
/*   Updated: 2018/11/27 17:46:45 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	i = 0;
	if (!s || start + len > ft_strlen(s))
		return (NULL);
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	ft_strncpy(str, s + start, len);
	return (str);
}
