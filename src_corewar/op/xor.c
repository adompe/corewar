/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:30:32 by qmoreaux          #+#    #+#             */
/*   Updated: 2016/12/14 20:34:24 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ope.h"

int	get_value_xor_1(t_env *env, int arg, unsigned char codage, int num_player)
{
	int value;

	value = 0;
	if (is_register(arg, codage, 0))
		value = reg_to_int(env->champion[num_player]->\
			instance[env->num_instance]->reg[arg]);
	else if (is_indirect(arg, codage, 0))
		value = memory_4_bytes_to_int(env, arg, num_player, 1);
	else if (is_direct(arg, codage, 0))
		value = arg;
	return (value);
}

int	get_value_xor_2(t_env *env, int arg, unsigned char codage, int num_player)
{
	int value;

	value = 0;
	if (is_register(arg, codage, 1))
		value = reg_to_int(env->champion[num_player]->\
			instance[env->num_instance]->reg[arg]);
	else if (is_indirect(arg, codage, 1))
		value = memory_4_bytes_to_int(env, arg, num_player, 1);
	else if (is_direct(arg, codage, 1))
		value = arg;
	return (value);
}

int	op_xor(t_env *env, int num_player, unsigned int op_args[3], \
	unsigned char codage)
{
	int	value;
	int	value2;
	int	i;

	i = REG_SIZE;
	if (!(is_register(op_args[0], codage, 0) || is_indirect(op_args[0], \
	codage, 0) || is_direct(op_args[0], codage, 0)) && \
	!(is_register(op_args[1], codage, 1) && is_indirect(op_args[1], \
	codage, 1) && is_direct(op_args[1], codage, 1)))
		return (-1);
	value = get_value_xor_1(env, op_args[0], codage, num_player);
	value2 = get_value_xor_2(env, op_args[1], codage, num_player);
	if (!is_register(op_args[2], codage, 2))
		return (-1);
	ft_memcpy(env->champion[num_player]->instance[env->num_instance]->\
		reg[op_args[2]], int_to_reg(value ^ value2), i * 2);
	env->champion[num_player]->instance[env->num_instance]->carry = 0;
	if (reg_to_int(env->champion[num_player]->instance[env->\
		num_instance]->reg[op_args[2]]) == 0)
		env->champion[num_player]->instance[env->num_instance]->carry = 1;
	return (0);
}
