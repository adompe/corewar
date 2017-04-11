/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opcode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adompe <adompe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 14:49:29 by adompe            #+#    #+#             */
/*   Updated: 2016/12/14 20:51:24 by qmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_param	*ft_get_tparam(char *str)
{
	t_param		*p;
	int			i;

	i = 0;
	p = (t_param *)malloc(sizeof(t_param));
	p->type = 0;
	if (str[i] == '%')
	{
		p->type = T_DIR;
		i++;
	}
	if (!str[i])
		ft_error("Error: invalid parameter\n");
	if (str[i] == 'r')
		ft_get_reg_param(p, str);
	else if (str[i] == ':')
		ft_get_label_param(p, str);
	else if (ft_isdigit(str[i]) || str[i] == '-')
		ft_get_num_param(p, str);
	else
		ft_error("Error: invalid parameter\n");
	return (p);
}

t_bool	ft_check_coma(char **tab)
{
	int i;
	int	last;

	i = 0;
	if (tab[i][0] == ',')
		return (TRUE);
	i++;
	while (tab[i])
	{
		last = ft_strlen(tab[i - 1]);
		if (tab[i][0] == '#' && tab[i - 1][last - 1] == ',')
			return (TRUE);
		else if (tab[i][0] == '#')
			return (FALSE);
		if (tab[i][0] != ',' && tab[i - 1][last - 1] != ',')
			return (TRUE);
		i++;
	}
	return (FALSE);
}

void	ft_get_ins_param(t_ins *ins, char **tab)
{
	t_param		*par;
	char		**ntab;

	if (ft_check_coma(tab))
		ft_error("Error: invalid parameter\n");
	while (*tab)
	{
		if (*tab[0] == COMMENT_CHAR || *tab[0] == ';')
			return ;
		ntab = ft_strsplit(*tab, ',');
		while (*ntab)
		{
			par = ft_get_tparam(*ntab);
			if (ins->param == NULL)
				ins->param = ft_lstnew(par, sizeof(t_param));
			else
				ft_lstappend(&(ins->param), ft_lstnew(par, sizeof(t_param)));
			ntab++;
		}
		tab++;
	}
}
