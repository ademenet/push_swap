/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimization.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 10:26:01 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/23 14:19:31 by ademenet         ###   ########.fr       */
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
