/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 13:58:05 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/19 11:24:02 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** This function check if the arg is an integer.
*/

int				ft_isunique(t_list *list, int v)
{
	t_node		*tmp;
	int			count;

	tmp = list->head;
	count = 0;
	if (tmp)
	{
		while (tmp->next != NULL)
		{
			if (v == tmp->v)
				ft_error();
			tmp = tmp->next;
		}
	}
	return (v);
}

int				ft_isint(t_list *list, char *av)
{
	long		v;

	v = ft_atoi(av);
	return (IS_INT(v) ? ft_isunique(list, (int)v) : ft_error());
}

int				ft_check(t_list *list, char *av)
{
	return (ft_strisdigit(av) ? ft_isint(list, av) : ft_error());
}

t_list			*ft_parsing(int ac, char **av)
{
	t_list		*la;
	int			v;
	int			i;

	la = ft_lstnew();
	i = 1;
	while (i < ac)
	{
		v = ft_check(la, av[i]);
		la = ft_lstappend(la, v);
		i++;
	}
	return (la);
}
