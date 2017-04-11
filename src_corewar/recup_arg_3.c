/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_arg_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 16:52:17 by rfernand          #+#    #+#             */
/*   Updated: 2016/12/08 18:36:19 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void	recup_421(unsigned char *str, unsigned int *params)
{
	params[0] = CUBE * str[0] + CARRE * str[1] + 256 * str[2] + str[3];
	params[1] = 256 * str[4] + str[5];
	params[2] = str[6];
}

void	recup_441(unsigned char *str, unsigned int *params)
{
	params[0] = CUBE * str[0] + CARRE * str[1] + 256 * str[2] + str[3];
	params[1] = CUBE * str[4] + CARRE * str[5] + 256 * str[6] + str[7];
	params[2] = str[8];
}

void	recup_141(unsigned char *str, unsigned int *params)
{
	params[0] = str[0];
	params[1] = CUBE * str[1] + CARRE * str[2] + 256 * str[3] + str[4];
	params[2] = str[5];
}

void	recup_411(unsigned char *str, unsigned int *params)
{
	params[0] = CUBE * str[0] + CARRE * str[1] + 256 * str[2] + str[3];
	params[1] = str[4];
	params[2] = str[5];
}

void	recup_121(unsigned char *str, unsigned int *params)
{
	params[0] = str[0];
	params[1] = 256 * str[1] + str[2];
	params[2] = str[3];
}
