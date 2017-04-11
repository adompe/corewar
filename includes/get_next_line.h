/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 16:20:35 by rfernand          #+#    #+#             */
/*   Updated: 2016/11/09 12:33:39 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32

typedef struct		s_gnl
{
	int				fd;
	int				state;
	char			*rest;
	struct s_gnl	*next;
}					t_gnl;

int					get_next_line(int const fd, char **line);

#endif
