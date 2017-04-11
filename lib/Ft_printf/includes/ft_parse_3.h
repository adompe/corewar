/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_1.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 15:44:55 by qmoreaux          #+#    #+#             */
/*   Updated: 2016/03/15 06:37:04 by qmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSE_3_H
# define FT_PARSE_3_H

# include <stdarg.h>
# include "libft.h"
# include "struct.h"

int	parse_field_length(const char *format, t_print *param, \
	t_norme *norme, va_list ap_cpy);
int	parse_precision(const char *format, int precision[2], \
	t_norme *norme, va_list ap_cpy);

#endif
