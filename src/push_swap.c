/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alain <alain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 13:57:46 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/28 16:30:04 by alain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** This function allows us to check different conditions, such as if the list is
** already sorted and so on. It aims to solve basics cases before calling more
** complexes algorithms.
*/

t_list		*ft_choose(t_list *la, t_list *lb, t_list *sol)
{
	t_list	*cur;

	cur = ft_lstnew();
	if (ft_issortasc(la))
	{
		if (la->len < 20)
		{
			cur = ft_dyn_resolve(la);
			ft_dyn_copy(cur, sol);
			ft_lstdelallnodes(cur);
		}
		cur = ft_sortmin(la, lb, cur);
		if (sol->head != NULL && cur->len < sol->len)
			ft_dyn_copy(cur, sol);
		else if (sol->head == NULL)
			ft_dyn_copy(cur, sol);
		ft_lstdelallnodes(cur);
	}
	free (cur);
	return (sol);
}

int			main(int ac, char **av)
{
	t_list	*la;
	t_list	*lb;
	t_list	*sol;
	int		bonus;

	sol = ft_lstnew();
	bonus = 0;
	if (ac == 1)
		return (0);
	la = ft_parsing(ac, av, &bonus);
	lb = ft_lstnew();
	ft_choose(la, lb, sol);
	ft_display(sol, bonus);
	ft_lstclear(sol);
	ft_lstclear(la);
	ft_lstclear(lb);
	return (0);
}
