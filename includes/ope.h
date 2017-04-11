/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:52:32 by qmoreaux          #+#    #+#             */
/*   Updated: 2016/12/14 21:41:14 by qmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPE_H
# define OPE_H

# include "struct.h"
# include "convert.h"
# include "checkers.h"
# include "libft.h"
# include "ft_printf.h"

int	op_live(t_env *env, int num_player, unsigned int op_args[4], \
	unsigned char codage);
int	op_ld(t_env *env, int num_player, unsigned int op_args[4], \
	unsigned char codage);
int	op_st(t_env *env, int num_player, unsigned int op_args[4], \
	unsigned char codage);
int	op_add(t_env *env, int num_player, unsigned int op_args[4], \
	unsigned char codage);
int	op_sub(t_env *env, int num_player, unsigned int op_args[4], \
	unsigned char codage);
int	op_and(t_env *env, int num_player, unsigned int op_args[4], \
	unsigned char codage);
int	op_or(t_env *env, int num_player, unsigned int op_args[4], \
	unsigned char codage);
int	op_xor(t_env *env, int num_player, unsigned int op_args[4], \
	unsigned char codage);
int	op_zjmp(t_env *env, int num_player, unsigned int op_args[4], \
	unsigned char codage);
int	op_ldi(t_env *env, int num_player, unsigned int op_args[4], \
	unsigned char codage);
int	op_sti(t_env *env, int num_player, unsigned int op_args[4], \
	unsigned char codage);
int	op_fork(t_env *env, int num_player, unsigned int op_args[4], \
	unsigned char codage);
int	op_lld(t_env *env, int num_player, unsigned int op_args[4], \
	unsigned char codage);
int	op_lldi(t_env *env, int num_player, unsigned int op_args[4], \
	unsigned char codage);
int	op_lfork(t_env *env, int num_player, unsigned int op_args[4], \
	unsigned char codage);
int	op_aff(t_env *env, int num_player, unsigned int op_args[4], \
	unsigned char codage);

#endif
