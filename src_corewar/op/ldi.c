/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 18:09:01 by qmoreaux          #+#    #+#             */
/*   Updated: 2016/12/14 20:33:54 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ope.h"
#include <limits.h>

unsigned int	get_value_ldi(t_env *env, int num_player, \
	unsigned int op_args[3], unsigned char codage)
{
	int	value;

	value = 0;
	if (is_register(op_args[0], codage, 0))
		value = reg_to_int(env->champion[num_player]->\
		instance[env->num_instance]->reg[op_args[0]]);
	else if (is_indirect(op_args[0], codage, 0))
		value = memory_4_bytes_to_int(env, op_args[0], num_player, 1);
	else if (is_direct(op_args[0], codage, 0))
		value = direct_to_four_bytes(op_args[0]);
	else
		return (-1);
	if (is_register(op_args[1], codage, 1))
		value += reg_to_int(env->champion[num_player]->\
		instance[env->num_instance]->reg[op_args[1]]);
	else if (is_direct(op_args[1], codage, 1))
		value += direct_to_four_bytes(op_args[1]);
	else
		return (-1);
	return (value);
}

int				test_ldi(t_env *env, unsigned int value, int num_player, \
	int modulo)
{
	int		i;
	char	*tmp;
	char	*tmp2;
	int		j;

	i = 0;
	j = REG_SIZE;
	value = position_4_bytes(env, value, num_player, modulo);
	tmp = (char *)malloc(sizeof(char) * j * 2);
	ft_memset(tmp, '0', j * 2);
	tmp2 = (char*)malloc(sizeof(char) * 2);
	while (i < j)
	{
		get_tmp_from_memory(env, tmp2, value, i);
		ft_memcpy(&tmp[2 * i], tmp2, 2);
		i++;
	}
	return (reg_to_int(tmp));
}

int				op_ldi(t_env *env, int num_player, unsigned int op_args[3], \
	unsigned char codage)
{
	unsigned int	value;
	int				i;

	i = REG_SIZE;
	if (!(!is_register(op_args[0], codage, 0) && !is_indirect(op_args[0], \
	codage, 0) && !is_direct(op_args[0], codage, 0) && \
	!is_register(op_args[1], codage, 1) && !is_direct(op_args[1], codage, 1)))
		value = get_value_ldi(env, num_player, op_args, codage);
	else
		return (-1);
	if (!is_register(op_args[2], codage, 2))
		return (-1);
	value = test_ldi(env, value, num_player, 1);
	ft_memcpy(env->champion[num_player]->instance[env->num_instance]->\
	reg[op_args[2]], int_to_reg(value), i * 2);
	return (0);
}
