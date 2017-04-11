/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adompe <adompe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 15:38:21 by adompe            #+#    #+#             */
/*   Updated: 2016/09/26 15:38:28 by adompe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*crt;

	crt = (*f)(lst);
	if (crt == NULL)
		return (NULL);
	new = crt;
	lst = lst->next;
	while (lst)
	{
		crt->next = (*f)(lst);
		if (crt->next == NULL)
			return (NULL);
		crt = crt->next;
		lst = lst->next;
	}
	return (new);
}
