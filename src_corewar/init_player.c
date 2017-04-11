/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:51:18 by rfernand          #+#    #+#             */
/*   Updated: 2016/12/15 13:20:48 by qmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "libft.h"
#include "ft_printf.h"
#include "convert.h"
#include <stdlib.h>
#include <fcntl.h>

int				error(unsigned char *str)
{
	if (!ft_strcmp("NUM/FILE", (char *)str))
		return (ft_printf("Le numero de jouer est deja utilise, n'est pas "\
		"present ou le fichier .cor est absent\n"));
	if (!ft_strcmp("FILENAME", (char *)str))
		return (ft_printf("un des fichier n'est pas un fichier valide\n"));
	if (!ft_strcmp("SIZE", (char *)str))
		return (ft_printf("La taille d'un des fichier est trop grande ou "\
		"le code est vide\n"));
	if (!ft_strcmp("INVALIDFILE", (char *)str))
		return (ft_printf("Fichier invalide\n"));
	if (!ft_strcmp("EMPTYFILE", (char *)str))
		return (ft_printf("Un des fichier est vide ou le header n'est pas" \
		" valide\n"));
	if (!ft_strcmp("NBP", (char *)str))
		return (ft_printf("Il y a trop de joueurs\n"));
	return (0);
}

void			init_instance(t_joueur **players, int *in)
{
	players[in[1]] = (t_joueur *)malloc(sizeof(t_joueur));
	players[0]->nb_instance = in[1] + 1;
	players[0]->instance = (t_proce **)realloc(players[0]->instance,
			players[0]->nb_instance * sizeof(t_proce *));
	players[0]->instance[in[1]] = (t_proce *)malloc(sizeof(t_proce));
}

unsigned char	*get_players(t_joueur **players, char **argv, int *in, int argc)
{
	int				fd;
	unsigned char	*str;
	unsigned char	*memory;

	memory = start_recup_players(&fd);
	while (in[0] < argc)
	{
		if (in[1] > 3)
			return ((unsigned char *)"NBP\0");
		init_instance(players, in);
		if (!flag_n(players, in, argv, argc))
			return ((unsigned char *)"NUM/FILE\0");
		if (strncmp(".cor", argv[in[0]] + ft_strlen(argv[in[0]]) - 4, 3))
			return ((unsigned char *)"FILENAME\0");
		if ((fd = open(argv[in[0]], O_RDONLY)) == -1)
			return ((unsigned char *)"INVALIDFILE\0");
		if (!init_player(players, in[1], fd))
			return ((unsigned char *)"EMPTYFILE\0");
		if ((str = get_instruct(players, fd, in[1])) == NULL)
			return ((unsigned char *)"SIZE\0");
		ft_memcpy(memory + ((MEM_SIZE / (argc - count_param(argv, argc))) *
					in[1]), str, MEM_SIZE / 4);
		in = reset_recup(in, &fd, str);
	}
	return (memory);
}

int				init_player(t_joueur **players, int n, int fd)
{
	int u;

	u = 0;
	if (!start_init(players, n, fd))
		return (0);
	players[0]->instance[n]->reg = (char**)malloc(sizeof(char*) *
			REG_NUMBER + 1);
	ft_bzero(players[0]->instance[n]->reg, REG_NUMBER);
	while (u <= REG_NUMBER + 1)
	{
		players[0]->instance[n]->reg[u] = (char*)malloc(sizeof(char) * 2
				* REG_SIZE);
		ft_memset(players[0]->instance[n]->reg[u], '0', 2 * REG_SIZE);
		u++;
	}
	ft_memcpy(players[0]->instance[n]->reg[1],
			int_to_reg(-players[n]->num_joueur), REG_SIZE * 2);
	return (1);
}
