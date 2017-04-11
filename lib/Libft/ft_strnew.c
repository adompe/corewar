/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adompe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 20:23:10 by adompe            #+#    #+#             */
/*   Updated: 2015/12/03 17:06:17 by adompe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = (char *)malloc(sizeof(char) * size + 1);
	if (!tmp)
		return (0);
	while (i < (int)size + 1)
	{
		tmp[i] = '\0';
		i++;
	}
	return (tmp);
}
