/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 15:26:49 by qmoreaux          #+#    #+#             */
/*   Updated: 2016/12/14 21:43:13 by qmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_H
# define CONVERT_H

# include "struct.h"
# include "libft.h"
# include "op.h"

unsigned int	reg_to_int(char *reg);
char			*int_to_reg(unsigned int value);
int				memory_4_bytes_to_int(t_env *env, unsigned int value, \
	int num_player, int modulo);
int				memory_2_bytes_to_int(t_env *env, unsigned int value, \
	int num_player, int modulo);
int				position_4_bytes(t_env *env, unsigned int value, \
	int num_player, int modulo);
int				position_2_bytes(t_env *env, unsigned int value, \
	int num_player, int modulo);
unsigned char	*int_to_ind(unsigned int value);
int				direct_to_four_bytes(int value);
void			get_tmp_from_memory(t_env *env, char *tmp2, \
	unsigned int value, int i);

#endif
