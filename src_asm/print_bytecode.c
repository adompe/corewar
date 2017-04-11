/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bytecode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adompe <adompe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:19:38 by adompe            #+#    #+#             */
/*   Updated: 2017/01/30 16:28:28 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_print_uint_hex(int fd, unsigned int nb, char l)
{
	unsigned int	b;

	b = 0;
	while (l > 4)
	{
		write(fd, &b, 1);
		l--;
	}
	if (l >= 4)
	{
		b = (nb & 0xFF000000) >> 24;
		write(fd, &b, 1);
		b = (nb & 0x00FF0000) >> 16;
		write(fd, &b, 1);
	}
	if (l >= 2)
	{
		b = (nb & 0x0000FF00) >> 8;
		write(fd, &b, 1);
	}
	b = (nb & 0x000000FF);
	write(fd, &b, 1);
}

void	ft_print_header(t_asm *data, int fd)
{
	t_header	*header;
	int			i;

	i = 0;
	header = data->header;
	ft_print_uint_hex(fd, header->magic, 4);
	while (i < PROG_NAME_LENGTH + 4)
	{
		if (header->prog_name[i] && i < (int)ft_strlen(header->prog_name))
			write(fd, &(header->prog_name[i]), 1);
		else
			ft_print_uint_hex(fd, 0, 1);
		i++;
	}
	i = 0;
	ft_print_uint_hex(fd, header->prog_size, 4);
	while (i < COMMENT_LENGTH + 4)
	{
		if (header->comment[i] && i < (int)ft_strlen(header->comment))
			write(fd, &(header->comment[i]), 1);
		else
			ft_print_uint_hex(fd, 0, 1);
		i++;
	}
}

char	*ft_get_name(char *str)
{
	int i;

	i = ft_strlen(str) - 1;
	while (str[i] && str[i] != '.')
		i--;
	if (!str[i])
		return (str);
	return (ft_strsub(str, 0, i));
}

void	ft_print_bytecode(t_asm *data, char *name)
{
	int fd;

	fd = open(ft_strcat(ft_get_name(name), ".cor"),
	O_WRONLY | O_CREAT | O_TRUNC, 0777);
	ft_print_header(data, fd);
	ft_print_ins(data, fd);
	ft_putstr("Writing output program to ");
	ft_putstr(ft_strcat(ft_get_name(name), ".cor"));
	ft_putchar('\n');
}
