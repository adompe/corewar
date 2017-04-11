/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 15:18:15 by qmoreaux          #+#    #+#             */
/*   Updated: 2016/04/05 15:04:38 by qmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/convert_cs.h"

void	size_bin(wint_t value, int *size)
{
	if (value >= (wint_t)2)
	{
		size_bin(value / 2, size);
		size_bin(value % 2, size);
	}
	else
		(*size)++;
}

int		ft_print_char_normal(char c, t_print param)
{
	int	i;
	int	nb_written;

	i = 1;
	nb_written = 0;
	while (param.flags[1] && i < param.field_length && !param.flags[2])
	{
		ft_putchar('0');
		i++;
		nb_written++;
	}
	while (!param.flags[1] && i < param.field_length && !param.flags[2])
	{
		ft_putchar(' ');
		i++;
		nb_written++;
	}
	ft_putchar(c);
	while (i < param.field_length && param.flags[2])
	{
		ft_putchar(' ');
		i++;
		nb_written++;
	}
	return (1 + nb_written);
}

int		ft_p_char_wint(wint_t c)
{
	unsigned int	mask[3];
	unsigned int	v;
	int				size;
	int				res;
	unsigned char	o[5];

	mask[0] = 49280;
	mask[1] = 14712960;
	mask[2] = 4034953344;
	v = c;
	size = 0;
	size_bin(c, &size);
	if (size <= 7)
		res = ft_write_char_1(o, c);
	else if (size <= 11)
		res = ft_write_char_2(mask, v, o);
	else if (size <= 16)
		res = ft_write_char_3(mask, v, o);
	else
		res = ft_write_char_4(mask, v, o);
	return (res);
}

int		ft_print_char_wint(wint_t c, t_print param)
{
	int	i;
	int	nb_written;

	i = 1;
	nb_written = 0;
	while (param.flags[1] && i < param.field_length && !param.flags[2])
	{
		ft_putchar('0');
		i++;
		nb_written++;
	}
	while (!param.flags[1] && i < param.field_length && !param.flags[2])
	{
		ft_putchar(' ');
		i++;
		nb_written++;
	}
	nb_written += ft_p_char_wint(c);
	while (i < param.field_length && param.flags[2])
	{
		ft_putchar(' ');
		i++;
		nb_written++;
	}
	return (nb_written);
}
