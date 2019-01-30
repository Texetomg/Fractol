/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 13:49:47 by bfalmer-          #+#    #+#             */
/*   Updated: 2018/12/02 13:49:48 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list_body;
	t_list	*list_start;

	if (!lst)
		return (NULL);
	list_body = f(lst);
	list_start = list_body;
	while (lst->next)
	{
		lst = lst->next;
		if (!(list_body->next = f(lst)))
		{
			free(list_body->next);
			return (NULL);
		}
		list_body = list_body->next;
	}
	return (list_start);
}
