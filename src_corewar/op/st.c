/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:21:08 by qmoreaux          #+#    #+#             */
/*   Updated: 2016/12/14 21:50:17 by qmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ope.h"

void	op_st_copy(t_env *env, unsigned char *tmp, int value, int num_player)
{
	int	i;

	i = 0;
	while (i < REG_SIZE)
	{
		ft_memcpy(&env->memory[(position_2_bytes(env, value, \
		num_player, 1) + i) % MEM_SIZE], tmp + i, 1);
		i++;
	}
}

int		op_st(t_env *env, int num_player, unsigned int op_args[3], \
	unsigned char codage)
{
	unsigned int	value;
	unsigned char	*tmp;

	tmp = (unsigned char*)malloc(sizeof(unsigned char) * REG_SIZE);
	if (is_register(op_args[0], codage, 0))
		value = reg_to_int(env->champion[num_player]->\
			instance[env->num_instance]->reg[op_args[0]]);
	else
		return (-1);
	if (is_register(op_args[1], codage, 1))
		ft_memcpy(env->champion[num_player]->instance[env->num_instance]->\
		reg[op_args[1]], int_to_reg(value), REG_SIZE * 2);
	else if (is_indirect(op_args[1], codage, 1))
	{
		tmp = int_to_ind(value);
		op_st_copy(env, tmp, op_args[1], num_player);
	}
	else
		return (-1);
	return (0);
}
