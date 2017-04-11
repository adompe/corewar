/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 18:02:19 by rfernand          #+#    #+#             */
/*   Updated: 2016/12/15 13:21:00 by qmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "ft_printf.h"
#include <stdlib.h>

int		check_alive(t_joueur **players, int nbp)
{
	int i;
	int n;
	int	u;

	i = 1;
	n = nbp;
	u = 0;
	while (u < players[0]->nb_instance)
	{
		if (players[0]->instance[u]->is_alive != 0)
			i = 0;
		u++;
	}
	return (i);
}

int		check_live(t_joueur **players, t_state *state, int nbp)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (n < players[0]->nb_instance)
	{
		if (!players[0]->instance[n]->last_op_live)
			players[0]->instance[n]->is_alive = 0;
		else
			players[0]->instance[n]->last_op_live = 0;
		n++;
	}
	while (i < nbp)
	{
		state->nbr_live += players[i]->nb_live_current_cycle;
		players[i]->nb_live_current_cycle = 0;
		i++;
	}
	return (check_alive(players, nbp));
}

void	init_program_control(t_joueur **players, int nbp)
{
	int i;

	i = 0;
	while (i < players[0]->nb_instance)
	{
		players[0]->instance[i]->program_control = ((MEM_SIZE / nbp) * i);
		i++;
	}
}

t_env	*create_env(t_joueur **players, unsigned char *memory, int nbp, int n)
{
	t_env *envi;

	envi = (t_env *)malloc(sizeof(t_env));
	envi->nb_player = nbp;
	envi->memory = memory;
	envi->champion = players;
	envi->num_instance = n;
	return (envi);
}

int		get_codage(unsigned char *str)
{
	if (str[0] == 1 || str[0] == 9 || str[0] == 12 || str[0] == 15)
		return (0);
	else
		return (str[1]);
}
