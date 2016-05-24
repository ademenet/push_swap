/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortcocktail.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 11:26:00 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/24 14:41:43 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** Like James Bond: vodka martini shaken, not stirred. This is cocktail/shaker
** sort.
*/

t_list		*ft_sortcocktail_a(t_list *l, t_list *mv)
{
	t_node	*tmp;
	t_node	*ttl;

	tmp = l->head;
	fprintf(stderr, "BONJOUR\n");
	while (ft_isascending(tmp->v, tmp->next->v))
	{
		ttl = l->tail;
		fprintf(stderr, "ttl->v1 == %d\n", ttl->v);
		while (tmp->next != ttl)
		{
			fprintf(stderr, "[1]\n");
			fprintf(stderr, "[2a] tmp->v == %d & %p\n", tmp->v, tmp->next);
			mv = ft_rotate(l, mv, 0);
			fprintf(stderr, "[2b] tmp->v == %d & %p\n", tmp->v, tmp->next);
			if (tmp->v > tmp->next->v)
			{
				fprintf(stderr, "[3]\n");
				mv = ft_swap(l, mv, 0);
				fprintf(stderr, "[4]\n");
			}
			fprintf(stderr, "ttl->v2 == %d\n", ttl->v);
		}
		ttl = l->tail;
		while (tmp->next != ttl)
		{
			mv = ft_revrotate(l, mv, 0);
			if (tmp->v > tmp->next->v)
				mv = ft_swap(l, mv, 0);
			fprintf(stderr, "ttl->v3 == %d\n", ttl->v);
		}
	}
	return (mv);
}
