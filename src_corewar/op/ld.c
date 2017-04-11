/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:12:15 by qmoreaux          #+#    #+#             */
/*   Updated: 2016/12/14 20:33:49 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ope.h"

int		op_ld(t_env *env, int num_player, unsigned int op_args[3], \
	unsigned char codage)
{
	unsigned int	value;
	int				i;

	i = REG_SIZE;
	if (is_direct(op_args[0], codage, 0))
		value = op_args[0];
	else if (is_indirect(op_args[0], codage, 0))
		value = memory_4_bytes_to_int(env, op_args[0], num_player, 1);
	else
		return (-1);
	if (!is_register(op_args[1], codage, 1))
		return (-1);
	ft_memcpy(env->champion[num_player]->instance[env->num_instance]->\
	reg[op_args[1]], int_to_reg(value), i * 2);
	env->champion[num_player]->instance[env->num_instance]->carry = 0;
	if (reg_to_int(env->champion[num_player]->instance[env->\
	num_instance]->reg[op_args[1]]) == 0)
		env->champion[num_player]->instance[env->num_instance]->carry = 1;
	return (0);
}
