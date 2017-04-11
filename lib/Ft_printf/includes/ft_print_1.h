/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_1.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 19:17:32 by qmoreaux          #+#    #+#             */
/*   Updated: 2016/03/13 15:35:47 by qmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_1_H
# define FT_PRINT_1_H

# include "ft_printf.h"
# include "struct.h"

int		ft_print_signed_int(t_print param, int *current_id, va_list ap_cpy);
int		ft_print_unsigned_int(t_print param, int *current_id, va_list ap_cpy, \
		int base);
int		ft_print_no_convert(t_print param);
#endif
