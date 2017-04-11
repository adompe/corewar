/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_1.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 15:44:55 by qmoreaux          #+#    #+#             */
/*   Updated: 2016/03/15 06:36:35 by qmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSE_1_H
# define FT_PARSE_1_H

# include <stdarg.h>
# include "libft.h"
# include "struct.h"

int	parse_id(const char *format, int *id, int i);
int	parse_flags(const char *format, int flags[6], int i);
int	parse_field_length(const char *format, t_print *param, \
	t_norme *norme, va_list ap_cpy);
int	parse_precision(const char *format, int precision[2], \
	t_norme *norme, va_list ap_cpy);

#endif
