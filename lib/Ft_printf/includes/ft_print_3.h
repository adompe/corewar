/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_3.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 15:35:57 by qmoreaux          #+#    #+#             */
/*   Updated: 2016/03/16 15:18:01 by qmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_3_H
# define FT_PRINT_3_H

# include "ft_printf.h"
# include "struct.h"

int	ft_print_double_scientific(t_print param, int *current_id, va_list ap_cpy);
int	ft_print_double_classic(t_print param, int *current_id, va_list ap_cpy);
int	ft_print_double_both(t_print param, int *current_id, va_list ap_cpy);
int	ft_print_double_hexa(t_print param, int *current_id, va_list ap_cpy);
int	ft_print_percent(t_print param);

#endif
