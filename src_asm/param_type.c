/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adompe <adompe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 16:05:39 by adompe            #+#    #+#             */
/*   Updated: 2016/11/17 16:05:42 by adompe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_get_num_param(t_param *p, char *str)
{
	if (*str == '%')
		str++;
	p->value = ft_atoi(str);
	if (*str == '-')
		str++;
	while (ft_isdigit(*str))
		str++;
	if (*str)
		ft_error("Error: invalid parameter\n");
	if (!(p->type & T_DIR))
		p->type = 3;
	p->label = NULL;
}

void	ft_get_reg_param(t_param *p, char *str)
{
	str++;
	p->type += T_REG;
	p->value = ft_atoi(str);
	while (ft_isdigit(*str))
		str++;
	if (*str)
		ft_error("Error: invalid parameter\n");
	if (p->value > 16 || p->value == 0)
		ft_error("Error: register is between 1 and 16\n");
	p->label = NULL;
}

void	ft_get_label_param(t_param *p, char *str)
{
	int		i;

	i = 0;
	if (*str == '%')
		str++;
	str++;
	while (str[i] && ft_valid_label_char(str[i], LABEL_CHARS))
		i++;
	if (str[i])
		ft_error("Error: invalid label parameter\n");
	if (!(p->type & T_DIR))
		p->type = 3;
	p->label = ft_strdup(str);
}
