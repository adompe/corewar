/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adompe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 23:52:24 by adompe            #+#    #+#             */
/*   Updated: 2015/12/01 23:52:36 by adompe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		tmp;
	int		i;
	int		j;

	if (!*s2)
		return ((char *)s1);
	i = 0;
	while (s1[i] && n > 0)
	{
		j = 0;
		if (n < ft_strlen(s2))
			return (NULL);
		tmp = i;
		while (s1[tmp] == s2[j] && s2[j] && s1[tmp])
		{
			j++;
			tmp++;
		}
		if (s2[j] == '\0')
			return ((char *)s1 + i);
		n--;
		i++;
	}
	return (NULL);
}
