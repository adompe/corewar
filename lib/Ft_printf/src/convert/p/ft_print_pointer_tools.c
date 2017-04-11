/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer_tools.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 17:00:02 by qmoreaux          #+#    #+#             */
/*   Updated: 2016/04/04 17:02:28 by qmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/convert_p.h"

void	ft_calc_size_ptr(unsigned long ptr, int *size)
{
	if (ptr >= 16)
	{
		ft_calc_size_ptr(ptr / 16, size);
		ft_calc_size_ptr(ptr % 16, size);
	}
	else
		(*size)++;
}
