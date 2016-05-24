/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 13:47:22 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/24 18:17:11 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** These functions are our basic moves: reverse rotate, rotate, push a, push b
** and swap. With these we have to sort n random int arguments.
*/

t_list			*ft_revrotate(t_list *l, t_list *mv, int ab)
{
	t_node		*tmp;
	t_node		*tta;

	if (l->head == NULL || l->head == l->tail)
		return (mv);
	tmp = l->tail;
	tta = l->head;
	while (tta->next != tmp)
		tta = tta->next;
	l->tail = tta;
	l->tail->next = NULL;
	tmp->next = l->head;
	l->head = tmp;
	return (mv = ft_lstappend(mv, 8 + ab));
}

t_list			*ft_rotate(t_list *l, t_list *mv, int ab)
{
	t_node		*tmp;

	if (l->head == NULL || l->head == l->tail)
		return (mv);
	tmp = l->head;
	l->head = l->head->next;
	l->tail->next = tmp;
	l->tail = tmp;
	l->tail->next = NULL;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (mv = ft_lstappend(mv, 5 + ab));
}

t_list			*ft_push_a(t_list *la, t_list *lb, t_list *mv)
{
	t_node		*tmp;

	if (lb->head == NULL)
		return (mv);
	else
	{
		tmp = lb->head;
		lb->head = lb->head->next;
		if (la->head != NULL)
			tmp->next = la->head;
		la->head = tmp;
		if (la->tail == NULL)
		{
			la->tail = tmp;
			la->tail->next = NULL;
		}
		else if (lb->head == NULL)
			lb->tail = NULL;
		la->len++;
		lb->len--;
	}
	return (mv = ft_lstappend(mv, 3));
}

t_list			*ft_push_b(t_list *la, t_list *lb, t_list *mv)
{
	t_node		*tmp;

	if (la->head == NULL)
		return (mv);
	else
	{
		tmp = la->head;
		la->head = la->head->next;
		if (lb->head != NULL)
			tmp->next = lb->head;
		lb->head = tmp;
		if (lb->tail == NULL)
		{
			lb->tail = tmp;
			lb->tail->next = NULL;
		}
		else if (la->head == NULL)
			la->tail = NULL;
		lb->len++;
		la->len--;
	}
	return (mv = ft_lstappend(mv, 4));
}

t_list			*ft_swap(t_list *l, t_list *mv, int ab)
{
	int			tmp;

	if (l->head == NULL || l->head->next == NULL)
		return (mv);
	tmp = l->head->next->v;
	l->head->next->v = l->head->v;
	l->head->v = tmp;
	return (mv = ft_lstappend(mv, 0 + ab));
}
