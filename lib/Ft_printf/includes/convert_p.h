/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_p.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 14:35:20 by qmoreaux          #+#    #+#             */
/*   Updated: 2016/04/04 17:01:42 by qmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_P_H
# define CONVERT_P_H

# include "libft.h"
# include "struct.h"

void	ft_calc_size_ptr(unsigned long ptr, int *size);
int		ft_print_pointer_normal(void *ptr, t_print param);

#endif
