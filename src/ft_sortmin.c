/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortmin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 10:45:20 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/23 11:27:51 by ademenet         ###   ########.fr       */
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
** Crunch of optimization. If my minimum value is more located in the fisrt part
** of my array then we use rotate (faster). Otherwise... reverse rotate. You got
** it!
*/

void		ft_bubble(t_list *l, int min)
{
	int		pos;

	pos = ft_locateit(l);
	if (pos > 2)
	{
		while (l->head->v != min)
			ft_rotate(l);
	}
	else if (pos < 2)
	{
		while (l->head->v != min)
			ft_revrotate(l);
	}
}

/*
** Now, I'm looking for the minimum then let it climb the list and push it in
** b-stack.
*/

void		ft_sortmin(t_list *la, t_list *lb)
{
	int		min;

	min = ft_findmin(la);
	while (ft_issortasc(la))
	{
		ft_bubble(la, min);
		ft_push_a(la, lb);
	}
}
