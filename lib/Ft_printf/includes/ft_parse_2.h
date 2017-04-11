/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_2.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 15:44:55 by qmoreaux          #+#    #+#             */
/*   Updated: 2016/03/15 05:45:04 by qmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSE_2_H
# define FT_PARSE_2_H

# include "libft.h"
# include "ft_printf_init.h"

int	parse_conversion(const char *format, char *conversion, int i);
int	parse_modifier(const char *format, char *modifier, int i);

#endif
