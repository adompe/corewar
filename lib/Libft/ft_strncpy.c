/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adompe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:37:38 by adompe            #+#    #+#             */
/*   Updated: 2015/12/03 17:06:49 by adompe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *restrict dst, const char *restrict src, size_t n)
{
	int	i;

	i = 0;
	while (src[i] && i < (int)n)
	{
		dst[i] = src[i];
		i++;
	}
	while (i < (int)n)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
