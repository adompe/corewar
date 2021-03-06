/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 14:57:49 by rfernand          #+#    #+#             */
/*   Updated: 2016/11/24 16:54:16 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_power(int i, int power)
{
	if (power == 0)
		return (1);
	if (power == 1)
		return (i);
	else
		return (i * ft_power(i, power - 1));
}
