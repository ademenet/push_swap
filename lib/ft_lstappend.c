/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 17:27:21 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/16 18:34:19 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_list			*ft_lstappend(t_list *list, int v)
{
	t_node		*new;

	if (list != NULL)
	{
		if ((new = (t_node*)malloc(sizeof(t_node))) != NULL)
		{
			new->v = v;
			new->next = NULL;
			if (list->tail == NULL)
			{
				new->prev = NULL;
				list->head = new;
				list->tail = new;
			}
			else
			{
				list->tail->next = new;
				new->prev = list->tail;
				list->tail = new;
			}
			list->len++;
		}
	}
	return (list);
}