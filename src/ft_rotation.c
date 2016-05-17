/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 18:21:21 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/17 18:56:38 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void			ft_rotate_a(t_list *la)
{
	t_node		*tmp;

	tmp = la->head;
	la->head = tmp->next;
	la->head->prev = tmp->prev;
	tmp->prev->next = la->head;

	tmp->prev = la->tail;
	la->tail->next = tmp;
	la->tail = tmp;
	la->tail->next = NULL;
}
