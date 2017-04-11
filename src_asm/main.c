/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adompe <adompe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 23:27:58 by adompe            #+#    #+#             */
/*   Updated: 2016/12/14 21:46:56 by qmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		ft_data_init(t_asm *data)
{
	data->header = (t_header *)malloc(sizeof(t_header));
	data->header->magic = COREWAR_EXEC_MAGIC;
	data->ins = NULL;
}

int				main(int argc, char **argv)
{
	t_asm *data;

	(void)argc;
	if (argc != 2)
		ft_error("Error\n");
	data = (t_asm *)malloc(sizeof(t_asm));
	ft_data_init(data);
	ft_get_data(argv, data);
	ft_check_ins(data);
	ft_get_prog_size(data);
	ft_print_bytecode(data, argv[1]);
	return (0);
}
