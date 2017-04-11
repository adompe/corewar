/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adompe <adompe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 15:37:34 by adompe            #+#    #+#             */
/*   Updated: 2016/09/26 15:37:36 by adompe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*current;
	t_list	*aux;

	if (alst && *alst)
	{
		current = *alst;
		while (current)
		{
			(*del)(current->content, current->content_size);
			aux = current->next;
			free(current);
			current = aux;
		}
		*alst = NULL;
	}
}
