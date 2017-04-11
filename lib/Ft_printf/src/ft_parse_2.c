/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 15:51:03 by qmoreaux          #+#    #+#             */
/*   Updated: 2016/12/15 13:22:05 by qmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_parse_2.h"

int		parse_conversion(const char *format, char *conversion, int i)
{
	*conversion = format[i];
	if (*conversion == 0)
		*conversion = 1;
	else if (ft_strchr("$#+- .0123456789hljtzL*", *conversion))
		*conversion = 0;
	if (*conversion == 0 || *conversion == 1)
		i--;
	return (i + 1);
}

void	find_modifier(int tab[8], char *modifier)
{
	modifier[1] = 0;
	if (tab[0])
		modifier[0] = 'z';
	else if (tab[1])
		modifier[0] = 't';
	else if (tab[2])
		modifier[0] = 'j';
	else if (tab[3])
		modifier[0] = 'L';
	else if (tab[4])
	{
		modifier[0] = 'l';
		modifier[1] = 'l';
	}
	else if (tab[5])
		modifier[0] = 'l';
	else if (tab[6])
		modifier[0] = 'h';
	else if (tab[7])
	{
		modifier[0] = 'h';
		modifier[1] = 'h';
	}
}

void	parse_modifier_suite(const char *format, int *i, int tab[8])
{
	if (format[*i] == 'l')
	{
		if (format[*i + 1] == 'l')
		{
			tab[4] = 1;
			(*i)++;
		}
		else
			tab[5] = 1;
	}
	else if (format[*i] == 'h')
	{
		if (format[*i + 1] == 'h')
		{
			tab[7] = 1;
			(*i)++;
		}
		else
			tab[6] = 1;
	}
}

int		parse_modifier(const char *format, char *modifier, int i)
{
	int	tab[8];

	init_tab(tab);
	while (format[i] == 'j' || format[i] == 'z' || format[i] == 'L' || \
		format[i] == 'h' || format[i] == 'l' || format[i] == 't')
	{
		if (format[i] == 'z')
			tab[0] = 1;
		else if (format[i] == 't')
			tab[1] = 1;
		else if (format[i] == 'j')
			tab[2] = 1;
		else if (format[i] == 'L')
			tab[3] = 1;
		parse_modifier_suite(format, &i, tab);
		i++;
	}
	find_modifier(tab, modifier);
	return (i);
}
