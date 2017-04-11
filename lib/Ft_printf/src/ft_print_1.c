/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 19:08:25 by qmoreaux          #+#    #+#             */
/*   Updated: 2016/04/05 15:16:50 by qmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_print_1.h"

int	ft_print_signed_int_suite(t_print param, va_list ap_cpy)
{
	int	nb_written;

	nb_written = 0;
	if (param.conversion == 'D')
		ft_strcpy(param.modifier, "l\0");
	if (!ft_strcmp(param.modifier, ""))
		nb_written = ft_putnbr_int(va_arg(ap_cpy, int), param);
	else if (!ft_strcmp(param.modifier, "hh"))
		nb_written = ft_putnbr_signed_char((signed char)va_arg(ap_cpy, int), \
				param);
	else if (!ft_strcmp(param.modifier, "h"))
		nb_written = ft_putnbr_short((short)va_arg(ap_cpy, int), param);
	else if (!ft_strcmp(param.modifier, "l"))
		nb_written = ft_putnbr_long(va_arg(ap_cpy, long), param);
	else if (!ft_strcmp(param.modifier, "ll"))
		nb_written = ft_putnbr_long_long(va_arg(ap_cpy, long long), param);
	else if (!ft_strcmp(param.modifier, "j"))
		nb_written = ft_putnbr_intmax(va_arg(ap_cpy, intmax_t), param);
	else if (!ft_strcmp(param.modifier, "t"))
		nb_written = ft_putnbr_ptrdiff(va_arg(ap_cpy, ptrdiff_t), param);
	else if (!ft_strcmp(param.modifier, "z"))
		nb_written = ft_putnbr_size(va_arg(ap_cpy, ssize_t), param);
	return (nb_written);
}

int	ft_print_signed_int(t_print param, int *current_id, va_list ap_cpy)
{
	int i;

	i = 1;
	if (param.id != 0)
		*current_id = param.id;
	while (i < *current_id)
	{
		va_arg(ap_cpy, void*);
		i++;
	}
	(*current_id)++;
	if (param.precision_spec)
		param.flags[1] = 0;
	return (ft_print_signed_int_suite(param, ap_cpy));
}

int	ft_print_unsigned_int_suite(t_print param, va_list ap_cpy, int base)
{
	int	nb_written;

	nb_written = 0;
	if ((param.conversion == 'O' || param.conversion == 'U'))
		ft_strcpy(param.modifier, "l\0");
	if (!ft_strcmp(param.modifier, ""))
		nb_written = ft_putnbr_uint(va_arg(ap_cpy, unsigned int), param, base);
	else if (!ft_strcmp(param.modifier, "hh"))
		nb_written = ft_putnbr_unsigned_char((unsigned char)va_arg(ap_cpy, \
					unsigned int), param, base);
	else if (!ft_strcmp(param.modifier, "h"))
		nb_written = ft_putnbr_ushort((unsigned short)va_arg(ap_cpy, \
					unsigned int), param, base);
	else if (!ft_strcmp(param.modifier, "l"))
		nb_written = ft_putnbr_ulong(va_arg(ap_cpy, unsigned long), \
				param, base);
	else if (!ft_strcmp(param.modifier, "ll"))
		nb_written = ft_putnbr_ulong_long(va_arg(ap_cpy, unsigned long long), \
				param, base);
	else if (!ft_strcmp(param.modifier, "j"))
		nb_written = ft_putnbr_uintmax(va_arg(ap_cpy, uintmax_t), param, base);
	else if (!ft_strcmp(param.modifier, "t") || !ft_strcmp(param.modifier, "z"))
		nb_written = ft_putnbr_usize((size_t)va_arg(ap_cpy, size_t), param, \
		base);
	return (nb_written);
}

int	ft_print_unsigned_int(t_print param, int *current_id, va_list ap_cpy, \
	int base)
{
	int i;

	i = 1;
	if (param.id != 0)
		*current_id = param.id;
	while (i < *current_id)
	{
		va_arg(ap_cpy, void*);
		i++;
	}
	(*current_id)++;
	if (param.precision_spec)
		param.flags[1] = 0;
	return (ft_print_unsigned_int_suite(param, ap_cpy, base));
}

int	ft_print_no_convert(t_print param)
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
	ft_putchar(param.conversion);
	while (i < param.field_length && param.flags[2] == 1)
	{
		ft_putchar(' ');
		i++;
	}
	if (!param.conversion)
		return (0);
	return (i);
}
