/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 17:16:25 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/23 18:56:20 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** Here, we display whatever based on a list of moves.
*/

static void		ft_whichonetodisplay(int v)
{
	if (v == 0)
		ft_printf("sa");
	if (v == 1)
		ft_printf("sb");
	if (v == 2)
		ft_printf("ss");
	if (v == 3)
		ft_printf("pa");
	if (v == 4)
		ft_printf("pb");
	if (v == 5)
		ft_printf("ra");
	if (v == 6)
		ft_printf("rb");
	if (v == 7)
		ft_printf("rr");
	if (v == 8)
		ft_printf("rra");
	if (v == 9)
		ft_printf("rrb");
	if (v == 10)
		ft_printf("rrr");
}

void		ft_display(t_list *mv)
{
	t_node	*tmp;

	tmp = mv->head;
	while (tmp->next != NULL)
	{
		ft_whichonetodisplay(tmp->v);
		if (tmp->next != NULL)
			ft_printf(" ");
		tmp = tmp->next;
	}
}
