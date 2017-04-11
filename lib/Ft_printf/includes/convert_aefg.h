/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_aefg.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 15:06:06 by qmoreaux          #+#    #+#             */
/*   Updated: 2016/03/16 15:08:23 by qmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_AEFG_H
# define CONVERT_AEFG_H

# include "libft.h"
# include "struct.h"

int	ft_putnbr_double_classic(double n, t_print param);
int	ft_putnbr_long_double_classic(long double n, t_print param);
int	ft_putnbr_double_scientific(double n, t_print param);
int	ft_putnbr_long_double_scientific(long double n, t_print param);
int	ft_putnbr_double_hexa(double n, t_print param);
int	ft_putnbr_long_double_hexa(long double n, t_print param);
int	ft_putnbr_double_both(double n, t_print param);
int	ft_putnbr_long_double_both(long double n, t_print param);
#endif
