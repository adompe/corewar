/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:45:33 by qmoreaux          #+#    #+#             */
/*   Updated: 2016/09/27 10:17:27 by qmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	test_valid(const char *str, int i, int nb)
{
	if ((nb == 0) && \
	((str[i] == '+' && (str[i + 1] >= '0' && str[i + 1] <= '9')) || \
	(str[i] == '-' && (str[i + 1] >= '0' && str[i + 1] <= '9')) || \
	str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || \
	str[i] == '\r' || str[i] == '\f' || str[i] == '\v'))
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	int		nb;
	int		first_nb;
	int		is_valid;

	i = 0;
	nb = 0;
	is_valid = 1;
	first_nb = 0;
	while (i < ft_strlen(str) && is_valid)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			nb = nb * 10 + (str[i] - '0');
			if (!first_nb)
				first_nb = i;
		}
		else
			is_valid = test_valid(str, i, nb);
		i++;
	}
	if (str[first_nb - 1] == '-')
		return (-nb);
	else
		return (nb);
}
