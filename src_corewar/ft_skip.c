/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:12:03 by rfernand          #+#    #+#             */
/*   Updated: 2017/02/10 17:15:39 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "struct.h"
#include "ft_printf.h"

int				nb_skip(unsigned char op, unsigned char c)
{
	int value;
	int *tab;
	int i;

	i = 2;
	value = c;
	tab = (int *)malloc(4 * sizeof(int));
	tab[0] = 0;
	tab[1] = 1;
	tab[2] = 4;
	tab[3] = 2;
	if (op == 10 || op == 11 || op == 14)
		tab[2] = 2;
	if (op != 16)
		i += tab[(value % 64) / 16];
	if (op != 2 && op != 3 && op != 13 && op != 16)
		i += tab[((value % 64) % 16) / 4];
	i += tab[value / 64];
	free(tab);
	return (i);
}

void			ft_cpymem(unsigned char *dst, unsigned char *src, int pos)
{
	int i;

	i = 0;
	while (i < 12)
	{
		dst[i] = src[(i + pos) % MEM_SIZE];
		i++;
	}
}

void			introduce_players(t_joueur **players, int nbp)
{
	int i;

	i = 0;
	ft_printf("Introducing contestants...\n");
	while (i < nbp)
	{
		ft_printf("* Player %i, weighing %i bytes, \"%s\" (\"%s\") !\n",
				players[i]->num_joueur, players[i]->weight, players[i]->name,
				players[i]->comment);
		i++;
	}
}

void			who_won(t_joueur **players, int nbp)
{
	int i;
	int n;

	n = 0;
	i = players[0]->last_alive;
	if (nbp == 1)
		ft_printf("contestant %i, \"%s\", has won !\n",
				players[n]->num_joueur, players[0]->name);
	else
	{
		while (players[n]->num_joueur != i)
			n++;
		ft_printf("contestant %i, \"%s\", has won !\n", i, players[n]->name);
		nbp = 0;
	}
}

unsigned char	*skip_zero(int fd, unsigned char *str)
{
	while (!str[0])
		read(fd, str, 1);
	read(fd, str + 1, 1);
	return (str);
}
