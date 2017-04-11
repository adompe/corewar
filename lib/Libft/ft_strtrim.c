/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adompe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 16:48:03 by adompe            #+#    #+#             */
/*   Updated: 2015/12/16 11:59:39 by adompe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	char	*tmp;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s);
	while (s[i] && (is_space(s[i])))
		i++;
	while (j > i && (is_space(s[j]) || s[j] == 0))
		j--;
	if (i >= j)
		j = i - 1;
	len = j - i + 1;
	tmp = ft_strsub(s, i, len);
	return (tmp);
}
