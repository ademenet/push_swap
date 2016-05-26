/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortcocktail.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 11:26:00 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/26 17:10:37 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** Like James Bond: vodka martini shaken, not stirred. This is cocktail/shaker
** sort.
*/

t_list		*ft_sortcocktail_a(t_list *l, t_list *mv)
{
	int		size;
	int		len;

	int		ttl;

	len = l->len;
	size = 0;
	fprintf(stderr, "len == %d", len);
	while (ft_issortasc(l))
	{
		while (size <= len || ft_issortasc(l))
		{
			mv = ft_swap(l, mv, 0);
			if (l->head->v < l->head->next->v)
			{
				mv = ft_rotate(l, mv, 0);
				ft_print_la(l);
			}
			ft_print_la(l);
			size++;
		}
		while (size >= 0 || ft_issortasc(l))
		{
			mv = ft_swap(l, mv, 0);
			if (l->head->v < l->head->next->v)
				mv = ft_revrotate(l, mv, 0);
		}
		len--;
	}
	return (mv);
}
