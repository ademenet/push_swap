/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 13:47:22 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/19 12:09:02 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// void		ft_push_a(t_list *la, t_list *lb)
// {
// 	if (lb->head == NULL)
// 		return ;
// 	else
// 	{
// 		la->head = lb->head;
// 		if (la->tail == NULL)
// 			la->tail = lb->head;
// 		if (lb->head->next != NULL)
// 			lb->head = lb->head->next;
// 		else
// 		{
// 			lb->head = NULL;
// 			lb->tail = NULL;
// 		}
// 		la->len++;
// 		lb->len--;
// 	}
// 	ft_printf("pa\n");
// }

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
		else
			la->tail = NULL;
		lb->len++;
		la->len--;
	}
	ft_printf("pb\n");
}

void		ft_swap(t_list *l)
{
	int		tmp;

	if (l->head == NULL || l->head->next == NULL)
		return ;
	tmp = l->head->next->v;
	l->head->next->v = l->head->v;
	l->head->v = tmp;
	ft_printf("sa\n");
}
