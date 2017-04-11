/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 21:57:54 by rfernand          #+#    #+#             */
/*   Updated: 2017/02/08 16:42:58 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "libft.h"
#include <stdlib.h>

int				start_init(t_joueur **players, int n, int fd)
{
	players[n]->name = get_name(fd);
	if (!players[n]->name[0])
		return (0);
	players[n]->comment = get_comment(fd);
	if (!players[n]->comment)
		return (0);
	players[n]->cycle = 0;
	players[n]->nb_live_current_cycle = 0;
	players[n]->last_live = 0;
	players[n]->nb_live_total = 0;
	players[0]->instance[n]->carry = 0;
	players[0]->instance[n]->is_alive = 1;
	players[0]->instance[n]->last_op_live = 0;
	players[0]->instance[n]->cycle = 0;
	players[0]->instance[n]->save_op =
		(unsigned char *)malloc(12 * sizeof(unsigned char));
	ft_bzero(players[0]->instance[n]->save_op, 12);
	return (1);
}

unsigned char	*start_recup_players(int *fd)
{
	unsigned char *memory;

	memory = (unsigned char *)malloc((MEM_SIZE) * sizeof(unsigned char));
	ft_bzero(memory, MEM_SIZE);
	*fd = 0;
	return (memory);
}

int				*reset_recup(int *in, int *fd, unsigned char *str)
{
	in[0]++;
	in[1]++;
	close(*fd);
	free(str);
	return (in);
}
