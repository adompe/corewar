/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adompe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 18:16:21 by adompe            #+#    #+#             */
/*   Updated: 2015/12/02 18:17:14 by adompe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*tmp;
	const char	*tmp2;

	tmp = dst;
	tmp2 = src;
	if (tmp2 <= tmp)
	{
		tmp = tmp + len - 1;
		tmp2 = tmp2 + len - 1;
		while (len--)
			*tmp-- = *tmp2--;
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
