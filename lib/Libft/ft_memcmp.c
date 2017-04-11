/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adompe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:58:17 by adompe            #+#    #+#             */
/*   Updated: 2015/12/03 17:18:23 by adompe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int			i;
	const char	*tmp1 = (const char *)s1;
	const char	*tmp2 = (const char *)s2;

	i = 0;
	while (i < (int)n)
	{
		if (tmp2[i] != tmp1[i])
		{
			return ((unsigned char)tmp1[i] - (unsigned char)tmp2[i]);
		}
		i++;
	}
	return (0);
}
