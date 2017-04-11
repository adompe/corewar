/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adompe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 23:24:07 by adompe            #+#    #+#             */
/*   Updated: 2016/02/27 03:31:15 by adompe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(long long n, int base)
{
	char *nb;

	nb = ft_strdup("0123456789abcdef");
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
	}
	if (n < base)
		ft_putchar(nb[n]);
	else
	{
		ft_putnbr_base(n / base, base);
		ft_putchar(nb[n % base]);
	}
}
