/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:11:08 by qmoreaux          #+#    #+#             */
/*   Updated: 2016/12/14 21:51:35 by qmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ope.h"

void	op_fork_copy(t_env *env, int num_player, int dest, int value)
{
	env->champion[num_player]->instance[dest]->carry = \
	env->champion[num_player]->instance[env->num_instance]->carry;
	env->champion[num_player]->instance[dest]->program_control = \
	position_2_bytes(env, value, num_player, 1);
	env->champion[num_player]->instance[dest]->cycle = -1;
	env->champion[num_player]->instance[dest]->last_op_live = \
	env->champion[num_player]->instance[env->num_instance]->last_op_live;
	env->champion[num_player]->instance[dest]->is_alive = 1;
	env->champion[num_player]->instance[dest]->save_op = (unsigned char *)\
	malloc(12 * sizeof(unsigned char));
}

int		op_fork(t_env *env, int num_player, unsigned int op_args[3], \
	unsigned char codage)
{
	int	num_instance;
	int	i;
	int	j;

	i = 0;
	j = REG_SIZE;
	num_instance = env->champion[num_player]->nb_instance;
	env->champion[num_player]->instance = (t_proce**)realloc(env->\
	champion[num_player]->instance, sizeof(t_proce*) * (num_instance + 1));
	env->champion[num_player]->instance[num_instance] = \
	(t_proce*)malloc(sizeof(t_proce));
	env->champion[num_player]->instance[num_instance]->reg = \
	(char**)malloc(sizeof(char*) * (REG_NUMBER + 1));
	while (i < REG_NUMBER + 1)
	{
		env->champion[num_player]->instance[num_instance]->reg[i] = \
		(char*)malloc(sizeof(char) * j * 2);
		ft_memcpy(env->champion[num_player]->instance[num_instance]->reg[i], \
		env->champion[num_player]->instance[env->num_instance]->reg[i], j * 2);
		i++;
	}
	op_fork_copy(env, num_player, num_instance, op_args[0]);
	return (0);
	codage = 0;
}
