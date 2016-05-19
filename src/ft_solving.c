/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solving.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 10:45:20 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/19 11:08:37 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

#include "../test/unit_test.h"

void		ft_simplesort(t_list *la, t_list *lb)
{

}

void		ft_quicksort(t_list *la, t_list *lb)
{
	int		count;

	count = 0;
	while (count++ < la->len)
		ft_push_b(la, lb);
	// printf("ok\n"); print_la(la); getchar();

	ft_sort_a(la);
	// printf("K\n"); getchar();
	ft_sort_b(lb);
	// printf("Kk\n"); getchar();
	count = 0;
	while (count++ < la->len)
		ft_push_a(la, lb);

}

void		ft_sort_a(t_list *la)
{
	while (ft_issortasc(la))
	{
		// printf("%d > %d ?\n", la->head->v, la->head->next->v); getchar();
		if (la->head->v > la->head->next->v)
		{
			ft_swap_a(la);
			// printf("oui !\n"); getchar();
		}
		else
		{
			ft_rotate_a(la);
			// printf("non !\n"); getchar();
		}
	}
}

void		ft_sort_b(t_list *lb)
{
	while (ft_issortdes(lb))
	{
		if (lb->head->v < lb->head->prev->v)
			ft_swap_b(lb);
		else
			ft_revrotate_b(lb);
	}
}
