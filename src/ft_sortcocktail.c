/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortcocktail.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 11:26:00 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/24 18:40:31 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** Like James Bond: vodka martini shaken, not stirred. This is cocktail/shaker
** sort.
*/

t_list		*ft_sortcocktail_a(t_list *l, t_list *mv)
{
	int		ttl;

	while (ft_issortasc(l))
	{
		ttl = l->tail->v;
		while (l->head->next->v != ttl)
		{
			if (l->head->v > l->head->next->v)
			{
				mv = ft_swap(l, mv, 0);
				print_la(l);
			}
			mv = ft_rotate(l, mv, 0);
			print_la(l);
		}
		printf("jai fini\n");
		ttl = l->tail->v;
		while (l->head->next->v != ttl)
		{
			if (l->head->v > l->head->next->v)
				mv = ft_swap(l, mv, 0);
			mv = ft_revrotate(l, mv, 0);
		}
	}
	return (mv);
}
