/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfalmer- <bfalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:24:02 by bfalmer-          #+#    #+#             */
/*   Updated: 2019/01/16 14:23:25 by bfalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_check_gnl(const int fd, t_list **gnl)
{
	t_list	*sub_gnl;

	sub_gnl = *gnl;
	while (sub_gnl)
	{
		if ((int)sub_gnl->content_size == fd && (*gnl)->content)
			return (sub_gnl);
		sub_gnl = sub_gnl->next;
	}
	sub_gnl = (t_list*)ft_memalloc(sizeof(t_list));
	sub_gnl->content_size = fd;
	sub_gnl->content = ft_memalloc(sizeof(char) * 1);
	ft_lstadd(gnl, sub_gnl);
	sub_gnl = *gnl;
	return (sub_gnl);
}

static int		ft_feel_line(char *content, char **line)
{
	int	index;

	index = -1;
	while (content[++index])
		if (content[index] == '\n')
			break ;
	*line = ft_strnew(index + 1);
	*line = ft_strncpy(*line, content, index);
	return (index);
}

static t_list	*ft_clear(t_list *sub_gnl, int read_length)
{
	char	*sub_str;

	if (read_length < (int)ft_strlen(sub_gnl->content))
	{
		sub_str = sub_gnl->content;
		sub_gnl->content = ft_strdup(sub_gnl->content + read_length + 1);
		ft_strdel(&sub_str);
	}
	else
		ft_strclr(sub_gnl->content);
	return (sub_gnl);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*gnl;
	t_list			*sub_gnl;
	char			buf_str[BUFF_SIZE + 1];
	char			*content_str;
	int				read_length;

	if (fd < 0 || !line || read(fd, buf_str, 0) < 0)
		return (-1);
	sub_gnl = ft_check_gnl(fd, &gnl);
	while ((read_length = read(fd, buf_str, BUFF_SIZE)))
	{
		buf_str[read_length] = 0;
		content_str = sub_gnl->content;
		sub_gnl->content = ft_strjoin(sub_gnl->content, buf_str);
		ft_strdel(&content_str);
	}
	if (read_length < BUFF_SIZE && !ft_strlen(sub_gnl->content))
		return (0);
	read_length = ft_feel_line(sub_gnl->content, line);
	sub_gnl = ft_clear(sub_gnl, read_length);
	return (1);
}
