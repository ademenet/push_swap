/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 15:01:24 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/10 17:35:16 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int			ft_wcharlen(wchar_t wchar)
{
	if (wchar <= 0x7f)
		return (1);
	else if (wchar <= 0x7ff)
		return (2);
	else if (wchar <= 0xffff)
		return (3);
	else
		return (4);
}
