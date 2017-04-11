/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adompe <adompe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:17:34 by adompe            #+#    #+#             */
/*   Updated: 2016/11/08 16:17:37 by adompe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_check_param_value(t_ins *ins, t_op opcode, t_param *param, int i)
{
	if (param->type == 3 && !(opcode.param[i] & 4))
		ft_error("Error: Bad argument\n");
	if (!(param->type & opcode.param[i]))
		ft_error("Error: Bad argument\n");
	if (opcode.coding_byte)
		ins->coding_byte += (param->type << (6 - (2 * i)));
	if (param->type == T_REG)
		ins->size++;
	else if (param->type == 3)
		ins->size += 2;
	else if (param->type == T_DIR)
	{
		if (opcode.two_bytes)
			ins->size += 2;
		else
			ins->size += 4;
	}
}

void	ft_check_param(t_ins *ins, t_op opcode)
{
	t_list	*tmp;
	t_param	*tmp_param;
	int		i;

	i = 0;
	tmp = ins->param;
	if (opcode.coding_byte)
		ins->size++;
	while (tmp)
	{
		tmp_param = tmp->content;
		ft_check_param_value(ins, opcode, tmp_param, i);
		i++;
		tmp = tmp->next;
	}
	if (i != opcode.nb_param)
		ft_error("Error: Bad argument\n");
}
