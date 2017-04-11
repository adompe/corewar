/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adompe <adompe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 20:22:59 by adompe            #+#    #+#             */
/*   Updated: 2017/02/10 16:49:12 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_op		g_op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0}
};

t_ins			*ft_init_new_ins(void)
{
	t_ins	*new_ins;

	new_ins = (t_ins *)malloc(sizeof(t_ins));
	new_ins->opcode = 0;
	new_ins->param = NULL;
	new_ins->coding_byte = 0;
	new_ins->size = 1;
	new_ins->label = NULL;
	return (new_ins);
}

t_ins			*ft_push_ins(t_asm *data, t_ins *new_ins)
{
	if (new_ins->opcode)
	{
		if (data->ins == NULL)
			data->ins = ft_lstnew(new_ins, sizeof(t_ins));
		else
			ft_lstappend(&(data->ins), ft_lstnew(new_ins, sizeof(t_ins)));
		if (new_ins)
			free(new_ins);
		new_ins = ft_init_new_ins();
	}
	return (new_ins);
}

void			ft_get_instruction(t_asm *data, int fd)
{
	t_ins	*new_ins;
	char	*line;
	int		gnl;

	new_ins = ft_init_new_ins();
	while ((gnl = get_next_line(fd, &line)))
	{
		if (ft_is_com(line))
			continue ;
		ft_get_ins_line(new_ins, line, g_op_tab);
		new_ins = ft_push_ins(data, new_ins);
	}
	if (gnl == -1)
		ft_error("Error: reading enter file\n");
	if (new_ins->label)
	{
		new_ins->size = 0;
		if (data->ins == NULL)
			data->ins = ft_lstnew(new_ins, sizeof(t_ins));
		else
			ft_lstappend(&(data->ins), ft_lstnew(new_ins, sizeof(t_ins)));
	}
}

void			ft_get_data(char **argv, t_asm *data)
{
	int		fd;

	if (!argv[1])
		return ;
	ft_check_s_file(argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_error("Error: file not found\n");
	ft_get_header(data, fd);
	ft_get_instruction(data, fd);
}
