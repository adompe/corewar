/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 14:43:25 by qmoreaux          #+#    #+#             */
/*   Updated: 2016/03/17 16:11:57 by qmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdarg.h>

typedef struct	s_print{
	int		id;
	int		flags[6];
	int		field_length;
	int		precision;
	int		precision_spec;
	char	*modifier;
	char	conversion;

}				t_print;

typedef struct	s_norme{
	int		i;
	int		j;
	int		current_id;
	int		nb_print;
	va_list	ap[2];
}				t_norme;

typedef struct	s_convert
{
	int	i;
	int	nb_written;
	int	nb_char[2];
}				t_convert;

#endif
