/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:23:27 by rfernand          #+#    #+#             */
/*   Updated: 2016/12/15 13:20:43 by qmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "libft.h"

int				flag_n(t_joueur **players, int *in, char **argv, int argc)
{
	int i;

	i = 0;
	if (!(ft_strcmp(argv[in[0]], "-n")))
	{
		if (argc - in[0] - 1 < 2)
			return (0);
		players[in[1]]->num_joueur = ft_atoi(argv[in[0] + 1]);
		while (i < in[1])
		{
			if (players[in[1]]->num_joueur == players[i]->num_joueur)
				return (0);
			i++;
		}
		in[0] += 2;
	}
	else
		check_num_available(players, in[1]);
	return (1);
}
