/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 13:57:46 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/23 18:54:38 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int			main(int ac, char **av)
{
	t_list	*la;
	t_list	*lb;
	t_list	*mv;

	la = ft_parsing(ac, av);
	lb = ft_lstnew();
	mv = ft_lstnew();
	mv = ft_sortmin(la, lb, mv);
	printf("%d %p\n", mv->head->v, mv->tail);
	ft_display(mv);
	return (0);
}
