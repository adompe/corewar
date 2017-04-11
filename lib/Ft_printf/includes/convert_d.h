/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_d.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 14:35:20 by qmoreaux          #+#    #+#             */
/*   Updated: 2016/04/04 14:07:05 by qmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_D_H
# define CONVERT_D_H

# include <stdint.h>
# include <stddef.h>
# include <limits.h>
# include <stdlib.h>
# include "libft.h"
# include "struct.h"

int				ft_putnbr_int(int nb, t_print param);
int				ft_putnbr_signed_char(signed char nb, t_print param);
int				ft_putnbr_short(short nb, t_print param);
int				ft_putnbr_long(long nb, t_print param);
int				ft_putnbr_long_long(long long nb, t_print param);
int				ft_putnbr_intmax(intmax_t nb, t_print param);
int				ft_putnbr_ptrdiff(ptrdiff_t nb, t_print param);
int				ft_putnbr_size(ssize_t nb, t_print param);

#endif
