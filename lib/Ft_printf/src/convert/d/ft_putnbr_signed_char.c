/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_signed_char.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:15:31 by qmoreaux          #+#    #+#             */
/*   Updated: 2016/04/04 14:47:34 by qmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/convert_d.h"

void			ft_p_signed_char(signed char n, int *nb_written)
{
	if (n >= SCHAR_MIN)
	{
		if (n >= 10)
		{
			ft_p_signed_char(n / 10, nb_written);
			ft_p_signed_char(n % 10, nb_written);
		}
		else if (n < 0)
		{
			ft_p_signed_char(n / -10, nb_written);
			ft_putchar('0' - (n % 10));
			(*nb_written)++;
		}
		else
		{
			ft_putchar(n + '0');
			(*nb_written)++;
		}
	}
}

void			ft_calc_signed_char(int nb_char[2], signed char n, \
	t_print param)
{
	int	size;

	size = ft_strlen(ft_itoa(n));
	if (!n && !param.precision && param.precision_spec)
		size = 0;
	nb_char[0] = param.precision - size;
	if (n < 0)
		nb_char[0]++;
	if (nb_char[0] < 0)
		nb_char[0] = 0;
	nb_char[1] = param.field_length - size - nb_char[0];
}

signed char		suite_schar_2(signed char n, t_print param, int nb_char[2], \
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
	if (n >= 0 && param.flags[3])
	{
		(*nb_written)++;
		ft_putchar('+');
	}
	if (n < 0)
	{
		ft_putchar('-');
		(*nb_written)++;
	}
	return (i);
}

signed char		suite_schar(signed char n, t_print param, int nb_char[2], \
	int *nb_written)
{
	int	i;

	i = 0;
	if (n >= 0)
	{
		if (param.flags[4] && !param.flags[3])
		{
			ft_putchar(' ');
			(*nb_written)++;
		}
		else if (!param.flags[3])
			nb_char[1]++;
		nb_char[1]--;
	}
	i = suite_schar_2(n, param, nb_char, nb_written);
	while (i < nb_char[1] && param.flags[1] == 1 && param.flags[2] == 0 \
			&& param.precision == 0)
	{
		ft_putchar('0');
		(*nb_written)++;
		i++;
	}
	return ((n < 0) ? -n : n);
}

int				ft_putnbr_signed_char(signed char n, t_print param)
{
	int	i;
	int	nb_char[2];
	int	nb_written;

	i = 0;
	nb_written = 0;
	ft_calc_signed_char(nb_char, n, param);
	n = suite_schar(n, param, nb_char, &nb_written);
	while (i < nb_char[0])
	{
		ft_putchar('0');
		i++;
		nb_written++;
	}
	if (!(n == 0 && param.precision == 0 && param.precision_spec))
		ft_p_signed_char(n, &nb_written);
	i = 0;
	while (i < nb_char[1] && param.flags[2] == 1)
	{
		ft_putchar(' ');
		i++;
		nb_written++;
	}
	return (nb_written);
}
