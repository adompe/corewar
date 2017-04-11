/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adompe <adompe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:50:52 by adompe            #+#    #+#             */
/*   Updated: 2016/11/09 16:50:55 by adompe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_bool			ft_check_label_same(t_ins *ins, char *label)
{
	t_list	*tmp;
	char	*str;

	tmp = ins->label;
	while (tmp)
	{
		str = tmp->content;
		if (ft_strcmp(label, str) == 0)
			return (TRUE);
		tmp = tmp->next;
	}
	return (FALSE);
}

unsigned int	ft_get_adress_label(t_asm *data, char *label, unsigned int pos)
{
	t_list			*tmp;
	t_ins			*ins;
	unsigned int	adress;

	adress = 0;
	tmp = data->ins;
	while (tmp)
	{
		ins = tmp->content;
		if (ins->label && ft_check_label_same(ins, label))
			return (adress - pos);
		adress += (ins->size);
		tmp = tmp->next;
	}
	ft_error("Error: label not found\n");
	return (0);
}

void			ft_set_label_value(t_asm *data, t_ins *ins, unsigned int pos)
{
	t_list	*tmp;
	t_param	*p;

	tmp = ins->param;
	while (tmp)
	{
		p = tmp->content;
		if (p->label)
			p->value = ft_get_adress_label(data, p->label, pos);
		tmp = tmp->next;
	}
}

void			ft_get_prog_size(t_asm *data)
{
	t_list			*tmp;
	t_ins			*ins;
	unsigned int	size;

	size = 0;
	tmp = data->ins;
	while (tmp)
	{
		ins = tmp->content;
		ft_set_label_value(data, ins, size);
		size += (ins->size);
		tmp = tmp->next;
	}
	data->header->prog_size = size;
}
