/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 15:34:05 by qmoreaux          #+#    #+#             */
/*   Updated: 2016/04/05 15:17:45 by qmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_print_2.h"

int	ft_print_string(t_print param, int *current_id, va_list ap_cpy)
{
	int i;
	int	n;

	i = 1;
	n = 0;
	if (param.id != 0)
		*current_id = param.id;
	while (i < *current_id)
	{
		va_arg(ap_cpy, void*);
		i++;
	}
	(*current_id)++;
	if (!ft_strcmp(param.modifier, "") && param.conversion != 'S')
		n = ft_print_string_normal(va_arg(ap_cpy, char*), param);
	else if (!ft_strcmp(param.modifier, "l") || param.conversion == 'S')
		n = ft_print_string_wchar(va_arg(ap_cpy, wchar_t *), param);
	return (n);
}

int	ft_print_char(t_print param, int *current_id, va_list ap_cpy)
{
	int		i;
	int		nb_written;
	wint_t	c;

	i = 1;
	if (param.id != 0)
		*current_id = param.id;
	while (i < *current_id)
	{
		va_arg(ap_cpy, void*);
		i++;
	}
	(*current_id)++;
	if (!ft_strcmp(param.modifier, "") && param.conversion != 'C')
		nb_written = ft_print_char_normal((unsigned char)va_arg(ap_cpy, int),\
		param);
	if (!ft_strcmp(param.modifier, "l") || param.conversion == 'C')
	{
		c = va_arg(ap_cpy, wint_t);
		nb_written = ft_print_char_wint(c, param);
	}
	return (nb_written);
}

int	ft_print_pointer(t_print param, int *current_id, va_list ap_cpy)
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
	return (ft_print_pointer_normal(va_arg(ap_cpy, void*), param));
}

int	ft_print_number(t_print param, int *current_id, va_list ap_cpy, \
		int nb_print)
{
	return (0);
	param.id = 0;
	current_id = 0;
	ap_cpy = NULL;
	nb_print = 0;
}
