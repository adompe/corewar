/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 18:09:01 by qmoreaux          #+#    #+#             */
/*   Updated: 2016/12/10 22:22:09 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ope.h"

int		op_aff(t_env *env, int num_player, unsigned int op_args[3], \
	unsigned char codage)
{
	int	value;

	if (!is_register(op_args[0], codage, 0))
		return (-1);
	value = reg_to_int(env->champion[num_player]->
		instance[env->num_instance]->reg[op_args[0]]);
	ft_printf("Aff : %c\n", value % 256);
	return (0);
}
