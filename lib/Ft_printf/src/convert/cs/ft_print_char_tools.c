/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_tools.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 14:54:38 by qmoreaux          #+#    #+#             */
/*   Updated: 2016/04/05 15:03:51 by qmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/convert_cs.h"

int	ft_write_char_1(unsigned char o[5], wint_t c)
{
	o[0] = c;
	write(1, &o[0], 1);
	return (1);
}

int	ft_write_char_2(unsigned int mask[3], unsigned int v, unsigned char o[5])
{
	o[2] = (v << 26) >> 26;
	o[1] = ((v >> 6) << 27) >> 27;
	o[0] = (mask[0] >> 8) | o[1];
	write(1, &o[0], 1);
	o[0] = ((mask[0] << 24) >> 24) | o[2];
	write(1, &o[0], 1);
	return (2);
}

int	ft_write_char_3(unsigned int mask[3], unsigned int v, unsigned char o[5])
{
	o[3] = (v << 26) >> 26;
	o[2] = ((v >> 6) << 26) >> 26;
	o[1] = ((v >> 12) << 28) >> 28;
	o[0] = (mask[1] >> 16) | o[1];
	write(1, &o[0], 1);
	o[0] = ((mask[1] << 16) >> 24) | o[2];
	write(1, &o[0], 1);
	o[0] = ((mask[1] << 24) >> 24) | o[3];
	write(1, &o[0], 1);
	return (3);
}

int	ft_write_char_4(unsigned int mask[3], unsigned int v, unsigned char o[5])
{
	o[4] = (v << 26) >> 26;
	o[3] = ((v >> 6) << 26) >> 26;
	o[2] = ((v >> 12) << 26) >> 26;
	o[1] = ((v >> 18) << 29) >> 29;
	o[0] = (mask[2] >> 24) | o[1];
	write(1, &o[0], 1);
	o[0] = ((mask[2] << 8) >> 24) | o[2];
	write(1, &o[0], 1);
	o[0] = ((mask[2] << 16) >> 24) | o[3];
	write(1, &o[0], 1);
	o[0] = ((mask[2] << 24) >> 24) | o[4];
	write(1, &o[0], 1);
	return (4);
}
