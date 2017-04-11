/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ins.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adompe <adompe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 15:09:34 by adompe            #+#    #+#             */
/*   Updated: 2016/10/23 15:09:36 by adompe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_bool	ft_check_opcode(t_ins *new_ins, char **tab, t_op g_op_tab[17])
{
	int i;

	i = 0;
	while (i < 16 && *tab)
	{
		if (ft_strcmp(g_op_tab[i].name, *tab) == 0
		&& ft_strlen(*tab) == ft_strlen(g_op_tab[i].name))
		{
			tab++;
			if (!(*tab))
				return (FALSE);
			new_ins->op_code = g_op_tab[i];
			new_ins->opcode = g_op_tab[i].opcode;
			ft_get_ins_param(new_ins, tab);
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

t_bool	ft_get_label_ins(t_ins *ins, char *str)
{
	int i;

	i = 0;
	while (str[i] && ft_valid_label_char(str[i], LABEL_CHARS))
		i++;
	if (str[i] == LABEL_CHAR && i == (int)ft_strlen(str) - 1)
	{
		str[i] = '\0';
		if (ins->label == NULL)
			ins->label = ft_lstnew(str, i + 1);
		else
			ft_lstappend(&(ins->label), ft_lstnew(str, i + 1));
		return (TRUE);
	}
	return (FALSE);
}

char	**ft_split_line(char *line)
{
	char	**tab;
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\t')
			line[i] = ' ';
		i++;
	}
	tab = ft_strsplit(line, ' ');
	return (tab);
}

void	ft_get_ins_line(t_ins *ins, char *line, t_op g_op_tab[17])
{
	char	**tab;
	int		i;
	t_bool	is_label;

	i = 0;
	tab = ft_split_line(line);
	while (tab[i])
	{
		if (tab[i][0] == '#')
			return ;
		is_label = ft_get_label_ins(ins, tab[i]);
		if (!is_label)
			if (ft_check_opcode(ins, tab + i, g_op_tab))
				return ;
		if (!is_label)
			ft_error("Error: Bad instruction\n");
		i++;
	}
}
