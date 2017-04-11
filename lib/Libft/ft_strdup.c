/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adompe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:14:21 by adompe            #+#    #+#             */
/*   Updated: 2015/12/16 11:15:23 by adompe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		c;
	int		i;
	char	*tmp;

	i = 0;
	c = ft_strlen(s1);
	tmp = malloc((c + 1) * sizeof(char));
	if (!tmp)
		return (0);
	while (i < c)
	{
		tmp[i] = s1[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
