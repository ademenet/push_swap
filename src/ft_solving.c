/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solving.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 10:45:20 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/19 17:00:41 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

#include "../test/unit_test.h"

int			ft_findmax(t_list *l)
{
	t_node	*tmp;
	int		max;

	tmp = l->head;
	while (tmp->next != NULL)
	{
		if (tmp->v > max)
			max = tmp->v;
		tmp = tmp->next;
	}
	printf("%d\n", max);
	return (max);
}

// void		ft_simplesort(t_list *la, t_list *lb)
// {
//
// }
//
// void		ft_quicksort(t_list *la, t_list *lb)
// {
// 	int		count;
//
// 	count = 0;
// 	while (count++ < la->len)
// 		ft_push_b(la, lb);
// 	// printf("ok\n"); print_la(la); getchar();
//
// 	ft_sort_a(la);
// 	// printf("K\n"); getchar();
// 	ft_sort_b(lb);
// 	// printf("Kk\n"); getchar();
// 	count = 0;
// 	while (count++ < la->len)
// 		ft_push_a(la, lb);
//
// }

void		ft_sort_a(t_list *la)
{
	int		max;

	max = ft_findmax(la);
	while (la->head->v != max)
	{
		fprintf(stderr, "%d != %d\n", la->head->v, max);
		ft_rotate(la);
	}
	while (ft_issortasc(la))
	{
		// printf("%d > %d ?\n", la->head->v, la->head->next->v); getchar();
		if (la->head->v > la->head->next->v)
		{
			ft_swap(la);
			// printf("oui !\n"); getchar();
		}
		else
		{
			ft_rotate(la);
		}
		print_la(la);
	}
}

// void		ft_sort_b(t_list *lb)
// {
// 	while (ft_issortdes(lb))
// 	{
// 		if (lb->head->v < lb->head->prev->v)
// 			ft_swap_b(lb);
// 		else
// 			ft_revrotate_b(lb);
// 	}
// }
