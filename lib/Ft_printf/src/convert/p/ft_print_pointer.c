/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 16:37:22 by qmoreaux          #+#    #+#             */
/*   Updated: 2016/04/04 17:00:36 by qmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/convert_p.h"

void	ft_p_ptr_ulong(unsigned long n, t_print param, int *nb_written)
{
	char c;

	c = 0;
	if (n >= 16)
	{
		ft_p_ptr_ulong(n / 16, param, nb_written);
		ft_p_ptr_ulong(n % 16, param, nb_written);
	}
	else
	{
		if (n < 10)
			c = '0' + n;
		else
			c = n + 'a' - 10;
		ft_putchar(c);
		(*nb_written)++;
	}
}

int		ft_calc_ptr_ulong(unsigned long ptr, int nb_char[2], t_print param)
{
	int	size;

	size = 0;
	ft_calc_size_ptr(ptr, &size);
	size += 2;
	if (param.precision >= size + 1)
		param.precision = size + 1;
	nb_char[0] = param.precision - size;
	if (nb_char[0] < 0)
		nb_char[0] = 0;
	nb_char[1] = param.field_length - size - nb_char[0];
	return (size);
}

void	suite_ptr(int nb_char[2], t_print param, int *nb_written, int size)
{
	int	i;

	i = 0;
	while (i < nb_char[1] && param.flags[2] == 0 && !param.flags[1])
	{
		ft_putchar(' ');
		i++;
		(*nb_written)++;
	}
	ft_putstr("0x");
	*nb_written += 2;
	while (i < param.precision - size + 2)
	{
		ft_putchar('0');
		i++;
		(*nb_written)++;
	}
}

int		ft_putptr_ulong(unsigned long ptr, t_print param)
{
	int	i;
	int	nb_char[2];
	int size;
	int	nb_written;

	nb_written = 0;
	size = ft_calc_ptr_ulong(ptr, nb_char, param);
	suite_ptr(nb_char, param, &nb_written, size);
	if (param.precision != 0 || !param.precision_spec)
		ft_p_ptr_ulong(ptr, param, &nb_written);
	i = 0;
	while (i < nb_char[1] && param.flags[1])
	{
		ft_putchar('0');
		i++;
		nb_written++;
	}
	while (i < nb_char[1] && param.flags[2])
	{
		ft_putchar(' ');
		i++;
		nb_written++;
	}
	return (nb_written);
}

int		ft_print_pointer_normal(void *ptr, t_print param)
{
	unsigned long	ptr_long;

	ptr_long = (unsigned long)ptr;
	return (ft_putptr_ulong(ptr_long, param));
}
