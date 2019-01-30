/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:42:56 by bfalmer-          #+#    #+#             */
/*   Updated: 2018/11/27 19:42:58 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i_begin;
	size_t	i_end;
	char	*str;

	if (!s)
		return (NULL);
	i_begin = 0;
	i_end = ft_strlen(s) - 1;
	while (s[i_begin] && (s[i_begin] == ' ' ||
		s[i_begin] == '\n' || s[i_begin] == '\t'))
		i_begin++;
	while (s && (s[i_end] == ' ' ||
		s[i_end] == '\n' || s[i_end] == '\t'))
		i_end--;
	if (i_begin == ft_strlen(s))
	{
		str = ft_strnew(0);
		return (str);
	}
	str = ft_strsub(s, i_begin, i_end - i_begin + 1);
	return (str);
}
