/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dynamicalgorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 14:31:35 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/27 16:35:02 by ademenet         ###   ########.fr       */
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
	if (mv->tail->v == 0)
		ft_swap(l, mv, -1);
	else if (mv->tail->v == 5)
		ft_revrotate(l, mv, -1);
	else if (mv->tail->v == 8)
		ft_rotate(l, mv, -1);
	ft_lstdellastone(mv);
	return (mv);
}

/*
** Here we select the move according to our previous one and the last one.
*/

t_list			*ft_dyn_selectmove(t_list *l, t_list *mv, int swt)
{
	t_node		*tmv;

	tmv = mv->head;
	while (tmv->next != mv->tail && mv->tail != mv->head)
		tmv = tmv->next;
	if (mv->tail->v == 0)
		swt == 0 ? ft_revrotate(l, mv, 0) : ft_rotate(l, mv, 0);
	else if (mv->tail->v == 5)
		swt == 0 ? ft_rotate(l, mv, 0) : ft_swap(l, mv, 0);
	else if (mv->tail->v == 8)
		swt == 0 ? ft_revrotate(l, mv, 0) : ft_swap(l, mv, 0);
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
		ft_lstdelallnodes(sol);
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

int				ft_dyn_explore(t_list *l, t_list *mv, t_list *sol, int index)
{
	static long	count = 0;
	int			swt;

	count++;
	swt = 0;
	if (count > ft_power(2, DP) - 1)
	{
		count = 0;
		return (0);
	}
	if (ft_issortasc(l) == 0)
		sol = ft_dyn_copy(mv, sol);
	while (index++ < DP + 1)
	{
		mv = ft_dyn_selectmove(l, mv, swt);
		swt = ft_dyn_explore(l, mv, sol, index);
		mv = ft_dyn_clean(l, mv);
	}
	return (1);
}

/*
** The master function, which call dyn_explore 3 times: one for each different
** start movements.
*/

t_list			*ft_dyn_resolve(t_list *l)
{
	t_list		*sol;
	t_list		*mv1;
	t_list		*mv2;
	t_list		*mv3;
	int			index;
	int ret;

	mv1 = ft_lstnew();
	mv2 = ft_lstnew();
	mv3 = ft_lstnew();
	sol = ft_lstnew();
	index = 1;
	mv1 = ft_swap(l, mv1, 0);
	ft_dyn_explore(l, mv1, sol, index);
	ft_swap(l, mv1, 0);
	mv2 = ft_rotate(l, mv2, 0);
	ret = ft_dyn_explore(l, mv2, sol, index);
	ft_revrotate(l, mv2, 0);
	mv3 = ft_revrotate(l, mv3, 0);
	ret = ft_dyn_explore(l, mv3, sol, index);
	ft_rotate(l, mv2, 0);
	return (sol);
}
