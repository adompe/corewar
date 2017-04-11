/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_boux.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 14:35:20 by qmoreaux          #+#    #+#             */
/*   Updated: 2016/04/04 17:04:00 by qmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_BOUX_H
# define CONVERT_BOUX_H

# include <stdint.h>
# include <stddef.h>
# include <limits.h>
# include "libft.h"
# include "struct.h"

void			ft_len_uintmax(uintmax_t n, int base, int *size);
void			ft_len_uint(unsigned int n, int base, int *size);
void			ft_len_ulong(unsigned long n, int base, int *size);
void			ft_len_ulong_long(unsigned long long n, int base, int *size);
void			ft_len_uchar(unsigned char n, int base, int *size);
void			ft_len_ushort(unsigned short n, int base, int *size);
void			ft_len_usize(size_t n, int base, int *size);
int				ft_putnbr_uint(unsigned int nb, t_print param, int base);
int				ft_putnbr_unsigned_char(unsigned char nb, t_print param, \
		int base);
int				ft_putnbr_ushort(unsigned short nb, t_print param, int base);
int				ft_putnbr_ulong(unsigned long nb, t_print param, int base);
int				ft_putnbr_ulong_long(unsigned long long nb, t_print param, \
		int base);
int				ft_putnbr_uintmax(uintmax_t nb, t_print param, int base);
int				ft_putnbr_usize(size_t nb, t_print param, int base);

#endif
