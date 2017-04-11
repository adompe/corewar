/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 18:09:01 by qmoreaux          #+#    #+#             */
/*   Updated: 2016/12/14 18:03:32 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ope.h"

int		get_value_sti(t_env *env, int num_player, unsigned int op_args[3], \
	unsigned char codage)
{
	int	value;

	value = 0;
	if (!is_register(op_args[0], codage, 0))
		return (-1);
	if (is_register(op_args[1], codage, 1))
		value = reg_to_int(env->champion[num_player]->\
			instance[env->num_instance]->reg[op_args[1]]);
	else if (is_indirect(op_args[1], codage, 1))
		value = memory_4_bytes_to_int(env, op_args[1], num_player, 1);
	else if (is_direct(op_args[1], codage, 1))
		value = direct_to_four_bytes(op_args[1]);
	if (is_register(op_args[2], codage, 2))
		value += reg_to_int(env->champion[num_player]->\
			instance[env->num_instance]->reg[op_args[2]]);
	else if (is_direct(op_args[2], codage, 2))
		value += direct_to_four_bytes(op_args[2]);
	else
		return (-1);
	return (value);
}

int		op_sti(t_env *env, int num_player, unsigned int op_args[3], \
	unsigned char codage)
{
	int				i;
	int				value;
	unsigned char	*tmp;

	i = 0;
	if (is_register(op_args[0], codage, 0) && (is_register(op_args[1], \
	codage, 1) || is_indirect(op_args[1], codage, 1) || \
	is_direct(op_args[1], codage, 1)) && (is_register(op_args[2], \
	codage, 2) || is_direct(op_args[2], codage, 2)))
		value = get_value_sti(env, num_player, op_args, codage);
	else
		return (-1);
	tmp = (unsigned char*)malloc(sizeof(unsigned char) * REG_SIZE);
	while (i < REG_SIZE)
	{
		tmp = int_to_ind(reg_to_int(env->champion[num_player]->\
		instance[env->num_instance]->reg[op_args[0]]));
		ft_memcpy(&env->memory[(position_4_bytes(env, value, num_player, 1) \
		+ i) % MEM_SIZE], tmp + i, 1);
		i++;
	}
	return (0);
}
