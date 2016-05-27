/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dynamicalgorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 14:31:35 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/27 10:52:23 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** Let's get funky! Recursive dynamic programing - in fact, backtracking.
*/

/*
** We need to clean each time we are coming back. We delete the last move and
** put the list order back.
*/

t_list			*ft_dyn_clean(t_list *l, t_list *mv)
{
	DB(40)
	if (mv->tail->v == 0)
		ft_swap(l, mv, -1);
	else if (mv->tail->v == 5)
		ft_revrotate(l, mv, -1);
	else if (mv->tail->v == 8)
		ft_rotate(l, mv, -1);
	ft_print_l(l, "la");
	ft_lstdellastone(mv);
	ft_print_l(mv, "mv");
	return (mv);
}

/*
** Here we select the move according to our previous one and the last one.
*/

t_list			*ft_dyn_selectmove(t_list *l, t_list *mv)
{
	t_node		*tmv;

	DS("selectmove")
	tmv = mv->head;
	while (tmv->next != mv->tail && mv->tail != mv->head) // tmv = avant-dernier
		tmv = tmv->next;
	printf("tmv->v == (%d)\n", tmv->v);
	if (mv->tail->v == 0)
	{
		DS("j'ai fait un swap")
		if (tmv->v)
		{
			DS("du coup, je fais un rotate")
			mv = ft_rotate(l, mv, 0); // ra
		}
		else
		{
			DS("du coup, je fais un revrotate")
			mv = ft_revrotate(l, mv, 0); // rra
		}
	}
	else if (mv->tail->v == 5)
	{
		DS("j'ai fait un rotate")
		if (tmv->v)
		{
			DS("du coup, je refais un rotate")
			mv = ft_rotate(l, mv, 0); // ra
		}
		else
		{
			DS("du coup, je fais un swap")
			mv = ft_swap(l, mv, 0); // rra
		}
	}
	else if (mv->tail->v == 8)
	{
		DS("j'ai fait un revrotate")
		if (tmv->v)
		{
			DS("du coup, je fais un revrotate again")
			mv = ft_revrotate(l, mv, 0); // ra
		}
		else
		{
			DS("du coup, je fais un swap")
			mv = ft_swap(l, mv, 0); // rra
		}
	}
	// if ((tmv->v == 0 && mv->tail->v == 5) || mv->head->next == NULL) // sa puis ra
	// {
	// 	DB(30)
	// 	mv = ft_revrotate(l, mv, 0); // rra
	// }
	// else if (tmv->v == 0 && mv->tail->v == 8) // sa puis rra
	// {
	// 	DB(31)
	// 	mv = ft_rotate(l, mv, 0); // ra
	// }
	// else if ((tmv->v == 5 && mv->tail->v == 0) || mv->head->next == NULL) // ra puis sa
	// {
	// 	DB(32)
	// 	mv = ft_rotate(l, mv, 0); // ra
	// }
	// else if (tmv->v == 5 && mv->tail->v == 5) // ra puis ra
	// {
	// 	DB(33)
	// 	mv = ft_swap(l, mv, 0); // sa
	// }
	// else if ((tmv->v == 8 && mv->tail->v == 0) || mv->head->next == NULL) // rra puis sa
	// {
	// 	DB(34)
	// 	mv = ft_revrotate(l, mv, 0); // rra
	// }
	// else if (tmv->v == 8 && mv->tail->v == 8) // rra puis sa
	// {
	// 	DB(35)
	// 	mv = ft_swap(l, mv, 0); // sa
	// }
	return (mv);
}

/*
** We check if the solution is better <=> shorter than our previous, or if it's
** first solution, we stock it.
*/

t_list			*ft_dyn_copy(t_list *mv, t_list *sol)
{
	t_node		*tmp;

	tmp = mv->head;
	if (mv->len < sol->len || sol->len == 0)
	{
		while (tmp)
		{
			ft_lstappend(sol, tmp->v);
			tmp = tmp->next;
		}
	}
	return (sol);
}

/*
** This recursive function explore all the possibilities. It stops when we reach
** the maximum value (2^DP - 1). We call dyn_copy each times we find a solution.
*/

int				ft_dyn_explore(t_list *l, t_list *mv, t_list *sol, long count)
{
	static int	index = 0;

	DB(2)
	count++;
	if (count > ft_power(2, DP) - 1)
		return (0);
	if (ft_issortasc(l) == 0 && index < DP + 1)
		sol = ft_dyn_copy(mv, sol);
	while (index++ < DP + 1)
	{
		DB(3)
		mv = ft_dyn_selectmove(l, mv);
		ft_print_l(l, "la");
		ft_print_l(mv, "mv");
		ft_print_l(sol, "sol");
		printf("count | %ld |\n", count);
		printf("index | %d |\n", index);
		DB(4)
		ft_dyn_explore(l, mv, sol, count);
		DB(5)
	}
	DB(6)
	mv = ft_dyn_clean(l, mv);
	index--;
	DB(7)
	return (1);
}

/*
** The master function, which call dyn_explore 3 times: one for each different
** start movements.
*/

t_list			*ft_dyn_resolve(t_list *l, t_list *mv)
{
	t_list		*sol;
	long		count;

	sol = ft_lstnew();
	count = 0;
	mv = ft_swap(l, mv, 0);
	DB(1)
	ft_dyn_explore(l, mv, sol, count);

	ft_print_l(l, "la");
	ft_print_l(mv, "mv");
	ft_print_l(sol, "sol");

	return (sol);
}
