/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 15:34:05 by qmoreaux          #+#    #+#             */
/*   Updated: 2016/12/15 13:22:18 by qmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_print_3.h"

int	ft_print_double_scientific(t_print param, int *current_id, va_list ap_cpy)
{
	int	nb_written;
	int i;

	i = 1;
	nb_written = 0;
	if (param.id != 0)
		*current_id = param.id;
	while (i < *current_id)
	{
		va_arg(ap_cpy, void*);
		i++;
	}
	(*current_id)++;
	if (!ft_strcmp(param.modifier, ""))
		nb_written = ft_putnbr_double_scientific(va_arg(ap_cpy, double), param);
	else if (!ft_strcmp(param.modifier, "L"))
		nb_written = ft_putnbr_long_double_scientific(va_arg(ap_cpy, \
			long double), param);
	return (nb_written);
}

int	ft_print_double_classic(t_print param, int *current_id, va_list ap_cpy)
{
	int	nb_written;
	int i;

	i = 1;
	nb_written = 0;
	if (param.id != 0)
		*current_id = param.id;
	while (i < *current_id)
	{
		va_arg(ap_cpy, void*);
		i++;
	}
	(*current_id)++;
	if (!ft_strcmp(param.modifier, ""))
		nb_written = ft_putnbr_double_classic(va_arg(ap_cpy, double), param);
	else if (!ft_strcmp(param.modifier, "L"))
		nb_written = ft_putnbr_long_double_classic(va_arg(ap_cpy, \
			long double), param);
	return (nb_written);
}

int	ft_print_double_both(t_print param, int *current_id, va_list ap_cpy)
{
	int	nb_written;
	int i;

	i = 1;
	nb_written = 0;
	if (param.id != 0)
		*current_id = param.id;
	while (i < *current_id)
	{
		va_arg(ap_cpy, void*);
		i++;
	}
	(*current_id)++;
	if (!ft_strcmp(param.modifier, ""))
		nb_written = ft_putnbr_double_both(va_arg(ap_cpy, double), param);
	else if (!ft_strcmp(param.modifier, "L"))
		nb_written = ft_putnbr_long_double_both(va_arg(ap_cpy, \
			long double), param);
	return (nb_written);
}

int	ft_print_double_hexa(t_print param, int *current_id, va_list ap_cpy)
{
	int	nb_written;
	int i;

	i = 1;
	nb_written = 0;
	if (param.id != 0)
		*current_id = param.id;
	while (i < *current_id)
	{
		va_arg(ap_cpy, void*);
		i++;
	}
	(*current_id)++;
	if (!ft_strcmp(param.modifier, ""))
		nb_written = ft_putnbr_double_hexa(va_arg(ap_cpy, double), param);
	else if (!ft_strcmp(param.modifier, "L"))
		nb_written = ft_putnbr_long_double_hexa(va_arg(ap_cpy, \
			long double), param);
	return (nb_written);
}

int	ft_print_percent(t_print param)
{
	int i;

	i = 1;
	while (i < param.field_length && param.flags[2] == 0 && !param.flags[1])
	{
		ft_putchar(' ');
		i++;
	}
	while (i < param.field_length && param.flags[2] == 0 && param.flags[1])
	{
		ft_putchar('0');
		i++;
	}
	ft_putchar('%');
	while (i < param.field_length && param.flags[2] == 1)
	{
		ft_putchar(' ');
		i++;
	}
	return (i);
}
