/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 05:57:40 by qmoreaux          #+#    #+#             */
/*   Updated: 2016/12/15 13:22:09 by qmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_parse_3.h"

void	parse_field_length_suite(const char *format, t_print *param, \
	t_norme *norme)
{
	int	ok;
	int	tmp;

	tmp = norme->j;
	if (format[norme->j] != '*')
	{
		while (format[norme->j] >= '0' && format[norme->j] <= '9')
			norme->j++;
		ok = ft_atoi(&format[tmp]);
		if (ok)
			param->field_length = ok;
	}
	if (param->field_length < 0)
	{
		param->field_length = -(param->field_length);
		param->flags[2] = 1;
	}
}

int		parse_field_length(const char *format, t_print *param, t_norme *norme, \
	va_list ap_cpy)
{
	int cmp;
	int	value;

	cmp = 1;
	if (format[norme->j] == '*')
	{
		norme->j++;
		if (format[norme->j] > '0' && format[norme->j] < '9')
			value = ft_atoi(&format[norme->j]);
		else
			value = norme->current_id;
		while (cmp < value)
		{
			va_arg(ap_cpy, void*);
			cmp++;
		}
		norme->current_id = cmp + 1;
		param->field_length = va_arg(ap_cpy, int);
	}
	parse_field_length_suite(format, param, norme);
	return (norme->j);
}

void	parse_precision_suite(const char *format, int precision[2], \
	t_norme *norme, va_list ap_cpy)
{
	int	tmp;
	int value;

	tmp = 1;
	norme->j++;
	if (format[norme->j] > '0' && format[norme->j] < '9')
		value = ft_atoi(&format[norme->j]);
	else
		value = norme->current_id;
	while (tmp < value)
	{
		va_arg(ap_cpy, void*);
		tmp++;
	}
	norme->current_id = tmp + 1;
	precision[0] = va_arg(ap_cpy, int);
}

int		parse_precision(const char *format, int precision[2], t_norme *norme, \
	va_list ap_cpy)
{
	int	tmp[2];

	tmp[0] = norme->j;
	tmp[1] = 1;
	if (format[norme->j] == '.')
	{
		precision[1] = 1;
		norme->j++;
		if (format[norme->j] == '*')
			parse_precision_suite(format, precision, norme, ap_cpy);
		else
		{
			while (format[norme->j] >= '0' && format[norme->j] <= '9')
				norme->j++;
			precision[0] = ft_atoi(&format[tmp[0] + 1]);
		}
	}
	if (*precision < 0)
	{
		precision[0] = 0;
		precision[1] = 0;
	}
	return (norme->j);
}
