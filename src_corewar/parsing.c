/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 12:25:39 by rfernand          #+#    #+#             */
/*   Updated: 2016/12/15 13:20:55 by qmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "ope.h"
#include "stdlib.h"

void			check_instruct(t_joueur **players, unsigned char *memory,
		int nbp, int n)
{
	int i;

	i = nbp;
	if (players[0]->instance[n]->cycle == -1)
		players[0]->instance[n]->cycle = 0;
	if (!players[0]->instance[n]->cycle)
	{
		players[0]->instance[n]->save_op[0] = memory[POS2];
		players[0]->instance[n]->cycle += get_nb_cycle(memory[POS2]);
	}
	n++;
}

void			reduc_cycle_to_check(t_state *state)
{
	if (state->nbr_live >= NBR_LIVE)
	{
		state->cycle_to_check -= CYCLE_DELTA;
		state->nb_check = 0;
	}
	else
		state->nb_check++;
	if (state->nb_check == MAX_CHECKS)
	{
		state->cycle_to_check -= CYCLE_DELTA;
		state->nb_check = 0;
	}
	if (state->cycle_to_check < 0)
		state->cycle_to_check = 0;
	state->nbr_live = 0;
}

void			init_execute_op(int (**execute_op)(t_env *env, int num_player,
			unsigned int op_args[4], unsigned char codage))
{
	execute_op[1] = &op_live;
	execute_op[2] = &op_ld;
	execute_op[3] = &op_st;
	execute_op[4] = &op_add;
	execute_op[5] = &op_sub;
	execute_op[6] = &op_and;
	execute_op[7] = &op_or;
	execute_op[8] = &op_xor;
	execute_op[9] = &op_zjmp;
	execute_op[10] = &op_ldi;
	execute_op[11] = &op_sti;
	execute_op[12] = &op_fork;
	execute_op[13] = &op_lld;
	execute_op[14] = &op_lldi;
	execute_op[15] = &op_lfork;
	execute_op[16] = &op_aff;
}

t_state			*init_state(int *cycle, int *totalcycle, t_joueur **players,
		int nbp)
{
	t_state *state;

	*cycle = 0;
	*totalcycle = 0;
	init_program_control(players, nbp);
	state = (t_state *)malloc(sizeof(t_state));
	state->cycle_to_check = CYCLE_TO_DIE;
	state->nb_check = 0;
	state->nbr_live = 0;
	return (state);
}

unsigned char	*parsing(t_joueur **players, unsigned char *memory, int nbp,
		int dumb)
{
	int		cycle;
	int		totalcycle;
	t_state	*state;
	int		(*execute_op[17])(t_env *env, int num_player, ARGCODE);

	init_execute_op(execute_op);
	state = init_state(&cycle, &totalcycle, players, nbp);
	while (state->cycle_to_check)
	{
		cycle++;
		totalcycle++;
		players[0]->cycle = totalcycle;
		moove_parseur(players, memory, nbp, execute_op);
		if (totalcycle == dumb)
			return (print_memory(memory));
		if (cycle == state->cycle_to_check)
		{
			if (check_live(players, state, nbp))
				return (memory);
			reduc_cycle_to_check(state);
			cycle = 0;
		}
	}
	return (memory);
}
