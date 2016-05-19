/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 13:47:22 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/19 14:19:57 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void			ft_revrotate(t_list *l)
{
	t_node		*tmp;
	t_node		*tta;

	if (l->head == NULL || l->head == l->tail)
		return ;
	tmp = l->tail;
	tta = l->head;
	while (tta->next != tmp)
		tta = tta->next;
	l->tail = tta;
	l->tail->next = NULL;
	tmp->next = l->head;
	l->head = tmp;
	// ft_printf("rra\n");
}


void			ft_rotate(t_list *l)
{
	t_node		*tmp;

	if (l->head == NULL || l->head == l->tail)
		return ;
	tmp = l->head;
	l->head = l->head->next;
	l->tail->next = tmp;
	l->tail = tmp;
	l->tail->next = NULL;
	// ft_printf("ra\n");
}

void		ft_push_a(t_list *la, t_list *lb)
{
	t_node	*tmp;

	if (lb->head == NULL)
		return ;
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
	// ft_printf("pa\n");
}

void		ft_push_b(t_list *la, t_list *lb)
{
	t_node	*tmp;

	if (la->head == NULL)
		return ;
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
	// ft_printf("pb\n");
}

void		ft_swap(t_list *l)
{
	int		tmp;

	if (l->head == NULL || l->head->next == NULL)
		return ;
	tmp = l->head->next->v;
	l->head->next->v = l->head->v;
	l->head->v = tmp;
	// ft_printf("sa\n");
}
