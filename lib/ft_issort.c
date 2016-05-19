/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 16:30:29 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/19 11:56:47 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int			ft_issortasc(t_list *l)
{
	t_node	*tmp;

	tmp = l->head;
	while (tmp->next != NULL)
	{
		if (tmp->v < tmp->next->v)
			tmp = tmp->next;
		else
			return (1);
	}
	return (0);
}

int			ft_issortdes(t_list *l)
{
	t_node	*tmp;

	tmp = l->head;
	while (tmp->next != NULL)
	{
		if (tmp->v > tmp->next->v)
			tmp = tmp->next;
		else
			return (1);
	}
	return (0);
}
