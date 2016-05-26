/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dynamicalgorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 14:31:35 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/26 12:22:52 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** Let's get funky!
*/

je cree une nouvelle liste avec le premier moves
je cree deux variable :
une pour tester
une pour stocker la solution
je passe les pointeurs afin de garder cela en memoire quans la recursion sera finie
si la ( fonction recursive ) retourne 1 jai ma solution
sinon je nai pas trouve de solution sur lensemble de mon arbre

int		fonction recursive :
si jai depasse ma valeur limite
	je retourne 1
je teste si le move classe par ordre croissant
	oui
		je stocke la solution
jajoute un mouvement tant que je nai pas atteint la valeur limite de tous mes coups et que je ne suis pas arrive
plus loin que la 6eme branche de mon arbre
	si javais

t_list		*ft_dyn_copy(t_list *mv, t_list *sol)
{
	t_node	*tmp;

	tmp = mv->head;
	while (tmp)
	{
		ft_lstappend(sol, tmp->v);
		tmp = tmp->next;
	}
	return (sol);
}

int			ft_dyn_explore(t_list *l, t_list *mv, t_list *sol, long count)
{
	int		index;

	if (count > ft_power(2, DP) - 1)
		return (0);
	if (!(ft_issortasc(l)) && index < DP + 1)
		sol = ft_dyn_copy(mv, sol);
	while (index < DP + 1)
	{
		if (ft_dyn_explore())
		{
			move selon parent
				si jai toujours le move en memoire, je regarde le parent et le move que je viens de faire, jefface le precedent move et je fais lautre
		}
		index++;
	}
	fonction qui restore ma stack (fait la fonction inverse)
	return (1);
	// test->nb = 0;
	// if (count < vmax)
	// 	ft_dyn_explore(vmax, count++, test, good);

}

t_list		*ft_dyn_resolve(t_list *l, t_list *mv)
{
	t_list	*sol;
	long	count;

	ft_dynalgo_explore(l, mv, sol, count);
	return (sol);
}
