/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 13:47:22 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/17 14:32:25 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void		ft_push_a(t_list *la, t_list *lb)
{
	if (lb->head == NULL)
		return ;
	else
	{
		la->head = lb->head;
		if (lb->head->prev != NULL)
			lb->head = lb->head->prev;
		else
		{
			lb->head = NULL;
			lb->tail = NULL;
		}
	}
}

void		ft_push_b(t_list *la, t_list *lb)
{
	if (la->head == NULL)
		return ;
	else
	{
		lb->head = la->head;
		if (la->head->next != NULL)
			la->head = la->head->next;
		else
		{
			la->head = NULL;
			la->tail = NULL;
		}
	}
}

void		ft_swap_a(t_list *la)
{
	int		tmp;

	if (la->head->next == NULL || !la)
		return ;
	tmp = la->head->next->v;
	la->head->next->v = la->head->v;
	la->head->v = tmp;
}

void		ft_swap_b(t_list *lb)
{
	int		tmp;

	if (lb->head->prev == NULL || !lb)
		return ;
	tmp = lb->head->prev->v;
	lb->head->prev->v = lb->head->v;
	lb->head->v = tmp;
}
