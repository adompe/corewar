/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned_char.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:15:31 by qmoreaux          #+#    #+#             */
/*   Updated: 2016/04/04 15:53:45 by qmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/convert_boux.h"

void	ft_p_uchar(unsigned char n, int base, int *nb_written, \
	t_print param)
{
	char c;

	c = 0;
	if (n >= (unsigned char)base)
	{
		ft_p_uchar(n / base, base, nb_written, param);
		ft_p_uchar(n % base, base, nb_written, param);
	}
	else
	{
		if (n < 10)
			c = n + '0';
		else
			c = n + 'a' - 10;
		if (param.conversion == 'X' && n >= 10)
			c -= 32;
		ft_putchar(c);
		(*nb_written)++;
	}
}

void	ft_calc_uchar(int nb_char[2], unsigned char n, t_print param, \
	int base)
{
	int	size;

	size = 0;
	ft_len_uchar(n, base, &size);
	if (!n && !param.precision && param.precision_spec)
		size = 0;
	if (base == 8 && param.flags[0])
		size++;
	nb_char[0] = param.precision - size;
	if (nb_char[0] < 0)
		nb_char[0] = 0;
	if (base == 16 && param.flags[0])
		size += 2;
	nb_char[1] = param.field_length - size - nb_char[0];
}

void	suite_uchar2(unsigned char n, t_print param, int *nb_written)
{
	if (param.flags[0] && param.conversion == 'x' && n != 0)
	{
		ft_putstr("0x");
		(*nb_written) += 2;
	}
	else if (param.flags[0] && param.conversion == 'X' && n != 0)
	{
		ft_putstr("0X");
		(*nb_written) += 2;
	}
}

void	suite_uchar(unsigned char n, t_print param, int nb_char[2], \
	int *nb_written)
{
	int	i;

	i = 0;
	while (i < nb_char[1] && param.flags[1] == 0 && param.flags[2] == 0)
	{
		ft_putchar(' ');
		(*nb_written)++;
		i++;
	}
	suite_uchar2(n, param, nb_written);
	while (i < nb_char[1] && param.flags[1] == 1 && param.flags[2] == 0 \
			&& param.precision == 0)
	{
		ft_putchar('0');
		(*nb_written)++;
		i++;
	}
	i = 0;
	while (i < nb_char[0])
	{
		ft_putchar('0');
		i++;
		(*nb_written)++;
	}
}

int		ft_putnbr_unsigned_char(unsigned char n, t_print param, \
	int base)
{
	int	i;
	int	nb_char[2];
	int	nb_written;

	i = 0;
	nb_written = 0;
	ft_calc_uchar(nb_char, n, param, base);
	suite_uchar(n, param, nb_char, &nb_written);
	if (base == 8 && param.flags[0] && (n != 0 || param.precision_spec))
	{
		ft_putchar('0');
		nb_written++;
	}
	if (!(n == 0 && param.precision == 0 && param.precision_spec))
		ft_p_uchar(n, base, &nb_written, param);
	i = 0;
	while (i < nb_char[1] && param.flags[2] == 1)
	{
		ft_putchar(' ');
		i++;
		nb_written++;
	}
	return (nb_written);
}
