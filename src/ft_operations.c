/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 13:47:22 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/17 14:07:53 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

void		ft_swap_a(t_list la)
{
	int		tmp;

	if (la->head->next == NULL)
		return ;
	tmp = la->head->next->v;
	la->head->next->v = la->head->v;
	la->head->v = tmp;
}

void		ft_swap_b(t_list lb)
{
	int		tmp;

	if (lb->head->prev == NULL)
		return ;
	tmp = lb->head->prev->v;
	lb->head->prev->v = lb->head->v;
	lb->head->v = tmp;
}
