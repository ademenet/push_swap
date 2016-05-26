/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonusdisplaystack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 14:59:20 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/26 12:36:07 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void		ft_print_la(t_list *l)
{
	t_node	*tmp;

	tmp = l->head;
	ft_printf("la |");
	while (tmp)
	{
		ft_printf("%7d", tmp->v);
		tmp = tmp->next;
	}
	ft_printf("|\n");
}

void		ft_print_lb(t_list *l)
{
	t_node	*tmp;

	tmp = l->head;
	ft_printf("lb |");
	while (tmp)
	{
		ft_printf("%7d", tmp->v);
		tmp = tmp->next;
	}
	ft_printf("|\n");
}
