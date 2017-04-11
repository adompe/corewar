/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:31:34 by qmoreaux          #+#    #+#             */
/*   Updated: 2016/09/27 10:17:45 by qmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		size_nb(long n)
{
	int i;

	i = 0;
	if (n < 0)
	{
		i = 1;
		n = -n;
	}
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

char	*ft_itoa(int n)
{
	char	*ptr_n;
	long	nb;
	int		i;
	int		taille;

	nb = (long)n;
	i = 0;
	taille = size_nb(n);
	ptr_n = (char *)malloc(sizeof(char*) * taille);
	if (nb < 0)
	{
		ptr_n[0] = '-';
		nb = -nb;
	}
	while (nb >= 10)
	{
		ptr_n[taille - 1 - i] = nb % 10 + '0';
		nb = nb / 10;
		i++;
	}
	ptr_n[taille - i - 1] = nb + '0';
	return (ptr_n);
}
