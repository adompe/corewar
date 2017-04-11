/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 14:00:23 by qmoreaux          #+#    #+#             */
/*   Updated: 2016/12/14 21:56:07 by qmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"
#include "ft_printf.h"
#include <limits.h>

int		direct_to_four_bytes(int value)
{
	if (value >= 0 && value <= SHRT_MAX)
		return (value);
	else
		return (value + (UINT_MAX - USHRT_MAX));
}

int		position_2_bytes(t_env *env, unsigned int value, \
	int num_player, int modulo)
{
	if (modulo)
	{
		if (value < SHRT_MAX)
			value = (env->champion[num_player]->instance[env->\
			num_instance]->program_control + (value % IDX_MOD)) % MEM_SIZE;
		else
		{
			while (value <= USHRT_MAX - IDX_MOD + 1 && value > SHRT_MAX)
				value += IDX_MOD;
			value = (env->champion[num_player]->instance[env->\
			num_instance]->program_control + value) % MEM_SIZE;
		}
	}
	else
		value = (env->champion[num_player]->instance[env->\
		num_instance]->program_control + value) % MEM_SIZE;
	return (value);
}

int		position_4_bytes(t_env *env, \
	unsigned int value, int num_player, int modulo)
{
	if (modulo)
	{
		if (value < INT_MAX)
			value = (env->champion[num_player]->instance[env->\
			num_instance]->program_control + (value % IDX_MOD)) % MEM_SIZE;
		else
		{
			while (value <= UINT_MAX - IDX_MOD + 1 && value > INT_MAX)
				value += IDX_MOD;
			value = env->champion[num_player]->instance[env->\
			num_instance]->program_control + (value % MEM_SIZE);
		}
	}
	else
		value = (env->champion[num_player]->instance[env->\
		num_instance]->program_control + value) % MEM_SIZE;
	return (value);
}

void	get_tmp_from_memory(t_env *env, char *tmp2, unsigned int value, int i)
{
	int	tmp3;
	int	tmp4;

	tmp3 = env->memory[(value + i) % MEM_SIZE] / 16;
	tmp4 = env->memory[(value + i) % MEM_SIZE] % 16;
	if (tmp3 > 9)
		tmp2[0] = tmp3 + 'A' - 10;
	else
		tmp2[0] = tmp3 + '0';
	if (tmp4 > 9)
		tmp2[1] = tmp4 + 'A' - 10;
	else
		tmp2[1] = tmp4 + '0';
}
