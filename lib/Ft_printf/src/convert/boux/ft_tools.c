/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 15:06:27 by qmoreaux          #+#    #+#             */
/*   Updated: 2016/04/04 15:41:45 by qmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/convert_boux.h"

void			ft_len_uint(unsigned int n, int base, int *size)
{
	if (n >= (unsigned int)base)
	{
		ft_len_uint(n / base, base, size);
		ft_len_uint(n % base, base, size);
	}
	else
		(*size)++;
}

void			ft_len_uintmax(uintmax_t n, int base, int *size)
{
	if (n >= (uintmax_t)base)
	{
		ft_len_uint(n / base, base, size);
		ft_len_uint(n % base, base, size);
	}
	else
		(*size)++;
}

void			ft_len_ulong(unsigned long n, int base, int *size)
{
	if (n >= (unsigned long)base)
	{
		ft_len_uint(n / base, base, size);
		ft_len_uint(n % base, base, size);
	}
	else
		(*size)++;
}

void			ft_len_ulong_long(unsigned long long n, int base, int *size)
{
	if (n >= (unsigned long long)base)
	{
		ft_len_uint(n / base, base, size);
		ft_len_uint(n % base, base, size);
	}
	else
		(*size)++;
}

void			ft_len_uchar(unsigned char n, int base, int *size)
{
	if (n >= (unsigned char)base)
	{
		ft_len_uint(n / base, base, size);
		ft_len_uint(n % base, base, size);
	}
	else
		(*size)++;
}
