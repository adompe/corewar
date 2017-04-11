/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adompe <adompe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 21:45:38 by adompe            #+#    #+#             */
/*   Updated: 2016/10/23 21:45:41 by adompe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_error(char *message)
{
	ft_putstr(message);
	exit(0);
}

t_bool	ft_valid_label_char(char c, char *label_chars)
{
	int i;

	i = 0;
	while (i < (int)ft_strlen(label_chars))
	{
		if (label_chars[i] != c)
			i++;
		else
			return (TRUE);
	}
	return (FALSE);
}

void	ft_check_s_file(char *str)
{
	char **tab;

	tab = ft_strsplit(str, '.');
	if (!tab[0])
		ft_error("Error: bad file type\n");
	if (ft_strcmp(tab[ft_tablen(tab) - 1], "s") != 0)
		ft_error("Error: bad file type\n");
}

t_bool	ft_is_com(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '#')
		return (TRUE);
	return (FALSE);
}
