/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 13:57:46 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/23 16:25:12 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int			main(int ac, char **av)
{
	t_list	*la;
	t_list	*lb;

	la = ft_parsing(ac, av);
	lb = ft_lstnew();
	ft_sortmin(la, lb);	
	return (0);
}
