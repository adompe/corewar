/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:34:12 by rfernand          #+#    #+#             */
/*   Updated: 2016/12/15 13:19:45 by qmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "struct.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"

unsigned char	*get_instruct(t_joueur **players, int fd, int num)
{
	int				i;
	int				n;
	unsigned char	*str;
	unsigned char	*instruct;

	instruct = (unsigned char *)malloc(1 * sizeof(unsigned char));
	instruct[0] = '\0';
	str = (unsigned char *)malloc(8 * sizeof(unsigned char));
	ft_bzero(str, 8);
	i = 0;
	str = skip_zero(fd, str);
	while (str[0])
	{
		instruct = resize(instruct, str, 2, i);
		i += 2;
		n = nb_arg(str);
		read(fd, str, n);
		instruct = resize(instruct, str, n, i);
		i += n;
		ft_bzero(str, 8);
		read(fd, str, 2);
	}
	if (i > CHAMP_MAX_SIZE || i <= 1)
		return (NULL);
	return (save_instruct(players, instruct, i, num));
}

int				flag_dump(char **argv, int argc, int *dumb)
{
	if (!(ft_strcmp(argv[1], "-dump")))
	{
		if (argc == 2)
			return (0);
		if (argc == 3)
			return (0);
		*dumb = ft_atoi(argv[2]);
		return (3);
	}
	return (1);
}

int				count_param(char **argv, int argc)
{
	int i;
	int n;

	i = 1;
	n = 1;
	if (!(ft_strcmp(argv[1], "-dump")))
	{
		i += 2;
		n = 3;
	}
	while (n < argc)
	{
		if (!(ft_strcmp(argv[n], "-n")))
		{
			i += 2;
			n += 2;
		}
		n++;
	}
	if (i >= argc)
		return (argc - 1);
	return (i);
}

void			check_num_available(t_joueur **players, int n)
{
	int i;
	int u;

	i = 0;
	u = n;
	if (n == 0)
	{
		players[0]->num_joueur = 1;
		return ;
	}
	while (i < n)
	{
		if (players[i]->num_joueur == n)
		{
			n++;
			i = 0;
		}
		i++;
	}
	players[u]->num_joueur = n;
}

int				main(int argc, char **argv)
{
	unsigned char	*memory;
	t_joueur		**players;
	int				in[2];
	int				dumb;

	in[1] = 0;
	if (argc == 1)
		return (0);
	if (!(in[0] = flag_dump(argv, argc, &dumb)))
		return (ft_printf("la valeur de dump n'est pas presente ou le fichier" \
		" .cor ne l'est pas\n"));
	players = (t_joueur **)malloc(argc * sizeof(t_joueur *));
	memory = get_players(players, argv, in, argc);
	if (error(memory))
		return (0);
	introduce_players(players, argc - count_param(argv, argc));
	memory = parsing(players, memory, argc - count_param(argv, argc), dumb);
	if (memory)
		who_won(players, argc - count_param(argv, argc));
	return (0);
}
