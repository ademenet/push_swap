/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 18:21:21 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/18 10:13:23 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void			ft_rotate_a(t_list *la)
{
	t_node		*tmp;

	if (la->head == NULL || la->head == la->tail)
		return ;
	tmp = la->head;
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	la->head = tmp->next;
	tmp->prev = la->tail;
	la->tail->next = tmp;
	la->tail = tmp;
	la->tail->next = NULL;
}

void			ft_rotate_b(t_list *lb)
{
	t_node		*tmp;

	if (lb->head == NULL || lb->head == lb->tail)
		return ;
	tmp = lb->head;
	tmp->next->prev = tmp->prev;
	tmp->prev->next = tmp->next;
	lb->head = tmp->prev;
	tmp->next = lb->tail;
	lb->tail->prev = tmp;
	lb->tail = tmp;
	lb->tail->prev = NULL;
}
