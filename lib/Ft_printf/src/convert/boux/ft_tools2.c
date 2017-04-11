/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 15:46:48 by qmoreaux          #+#    #+#             */
/*   Updated: 2016/04/04 15:55:11 by qmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/convert_boux.h"

void	ft_len_ushort(unsigned short n, int base, int *size)
{
	if (n >= (unsigned short)base)
	{
		ft_len_ushort(n / base, base, size);
		ft_len_ushort(n % base, base, size);
	}
	else
		(*size)++;
}

void	ft_len_usize(size_t n, int base, int *size)
{
	if (n >= (size_t)base)
	{
		ft_len_ushort(n / base, base, size);
		ft_len_ushort(n % base, base, size);
	}
	else
		(*size)++;
}
