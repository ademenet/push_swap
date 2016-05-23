/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimization.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 10:26:01 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/23 10:55:01 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** We wan't to use the minimums moves: so if I know where is localized my node
** I could use either rotate or reverse rotate.
*/

int			ft_locateit(t_list *l)
{
	t_node	tmp;

	tmp = l->head;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
}
