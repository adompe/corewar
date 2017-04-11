/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:08:45 by qmoreaux          #+#    #+#             */
/*   Updated: 2015/12/08 14:14:54 by qmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	chr;
	int		found;
	int		i;

	chr = (char)c;
	found = 0;
	i = 0;
	while (s[i] != '\0' && !found)
	{
		if (s[i] == chr)
			found = 1;
		else
			i++;
	}
	if (s[i] == chr || found)
		return ((char *)&s[i]);
	else
		return (NULL);
}
