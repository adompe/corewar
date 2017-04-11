/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:16:42 by rfernand          #+#    #+#             */
/*   Updated: 2016/12/14 22:36:37 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/op.h"
#include <math.h>

void			debug(unsigned char *memory)
{
	int	i;

	i = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("%0.2x ", memory[i]);
		i++;
	}
}

unsigned char	*print_memory(unsigned char *memory)
{
	int	i;

	i = 0;
	ft_printf("0x%0.4x : ", i);
	while (i < MEM_SIZE)
	{
		if (!(i % (int)sqrt(MEM_SIZE)) && i != 0)
			ft_printf("\n0x%0.4x : ", i);
		ft_printf("%0.2x ", memory[i]);
		i++;
	}
	ft_printf("\n");
	return ((unsigned char *)NULL);
}
