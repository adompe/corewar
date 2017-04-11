/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_arg_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 16:47:02 by rfernand          #+#    #+#             */
/*   Updated: 2016/12/08 18:33:25 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void	recup_11(unsigned char *str, unsigned int *params)
{
	params[0] = str[0];
	params[1] = str[1];
}

void	recup_12(unsigned char *str, unsigned int *params)
{
	params[0] = str[0];
	params[1] = 256 * str[1] + str[2];
}

void	recup_221(unsigned char *str, unsigned int *params)
{
	params[0] = 256 * str[0] + str[1];
	params[1] = 256 * str[2] + str[3];
	params[2] = str[4];
}

void	recup_241(unsigned char *str, unsigned int *params)
{
	params[0] = 256 * str[0] + str[1];
	params[1] = CUBE * str[2] + CARRE * str[3] + 256 * str[4] + str[5];
	params[2] = str[6];
}

void	recup_211(unsigned char *str, unsigned int *params)
{
	params[0] = 256 * str[0] + str[1];
	params[1] = str[2];
	params[2] = str[3];
}
