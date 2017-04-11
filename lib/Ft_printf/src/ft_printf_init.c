/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 05:27:31 by qmoreaux          #+#    #+#             */
/*   Updated: 2016/12/15 13:22:28 by qmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_init.h"

void	init_norme_printf(t_norme *norme)
{
	norme->i = 0;
	norme->j = 0;
	norme->current_id = 1;
	norme->nb_print = 0;
}

void	ft_init(t_print *param)
{
	param->id = 0;
	param->flags[0] = 0;
	param->flags[1] = 0;
	param->flags[2] = 0;
	param->flags[3] = 0;
	param->flags[4] = 0;
	param->flags[5] = 0;
	param->field_length = 0;
	param->precision = 0;
	param->precision_spec = 0;
	param->modifier = NULL;
	param->conversion = 0;
}

void	init_tab(int tab[8])
{
	int	i;

	i = 0;
	while (i < 8)
	{
		tab[i] = 0;
		i++;
	}
}
