/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dynamicalgorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 14:31:35 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/27 13:08:13 by ademenet         ###   ########.fr       */
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

t_list			*ft_dyn_selectmove(t_list *l, t_list *mv, int swt)
{
	t_node		*tmv;

	tmv = mv->head;
	while (tmv->next != mv->tail && mv->tail != mv->head)
		tmv = tmv->next;
	if (mv->tail->v == 0)
	{
		if (swt == 0)
			mv = ft_revrotate(l, mv, 0);
		else
			mv = ft_rotate(l, mv, 0);
	}
	else if (mv->tail->v == 5)
	{
		if (swt == 0)
			mv = ft_rotate(l, mv, 0);
		else
			mv = ft_swap(l, mv, 0);
	}
	else if (mv->tail->v == 8)
	{
		if (swt == 0)
			mv = ft_revrotate(l, mv, 0);
		else
			mv = ft_swap(l, mv, 0);
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

int				ft_dyn_explore(t_list *l, t_list *mv, t_list *sol, int index)
{
	static long	count = 0;
	int swt;

printf("Je lance dyn_explore la %ld (count)eme fois.\n", count);
	count++;
	swt = 0;
	if (count > ft_power(2, DP) - 1)
	{
DS("J'ai atteint la limite max, je sors.")
		return (0);
	}
	if (ft_issortasc(l) == 0 && index < DP + 1)
	{
DS("J'ai trouve une solution, je la copie.")
		sol = ft_dyn_copy(mv, sol);
	}
	while (index++ < DP + 1)
	{
DS("Je rentre dans ma boucle.")
DS("Je vais selectionner mon mouvement")
		mv = ft_dyn_selectmove(l, mv, swt);
ft_print_l(l, "la");
ft_print_l(mv, "mv");
ft_print_l(sol, "sol");
printf("count while | %ld |\n", count);
printf("index while | %d |\n", index);
DS("Je fais ma recursive.")
		swt = ft_dyn_explore(l, mv, sol, index);
DS("Je sors de ma recursive.")
DS("Je vais cleaner le dernier maillon et la liste")
		mv = ft_dyn_clean(l, mv);
	}
DS("je suis sorti de ma boucle")
getchar();
	return (1);
}

/*
** The master function, which call dyn_explore 3 times: one for each different
** start movements.
*/

t_list			*ft_dyn_resolve(t_list *l, t_list *mv)
{
	t_list		*sol;
	int			index;

	sol = ft_lstnew();
	index = 1;
	mv = ft_revrotate(l, mv, 0);
	DB(1)
	while (ft_dyn_explore(l, mv, sol, index));
	ft_print_l(l, "la");
	ft_print_l(mv, "mv");
	ft_print_l(sol, "sol");

	return (sol);
}
