/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 21:41:27 by qmoreaux          #+#    #+#             */
/*   Updated: 2016/05/17 12:19:42 by qmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "ft_printf_init.h"
# include "ft_parse_1.h"
# include "ft_parse_2.h"
# include "ft_print_1.h"
# include "ft_print_2.h"
# include "ft_print_3.h"
# include "convert_d.h"
# include "convert_boux.h"
# include "convert_cs.h"
# include "convert_p.h"
# include "convert_aefg.h"
# include "struct.h"
# include "libft.h"

int				ft_printf(const char *format, ...);
int				ft_analyze(const char *format, t_print *param, t_norme *norme);
int				ft_print_printf(t_print param, int *current_id, \
				va_list ap_cpy, int nb_print);
int				ft_print_bonus(t_print param, int *current_id, \
				va_list ap_cpy, int nb_print);
void			ft_init(t_print *param);
void			test(t_print param);

#endif
