/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_annexe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:45:31 by rfernand          #+#    #+#             */
/*   Updated: 2017/02/08 16:39:59 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "struct.h"
#include "get_next_line.h"
#include "ft_printf.h"
#include <unistd.h>

char			*get_name(int fd)
{
	char *str;

	lseek(fd, 1, SEEK_SET);
	get_next_line(fd, &str);
	if (!str)
	{
		str = (char *)malloc(1 * sizeof(char));
		str[0] = '\0';
		return (str);
	}
	return (ft_strdup(&str[3]));
}

char			*get_comment(int fd)
{
	char	*str;
	int		i;

	str = (char *)malloc(2 * sizeof(char));
	ft_bzero(str, 2);
	read(fd, str, 1);
	i = 1;
	while (!str[0])
	{
		read(fd, str, 1);
		i++;
		if (i > 107)
			return (NULL);
	}
	if (i != 107)
		read(fd, str, 1);
	get_next_line(fd, &str);
	if (str)
		return (ft_strdup(str));
	return (str);
}

int				nb_arg(unsigned char *str)
{
	if (str[0] == 9 || str[0] == 12 || str[0] == 15 || str[0] == 16)
		return (1);
	if (str[0] == 1 || str[1] == 0x54 || str[1] == 0xd0 || str[1] == 0x70)
		return (3);
	if (str[1] == 0x68 || str[1] == 0x90 || str[1] == 0x78 || str[1] == 0xf4 ||
			((str[1] == 0xa4 || str[1] == 0xe4) && (str[0] == 10 ||
				str[0] == 14)))
		return (5);
	if (str[0] == 3)
		return (2);
	if (((str[1] == 0x58 || str[1] == 0x64 || str[1] == 0x94) && (str[0] == 11
				|| str[0] == 10)) || str[1] == 0x74 || str[1] == 0xd4)
		return (4);
	if ((str[1] == 0x64 || str[1] == 0x94) && str[0] >= 6 && str[0] <= 8)
		return (6);
	if ((str[0] >= 6 && str[0] <= 8) && (str[1] == 0xb4 || str[1] == 0xe4))
		return (7);
	if (str[1] == 0xa4 && str[0] >= 6 && str[0] <= 8)
		return (9);
	return (-1);
}

unsigned char	*resize(unsigned char *instruct, unsigned char *str,
		int nb, int i)
{
	unsigned char *tmp;

	tmp = (unsigned char *)malloc((i + 1) * sizeof(unsigned char));
	ft_bzero(tmp, i + 1);
	ft_memcpy(tmp, instruct, i);
	free(instruct);
	instruct = (unsigned char *)malloc((nb + i + 1) * sizeof(unsigned char));
	ft_memcpy(instruct, tmp, i);
	ft_memcpy(instruct + i, str, nb);
	free(tmp);
	return (instruct);
}

unsigned char	*save_instruct(t_joueur **players, unsigned char *instruct,
		int i, int num)
{
	unsigned char *str;

	str = (unsigned char *)malloc(1024 * sizeof(unsigned char));
	ft_bzero(str, 1024);
	ft_memcpy(str, instruct, i);
	free(instruct);
	players[num]->weight = i;
	return (str);
}
