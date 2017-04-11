/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adompe <adompe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:47:53 by adompe            #+#    #+#             */
/*   Updated: 2016/11/08 16:47:57 by adompe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_check_ins(t_asm *data)
{
	t_list	*tmp;
	t_ins	*tmp_ins;

	tmp = data->ins;
	while (tmp)
	{
		tmp_ins = tmp->content;
		if (tmp_ins->opcode)
		{
			tmp_ins->two_bytes = tmp_ins->op_code.two_bytes;
			ft_check_param(tmp_ins, tmp_ins->op_code);
		}
		tmp = tmp->next;
	}
}
