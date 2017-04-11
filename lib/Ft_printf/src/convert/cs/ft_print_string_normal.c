/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string_normal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 17:39:48 by qmoreaux          #+#    #+#             */
/*   Updated: 2016/04/04 18:58:17 by qmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/convert_cs.h"

void	suite_string_normal(t_print param, int *i, int *nb_written)
{
	*nb_written = 0;
	while (param.flags[1] && *i < param.field_length && !param.flags[2])
	{
		ft_putchar('0');
		(*i)++;
		(*nb_written)++;
	}
	while (!param.flags[1] && *i < param.field_length && !param.flags[2])
	{
		ft_putchar(' ');
		(*i)++;
		(*nb_written)++;
	}
}

void	suite_string_normal2(t_print param, char *str, int *nb_written, int i)
{
	if (param.precision_spec && str)
		ft_putnstr(str, param.precision);
	else if (str)
		ft_putstr(str);
	while (i < param.field_length && param.flags[2])
	{
		ft_putchar(' ');
		i++;
		(*nb_written)++;
	}
}

int		ft_print_string_normal(char *str, t_print param)
{
	int	i;
	int	len;
	int	nb_written;

	if (str == 0 && !param.precision_spec)
	{
		ft_putstr("(null)");
		return (6);
	}
	else if (str == 0)
		len = param.field_length;
	else
		len = (int)ft_strlen(str);
	if (param.precision < len && param.precision_spec)
		i = param.precision;
	else
		i = len;
	suite_string_normal(param, &i, &nb_written);
	suite_string_normal2(param, str, &nb_written, i);
	if (param.precision_spec && param.precision < len)
		nb_written += param.precision;
	else
		nb_written += len;
	return (nb_written);
}

void	suite_string_wchar(t_print param, int *i, int *nb_written)
{
	*nb_written = 0;
	while (param.flags[1] && *i < param.field_length && !param.flags[2])
	{
		ft_putchar('0');
		(*i)++;
		(*nb_written)++;
	}
	while (!param.flags[1] && *i < param.field_length && !param.flags[2])
	{
		ft_putchar(' ');
		(*i)++;
		(*nb_written)++;
	}
}

void	suite_string_wchar2(t_print param, wchar_t *str, int *nb_written, int i)
{
	if (param.precision_spec && str)
		*nb_written += ft_putnstr_wchar(str, param.precision);
	else if (str)
		*nb_written += ft_putstr_wchar(str);
	while (i < param.field_length && param.flags[2])
	{
		ft_putchar(' ');
		i++;
		(*nb_written)++;
	}
}
