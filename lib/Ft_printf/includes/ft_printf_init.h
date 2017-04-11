/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 21:41:27 by qmoreaux          #+#    #+#             */
/*   Updated: 2016/05/21 16:57:55 by qmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INIT_H
# define FT_PRINTF_INIT_H

# include <stdlib.h>
# include "struct.h"

void	init_norme_printf(t_norme *norme);
void	ft_init(t_print *param);
void	init_tab(int tab[8]);

#endif
