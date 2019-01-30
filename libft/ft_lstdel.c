/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:46:03 by bfalmer-          #+#    #+#             */
/*   Updated: 2018/11/30 17:46:05 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *current_list;
	t_list *next_list;

	current_list = *alst;
	while (current_list)
	{
		next_list = current_list->next;
		del(current_list->content, current_list->content_size);
		free(current_list);
		current_list = next_list;
	}
	*alst = NULL;
}
