/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 13:57:46 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/27 17:31:31 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** This function allows us to check different conditions, such as if the list is
** already sorted and so on. It aims to solve basics cases before calling more
** complexes algorithms.
*/

t_list		*ft_choose(t_list *la, t_list *lb)
{
	t_list	*mv1;
	t_list	*mv2;
	t_list	*mv3;
	t_list	*sol;

	mv1 = ft_lstnew();
	mv2 = ft_lstnew();
	mv3 = ft_lstnew();
	sol = NULL;
	if (ft_issortasc(la))
	{
		mv3 = ft_sortmin(la, lb, mv3);
		sol = mv3;
		if (la->len < 11)
			mv1 = ft_dyn_resolve(la);
		if (mv1->head != NULL && mv1->len < sol->len)
		{
			sol = mv1;
			ft_lstclear(mv3);
		}
		mv2 = ft_isreverse(la, mv2);
		if (mv2->head != NULL && mv2->len < sol->len)
		{
			sol = mv2;
			ft_lstclear(mv1);
			ft_lstclear(mv3);
		}
	}
	return (sol);
}

int			main(int ac, char **av)
{
	t_list	*la;
	t_list	*lb;
	t_list	*sol;

	if (ac == 1)
		return (0);
	la = ft_parsing(ac, av);
	lb = ft_lstnew();
	sol = ft_choose(la, lb);
	ft_display(sol);
	ft_lstclear(sol);
	ft_lstclear(la);
	ft_lstclear(lb);
	return (0);
}
