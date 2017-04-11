/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_2.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 15:35:57 by qmoreaux          #+#    #+#             */
/*   Updated: 2016/03/16 15:18:10 by qmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_2_H
# define FT_PRINT_2_H

# include "ft_printf.h"
# include "struct.h"
# include <wchar.h>

int	ft_print_string(t_print param, int *current_id, va_list ap_cpy);
int	ft_print_char(t_print param, int *current_id, va_list ap_cpy);
int	ft_print_pointer(t_print param, int *current_id, va_list ap_cpy);
int	ft_print_number(t_print param, int *current_id, va_list ap_cpy, \
		int nb_print);

#endif
