/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_arg_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 15:45:54 by rfernand          #+#    #+#             */
/*   Updated: 2016/12/08 18:31:42 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void	recup_111(unsigned char *str, unsigned int *params)
{
	params[0] = str[0];
	params[1] = str[1];
	params[2] = str[2];
}

void	recup_122(unsigned char *str, unsigned int *params)
{
	params[0] = str[0];
	params[1] = 256 * str[1] + str[2];
	params[2] = 256 * str[3] + str[4];
}

void	recup_112(unsigned char *str, unsigned int *params)
{
	params[0] = str[0];
	params[1] = str[1];
	params[2] = 256 * str[2] + str[3];
}

void	recup_41(unsigned char *str, unsigned int *params)
{
	params[0] = CUBE * str[0] + CARRE * str[1] + 256 * str[2] + str[3];
	params[1] = str[4];
}

void	recup_21(unsigned char *str, unsigned int *params)
{
	params[0] = 256 * str[0] + str[1];
	params[1] = str[2];
}
