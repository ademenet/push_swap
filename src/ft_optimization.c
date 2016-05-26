/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimization.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 10:26:01 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/25 14:44:13 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** We wan't to use the minimums moves: so if I know where is localized my node
** I could use either rotate or reverse rotate. To do so, we return list length
** ratio / position.
*/

int			ft_locateit(t_list *l, int min)
{
	t_node	*tmp;
	int		index;

	tmp = l->head;
	index = 1;
	while (tmp->next != NULL && tmp->v != min)
	{
		index++;
		tmp = tmp->next;
	}
	return (l->len / index);
}

/*
** This function is useful only if my list is sorted but the minimum value is
** not set to list start.
*/

t_list		*ft_isreverse(t_list *l, t_list *mv)
{
	int		pos;
	int		min;

	min = ft_findmin(l);
	pos = ft_locateit(l, min);
	if (pos > 2)
	{
		while (ft_issortasc(l) == 1)
			mv = ft_revrotate(l, mv, 0);
	}
	else if (pos <= 2)
	{
		while (ft_issortasc(l) == 1)
			mv = ft_rotate(l, mv, 0);
	}
	return (mv);
}

// t_list		*ft_simplesort(t_list *l, t_list *mv)
// {
// 	t_node	*tmp;
//
// 	tmp = l->head;
// 	while (ft_issortasc(l))
// 	{
// 		if (tmp->v > tmp->next->v)
//
// 	}
// }
