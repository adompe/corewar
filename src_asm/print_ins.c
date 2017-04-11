/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adompe <adompe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:25:24 by adompe            #+#    #+#             */
/*   Updated: 2016/11/09 15:25:27 by adompe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_print_param(t_ins *ins, int fd)
{
	t_list	*tmp;
	t_param	*tmp_param;

	tmp = ins->param;
	while (tmp)
	{
		tmp_param = tmp->content;
		if (tmp_param->type == T_REG)
			ft_print_uint_hex(fd, tmp_param->value, 1);
		else if (tmp_param->type == 3)
			ft_print_uint_hex(fd, tmp_param->value, 2);
		else if (tmp_param->type == T_DIR && ins->two_bytes)
			ft_print_uint_hex(fd, tmp_param->value, 2);
		else if (tmp_param->type == T_DIR && ins->two_bytes == FALSE)
			ft_print_uint_hex(fd, tmp_param->value, 4);
		tmp = tmp->next;
	}
	return (0);
}

void	ft_print_ins(t_asm *data, int fd)
{
	t_list	*tmp;
	t_ins	*tmp_ins;

	tmp = data->ins;
	while (tmp)
	{
		tmp_ins = tmp->content;
		if (tmp_ins->opcode == 0)
			return ;
		write(fd, &(tmp_ins->opcode), 1);
		if (tmp_ins->coding_byte)
			write(fd, &(tmp_ins->coding_byte), 1);
		ft_print_param(tmp_ins, fd);
		tmp = tmp->next;
	}
}
