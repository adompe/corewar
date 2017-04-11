/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 12:57:28 by rfernand          #+#    #+#             */
/*   Updated: 2016/11/24 15:41:48 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**alloc_str(t_gnl *elem, char **str, char *buf)
{
	int		i;
	int		n;
	char	*buffer;

	n = 0;
	i = 0;
	buffer = NULL;
	if (str[0])
	{
		i = ft_strlen(str[0]);
		buffer = malloc((ft_strlen(str[0]) + 1) * sizeof(char));
		ft_strcpy(buffer, str[0]);
		free(str[0]);
	}
	while (buf[n] != '\n' && buf[n] && buf[0])
		n++;
	while (elem->rest[n] != '\n' && elem->rest[n] && !buf[0])
		n++;
	str[0] = malloc((i + n + 1) * sizeof(char));
	ft_bzero(str[0], i + n + 1);
	if (buffer)
		ft_strcpy(str[0], buffer);
	free(buffer);
	return (str);
}

static t_gnl	*create_node(t_gnl *begin, int fd)
{
	t_gnl *elem;

	if (!begin)
	{
		elem = malloc(sizeof(t_list));
		if (elem)
		{
			elem->fd = 257;
			elem->rest = NULL;
			elem->next = NULL;
		}
		return (elem);
	}
	elem = begin;
	while (elem->next && elem->fd != fd)
		elem = elem->next;
	if (elem->fd == fd)
		return (elem);
	elem->next = malloc(sizeof(t_list));
	elem->next->fd = fd;
	elem->next->state = 0;
	elem->next->next = NULL;
	elem->next->rest = malloc((BUFF_SIZE + 1) * sizeof(char));
	ft_bzero(elem->next->rest, BUFF_SIZE + 1);
	return (elem->next);
}

static int		stock_rest(t_gnl *elem, char **str, char *buf)
{
	int i;

	i = 0;
	str[0] = NULL;
	if (elem->rest[0] == '\0')
		return (0);
	str = alloc_str(elem, str, buf);
	while (elem->rest[i] && elem->rest[i] != '\n')
	{
		str[0][i] = elem->rest[i];
		i++;
	}
	str[0][i] = '\0';
	if (elem->rest[i] == '\n')
	{
		i++;
		ft_memmove(elem->rest, elem->rest + i, BUFF_SIZE - i);
		ft_bzero(elem->rest + (BUFF_SIZE - i), i + 1);
		return (1);
	}
	return (0);
}

static int		stock_buf(t_gnl *elem, char *buf, char **str)
{
	int i;
	int n;

	n = 0;
	if (!buf[0] && !elem->rest[0] && elem->state)
		return (3);
	elem->state = 0;
	ft_bzero(elem->rest, BUFF_SIZE);
	str = alloc_str(elem, str, buf);
	i = ft_strlen(str[0]);
	while (buf[n] && buf[n] != '\n')
		str[0][i++] = buf[n++];
	if (!buf[n] && n < BUFF_SIZE)
		return (elem->state = 1);
	if (buf[n] == '\n')
	{
		n++;
		i = 0;
		while (buf[n])
			elem->rest[i++] = buf[n++];
		ft_bzero(buf, BUFF_SIZE);
		return (elem->state = 1);
	}
	ft_bzero(buf, BUFF_SIZE);
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	static t_gnl	*begin;
	t_gnl			*elem;
	char			buf[BUFF_SIZE + 1];
	int				u;
	int				i;

	if (!line || BUFF_SIZE < 1)
		return (-1);
	i = 1;
	ft_bzero(buf, BUFF_SIZE + 1);
	u = 0;
	if (!begin)
		begin = create_node(NULL, -1);
	elem = begin;
	if (elem->fd != fd)
		elem = create_node(elem, fd);
	u = stock_rest(elem, line, buf);
	while (!u || u == 2)
	{
		if ((i = read(fd, buf, BUFF_SIZE) == -1))
			return (-1);
		if ((u = stock_buf(elem, buf, line)) == 3)
			return (0);
	}
	return (1);
}
