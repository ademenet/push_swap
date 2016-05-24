/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 13:57:46 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/24 14:48:52 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
	mv = ft_sortmin(la, lb, mv);
	ft_display(mv);
	fprintf(stderr, "\n");
	mv = ft_lstnew();
	mv = ft_sortcocktail_a(la, mv);
	ft_display(mv);
	return (0);
}
