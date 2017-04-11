/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 14:27:50 by qmoreaux          #+#    #+#             */
/*   Updated: 2016/04/04 18:47:39 by qmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/convert_cs.h"

int	ft_strlen_wchar(wchar_t *str)
{
	int	i;
	int	tmp;
	int	size;

	i = 0;
	size = 0;
	while (str[i] != 0)
	{
		tmp = 0;
		size_bin((wint_t)str[i], &tmp);
		if (tmp <= 7)
			size++;
		else if (tmp <= 11)
			size += 2;
		else if (tmp <= 16)
			size += 3;
		else
			size += 4;
		i++;
	}
	return (size);
}

int	ft_strlen_precision_wchar(wchar_t *str, int precision)
{
	int	i;
	int	tmp;
	int	size;

	i = 0;
	size = 0;
	while (str[i] != 0 && size <= precision)
	{
		tmp = 0;
		size_bin((wint_t)str[i], &tmp);
		if (tmp <= 7)
			tmp = 1;
		else if (tmp <= 11)
			tmp = 2;
		else if (tmp <= 16)
			tmp = 3;
		else
			tmp = 4;
		i++;
		if (size + tmp <= precision)
			size += tmp;
		else
			return (size);
	}
	return (size);
}

int	ft_putnstr_wchar(wchar_t *str, int n)
{
	int	i;
	int	nb_written;
	int	tmp;
	int	tmp2;

	i = 0;
	nb_written = 0;
	tmp2 = 0;
	while (str[i] != 0 && nb_written + tmp2 <= n)
	{
		tmp = 0;
		size_bin((wint_t)str[i], &tmp);
		if (tmp <= 7)
			tmp2 = 1;
		else if (tmp <= 11)
			tmp2 = 2;
		else if (tmp <= 16)
			tmp2 = 3;
		else
			tmp2 = 4;
		if (tmp2 + nb_written <= n)
			nb_written += ft_p_char_wint(str[i]);
		i++;
	}
	return (nb_written);
}

int	ft_putstr_wchar(wchar_t *str)
{
	int	i;
	int	nb_written;

	i = 0;
	nb_written = 0;
	while (str[i] != 0)
	{
		nb_written += ft_p_char_wint(str[i]);
		i++;
	}
	return (nb_written);
}

int	ft_print_string_wchar(wchar_t *str, t_print param)
{
	int	i;
	int len;
	int	nb_written;

	if (str == 0 && !param.precision_spec)
	{
		ft_putstr("(null)");
		return (6);
	}
	else if (str == 0)
		len = param.field_length;
	else
		len = (int)ft_strlen_wchar(str);
	if (param.precision < len && param.precision_spec && str)
		i = ft_strlen_precision_wchar(str, param.precision);
	else
		i = len;
	suite_string_wchar(param, &i, &nb_written);
	suite_string_wchar2(param, str, &nb_written, i);
	return (nb_written);
}
