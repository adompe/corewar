/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:11:08 by qmoreaux          #+#    #+#             */
/*   Updated: 2016/12/10 20:34:45 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ope.h"

int	op_zjmp(t_env *env, int num_player, unsigned int op_args[3], \
	unsigned char codage)
{
	if (env->champion[num_player]->instance[env->num_instance]->carry)
		env->champion[num_player]->instance[env->num_instance]->\
		program_control = position_2_bytes(env, op_args[0], num_player, 1);
	return (0);
	codage = 0;
}
