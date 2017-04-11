/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 15:37:40 by qmoreaux          #+#    #+#             */
/*   Updated: 2016/12/15 13:21:59 by qmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_parse_1.h"

int	parse_id(const char *format, int *id, int i)
{
	int	tmp;

	tmp = i;
	while (format[i] >= '0' && format[i] <= '9')
		i++;
	if (format[i] == '$')
	{
		*id = ft_atoi(format);
		i++;
	}
	else
	{
		*id = 0;
		i = tmp;
	}
	return (i);
}

int	parse_flags(const char *format, int flags[6], int i)
{
	while (format[i] == '#' || format[i] == '0' || format[i] == '-' \
		|| format[i] == '+' || format[i] == ' ' || format[i] == '\'')
	{
		if (format[i] == '#')
			flags[0] = 1;
		if (format[i] == '0')
			flags[1] = 1;
		if (format[i] == '-')
			flags[2] = 1;
		if (format[i] == '+')
			flags[3] = 1;
		if (format[i] == ' ')
			flags[4] = 1;
		if (format[i] == '\'')
			flags[5] = 1;
		i++;
	}
	return (i);
}
