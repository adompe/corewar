/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 18:07:04 by rfernand          #+#    #+#             */
/*   Updated: 2016/12/15 13:21:05 by qmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "ft_printf.h"
#include <stdlib.h>

unsigned int	*get_op_arg_2(unsigned char *str, unsigned int *params)
{
	if (str[0] >= 6 && str[0] <= 8 && str[1] == 0xe4)
		recup_241(str + 2, params);
	if (str[1] == 0xd4 || ((str[0] == 10 || str[0] == 14) && str[1] == 0x94))
		recup_211(str + 2, params);
	if (str[1] == 0xb4)
		recup_421(str + 1, params);
	if (str[0] >= 6 && str[0] <= 8 && str[1] == 0xa4)
		recup_441(str + 1, params);
	if (str[0] >= 6 && str[0] <= 8 && str[1] == 0x64)
		recup_141(str + 2, params);
	if (str[0] >= 6 && str[0] <= 8 && str[1] == 0x94)
		recup_411(str + 2, params);
	if (str[0] == 9 || str[0] == 12 || str[0] == 15)
		params[0] = 256 * str[1] + str[2];
	if (str[0] == 16)
		params[0] = str[2];
	if (str[0] == 1)
		params[0] = CUBE * str[1] + CARRE * str[2] + 256 * str[3] + str[4];
	return (params);
}

unsigned int	*get_op_arg(unsigned char *str)
{
	unsigned int	*params;

	params = (unsigned int *)malloc(4 * sizeof(unsigned int));
	if (str[1] == 0x54)
		recup_111(str + 2, params);
	if (str[0] == 11 && (str[1] == 0x68 || str[1] == 0x78))
		recup_122(str + 2, params);
	if (str[1] == 0x74 || ((str[0] == 11 || str[0] == 10 || str[0] == 11)
				&& str[1] == 0x64))
		recup_121(str + 2, params);
	if (str[1] == 0x58)
		recup_112(str + 2, params);
	if (str[1] == 0x90)
		recup_41(str + 2, params);
	if (str[1] == 0xd0)
		recup_21(str + 2, params);
	if (str[1] == 0x50)
		recup_11(str + 2, params);
	if (str[1] == 0x70)
		recup_12(str + 2, params);
	if ((str[0] >= 6 && str[0] <= 8 && str[1] == 0xf4) || ((str[0] == 10 ||
					str[0] == 14) && (str[1] == 0xa4 || str[1] == 0xe4)))
		recup_221(str + 2, params);
	get_op_arg_2(str, params);
	return (params);
}

void			split_moove(t_joueur **players, int *inu, unsigned char *memory,
		int (**execute_op)(t_env *env, int num_player, unsigned int op_args[4],
			unsigned char codage))
{
	int last_op;

	last_op = 0;
	if (players[0]->instance[inu[1]]->cycle && ALIVE)
		players[0]->instance[inu[1]]->cycle--;
	if (!players[0]->instance[inu[1]]->cycle && ALIVE)
	{
		last_op = SAVEOP[0];
		ft_cpymem(SAVEOP + 1, memory, POS + 1);
		if (last_op <= 16 && last_op >= 1)
			inu[2] = execute_op[SAVEOP[0]](create_env(players, memory,
				inu[3], inu[1]), 0, get_op_arg(SAVEOP),
					get_codage(SAVEOP));
		if (last_op < 1 || last_op > 16)
			POS++;
		else if (inu[2] == -1)
			POS += nb_skip(SAVEOP[0], memory[(POS + 1) % MEM_SIZE]);
		else if (last_op != 9 || !players[0]->instance[inu[1]]->carry)
			POS += (nb_arg(SAVEOP) + 2);
		inu[2] = 0;
		if (last_op == 12 || last_op == 15)
			players[0]->nb_instance++;
	}
	POS = POS >= 4096 ? POS % 4096 : POS;
}

void			moove_parseur(t_joueur **players, unsigned char *memory,
		int nbp, int (**execute_op)(t_env *env, int num_player,
			unsigned int op_args[4], unsigned char codage))
{
	int inu[4];

	inu[0] = nbp - 1;
	inu[1] = players[0]->nb_instance - 1;
	inu[2] = 0;
	inu[3] = nbp;
	while (inu[1] >= 0)
	{
		check_instruct(players, memory, nbp, inu[1]);
		split_moove(players, inu, memory, execute_op);
		inu[1]--;
	}
}

int				get_nb_cycle(char c)
{
	if (c == 1 || c == 4 | c == 5 || c == 13)
		return (10);
	if (c == 2 || c == 3)
		return (5);
	if (c == 6 || c == 7 || c == 8)
		return (6);
	if (c == 9)
		return (20);
	if (c == 10 || c == 11)
		return (25);
	if (c == 12)
		return (800);
	if (c == 14)
		return (50);
	if (c == 15)
		return (1000);
	if (c == 16)
		return (2);
	return (0);
}
