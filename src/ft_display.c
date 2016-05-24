/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 17:16:25 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/24 11:13:01 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** Here, we display whatever based on a list of moves.
*/

const static char	*g_push_swap_moves[11] = { "sa", "sb", "ss", "pa", "pb",
	"ra", "rb", "rr", "rra", "rrb", "rrr" };

void				ft_display(t_list *mv)
{
	t_node			*tmp;
	int				len;

	tmp = mv->head;
	len = 0;
	while (tmp->next != NULL)
	{
		ft_printf(g_push_swap_moves[tmp->v]);
		if (len < mv->len - 2)
			ft_printf(" ");
		tmp = tmp->next;
		len++;
	}
}
