/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 13:58:05 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/16 18:58:32 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** This function check if the arg is an integer.
*/

int				ft_isunique(t_list *list, int v)
{
	t_node		*tmp;

	tmp = list->head;
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
	int			v;

	v = (int)ft_atoi(av);
	return (IS_INT(v) ? ft_isunique(list, v) : ft_error());
}

int				ft_check(t_list *list, char *av)
{
	return (ft_strisdigit(av) ? ft_isint(list, av) : ft_error());
}

t_list			*ft_parsing(int ac, char **av)
{
	t_list		*list;
	int			v;
	int			i;

	list = ft_lstnew();
	i = 1;
	while (i < ac)
	{
		v = ft_check(list, av[i]);
		list = ft_lstappend(list, v);
		i++;
	}
	return (list);
}
