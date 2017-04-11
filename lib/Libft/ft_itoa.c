/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adompe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 19:05:05 by adompe            #+#    #+#             */
/*   Updated: 2015/12/07 17:15:23 by adompe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_len(int n)
{
	int		len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char	*s;
	int		len;
	int		nb;

	len = ft_len(n);
	s = (char *)malloc(sizeof(*s) * (len + 1));
	if (!s)
		return (NULL);
	s[len] = '\0';
	nb = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		nb = -n;
	while (len != 0)
	{
		len--;
		s[len] = (nb % 10) + '0';
		nb /= 10;
	}
	if (n < 0)
		s[0] = '-';
	return (s);
}
