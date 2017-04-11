/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rostring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 15:50:14 by rfernand          #+#    #+#             */
/*   Updated: 2015/12/18 16:32:23 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_strlennew(char *str)
{
	int	i;
	int	u;

	i = 0;
	u = 0;
	while (str[i])
	{
		while (str[i] != ' ' && str[i] != '\t' && str[i])
		{
			u++;
			i++;
		}
		if (str[i] == ' ' || str[i] == '\t')
		{
			u++;
			i++;
		}
		while ((str[i] == ' ' || str[i] == '\t') && str[i])
			i++;
	}
	return (u);
}

static char	*delete_space(char *str)
{
	int		i;
	int		u;
	char	*buf;

	i = 0;
	u = 0;
	buf = malloc((ft_strlennew(str) + 1) * sizeof(char *));
	while ((str[i] == ' ' || str[i] == '\t') && str[i])
		i++;
	while (str[i])
	{
		while (str[i] != ' ' && str[i] != '\t' && str[i])
		{
			buf[u] = str[i];
			u++;
			i++;
		}
		buf[u++] = ' ';
		while ((str[i] == ' ' || str[i] == '\t') && str[i])
			i++;
	}
	buf[u - 1] = '\0';
	return (buf);
}

char		*ft_stradvtrim(char *str)
{
	int	i;
	int	u;

	i = 0;
	u = 0;
	while ((str[i] == ' ' || str[i] == '\t') && str[i])
		i++;
	while (str[i])
		str[u++] = str[i++];
	i = 0;
	while (str[u])
		str[u++] = '\0';
	str = delete_space(str);
	return (str);
}
