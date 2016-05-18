/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 18:21:21 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/18 10:40:19 by ademenet         ###   ########.fr       */
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
	if (tmp->next != NULL)
		tmp->next->prev = tmp->prev;
	tmp->prev->next = tmp->next;
	lb->head = tmp->prev;
	tmp->next = lb->tail;
	lb->tail->prev = tmp;
	lb->tail = tmp;
	lb->tail->prev = NULL;
}

void			ft_revrotate_a(t_list *la)
{
	t_node		*tmp;

	if (la->head == NULL || la->head == la->tail)
		return ;
	tmp = la->tail;
	tmp->prev->next = NULL;
	la->tail = tmp->prev;
	if (la->head->next != NULL)
		la->head->prev->next = tmp;
	tmp->prev = la->head->prev;
	la->head->prev = tmp;
	tmp->next = la->head;
	la->head = tmp;
}

void			ft_revrotate_b(t_list *lb)
{
	t_node		*tmp;

	if (lb->head == NULL || lb->head == lb->tail)
		return ;
	tmp = lb->tail;
	tmp->next->prev = NULL;
	lb->tail = tmp->next;
	if (lb->head->next != NULL)
		lb->head->next->prev = tmp;
	tmp->next = lb->head->next;
	lb->head->next = tmp;
	tmp->prev = lb->head;
	lb->head = tmp;
}
