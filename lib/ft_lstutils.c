/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 16:20:47 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/27 10:59:35 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void		ft_lstdellastone(t_list *l)
{
	t_node	*tmp;
	t_node	*del;

	if (l->head != l->tail)
	{
		tmp = l->head;
		while (tmp->next != l->tail)
			tmp = tmp->next;
		del = l->tail;
		l->tail = tmp;
		l->tail->next = NULL;
		free (del);
		l->len--;
	}
}
