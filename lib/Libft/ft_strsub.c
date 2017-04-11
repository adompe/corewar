/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adompe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:46:46 by adompe            #+#    #+#             */
/*   Updated: 2015/12/03 17:04:15 by adompe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*tmp;
	int		i;

	if (!s)
		return (NULL);
	tmp = (char *)malloc(sizeof(*tmp) * len + 1);
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < (int)len && s[i + start])
	{
		tmp[i] = s[i + start];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
