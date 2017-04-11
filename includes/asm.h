/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adompe <adompe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 14:22:33 by adompe            #+#    #+#             */
/*   Updated: 2016/12/14 21:46:30 by qmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "get_next_line.h"
# include "op.h"
# include <fcntl.h>

typedef	struct	s_op
{
	char			*name;
	int				nb_param;
	int				param[3];
	char			opcode;
	int				cycle;
	char			*full_name;
	int				coding_byte;
	int				two_bytes;
}				t_op;

typedef	struct	s_param
{
	unsigned int	value;
	char			*label;
	int				type;
}				t_param;

typedef struct	s_ins
{
	t_list			*label;
	char			opcode;
	char			coding_byte;
	t_op			op_code;
	t_bool			two_bytes;
	t_list			*param;
	unsigned int	size;
}				t_ins;

typedef struct	s_asm
{
	t_header		*header;
	t_list			*ins;
	t_list			*label_adress;
}				t_asm;

void			ft_get_data(char **argv, t_asm *data);
void			ft_get_ins_line(t_ins *new_ins, char *line, t_op t_op_tab[17]);
t_bool			ft_get_opcode(t_ins *new_ins, char *str, t_op op);
void			ft_get_header(t_asm *data, int fd);
void			ft_get_ins_param(t_ins	*ins, char **tab);
t_bool			ft_valid_label_char(char c, char *label_chars);

char			**ft_split_line(char *line);
void			ft_get_label_param(t_param *p, char *str);
void			ft_get_reg_param(t_param *p, char *str);
void			ft_get_num_param(t_param *p, char *str);

void			ft_check_ins(t_asm *data);
void			ft_check_param(t_ins *ins, t_op opcode);

void			ft_print_bytecode(t_asm *data, char *name);
void			ft_print_ins(t_asm *data, int fd);
void			ft_print_uint_hex(int fd, unsigned int nb, char l);
void			ft_get_prog_size(t_asm *data);

void			ft_error(char *str);

void			debug(t_asm *data);

void			ft_check_s_file(char *str);
t_bool			ft_is_com(char *str);

#endif
