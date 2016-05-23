/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortmin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 10:45:20 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/23 10:54:10 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** This sortmin alogrithm is a kind of bubble sort. We are looking for the
** minimum value and we rotate it up so as to push it in our second stack.
** With some magic crunch of codes, it gives us an sorted array.
*/

/*
** Finding the minimum. Not a big deal but it could cost O(n) operations.
*/

int			ft_findmin(t_list *l)
{
	t_node	*tmp;
	int		min;

	tmp = l->head;
	min = tmp->v;
	while (tmp->next != NULL)
	{
		if (tmp->v < min)
			min = tmp->v;
		tmp = tmp->next;
	}
	return (min);
}

/*
** Now, I'm looking for the minimum then let it climb the list and push it in
** b-stack.
*/

void		ft_sortmin(t_list *l)
{
	int		min;

	min = ft_findmin(l);
	while (l->head->v != min)
		ft_rotate(l);
	while (ft_issortasc(l))
	{
		// printf("%d > %d ?\n", la->head->v, la->head->next->v); getchar();
		if (l->head->v > la->head->next->v)
		{
			ft_swap(l);
			// printf("oui !\n"); getchar();
		}
		else
		{
			ft_rotate(l);
		}
		print_la(l);
	}
}
