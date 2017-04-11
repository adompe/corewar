/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:10:34 by qmoreaux          #+#    #+#             */
/*   Updated: 2016/12/15 14:45:58 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ope.h"

int		op_live(t_env *env, int num_player, unsigned int op_args[3], \
	unsigned char codage)
{
	int	nb;

	env->champion[num_player]->instance[env->num_instance]->last_op_live = \
	env->champion[0]->cycle;
	if ((nb = is_valid_player(op_args[0], env)) != -1)
	{
		env->champion[nb]->last_live = env->champion[0]->cycle;
		env->champion[nb]->nb_live_total++;
		env->champion[num_player]->last_alive = env->champion[nb]->num_joueur;
		ft_printf("Un processus dit que le champion %d(%s) est en vie\n", \
		env->champion[nb]->num_joueur, env->champion[nb]->name);
	}
	env->champion[0]->nb_live_current_cycle++;
	return (0);
	codage = 0;
	num_player = 0;
}
