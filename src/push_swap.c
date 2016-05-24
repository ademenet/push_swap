/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 13:57:46 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/24 19:00:47 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** This function allows us to check different conditions, such as if the list is
** already sorted and so on. It aims to solve basics cases before calling more
** complexes algorithms.
*/

t_list		*ft_precheck(t_list *la, t_list *lb, t_list *mv)
{
	if (ft_issortasc(la))
	{
		// mv = ft_sortmin(la, lb, mv);
		mv = ft_isreverse(la, mv);
		// mv = ft_sortcocktail_a(la, mv);
	}
	return (mv);
}

int			main(int ac, char **av)
{
	t_list	*la;
	t_list	*lb;
	t_list	*mv;

	if (ac == 1)
		return (0);
	la = ft_parsing(ac, av);
	lb = ft_lstnew();
	mv = ft_lstnew();
	mv = ft_precheck(la, lb, mv);
	ft_display(mv);
	return (0);
}
