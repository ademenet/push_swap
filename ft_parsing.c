/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alain <alain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 13:58:05 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/15 17:32:08 by alain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.a"

/*
** This function check if the arg is an integer.
*/

int			ft_is_correct()
{
	if (ft_isdigit(av) && av < INT_MAX && av > INT_MIN)
	return (1);
}

int			*ft_parsing(int ac, char **av)
{
	int		*pile_a;
	int		i;

	pile_a = (int*)malloc(sizeof(int) * (ac - 1));
	i = 1;
	while (i <= ac)
	{
		pile_a[i - 1] = ft_atoi(av[i]);
	}
	return (pile_a);
}
