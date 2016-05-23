/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 16:09:24 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/23 10:56:21 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** Because sometimes things goes wrong. Just say "Error" then exit the program.
*/

int			ft_error(void)
{
	write(2, "Error\n", 6);
	exit (1);
	return (0);
}
