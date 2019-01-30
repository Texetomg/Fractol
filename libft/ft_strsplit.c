/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:41:20 by bfalmer-          #+#    #+#             */
/*   Updated: 2018/11/28 15:41:23 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_size(char *s, char c)
{
	int		index;

	index = 0;
	while (s[index] && s[index] != c)
		index++;
	return (index);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	s_i;

	if (!s)
		return (NULL);
	s_i = 0;
	i = 0;
	str = (char**)malloc(sizeof(char *) * (ft_str_word_cnt(s, c) + 1));
	if (!str)
		return (NULL);
	str[ft_str_word_cnt(s, c)] = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (ft_size((char*)(s + i), c) != 0)
		{
			str[s_i] = ft_strsub((char*)s, i, ft_size((char*)(s + i), c));
			if (!str[s_i++])
				return (NULL);
			i = i + ft_size((char*)(s + i), c);
		}
	}
	return (str);
}
