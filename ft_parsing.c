/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 13:58:05 by ademenet          #+#    #+#             */
/*   Updated: 2016/04/26 14:30:36 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
