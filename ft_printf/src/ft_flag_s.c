/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 18:20:57 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/13 14:31:31 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int			ft_handler_s(t_flag *f, va_list *ap)
{
	static int	mask_s[13] = {0, 0, 2, 1, 1, 2, 2, 2, 2, 2, 1, 2, 2};

	ft_apply_mask(f, mask_s);
	if (f->fla[10] == 1)
	{
		f->warg = va_arg(*ap, wchar_t*);
		ft_handler_char(f);
		return (0);
	}
	else
		f->arg = va_arg(*ap, char*);
	if (f->arg == 0)
		f->arg = "(null)";
	ft_handler_char(f);
	return (0);
}

int			ft_handler_ws(t_flag *f, va_list *ap)
{
	static int	mask_s[13] = {0, 0, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2};

	ft_apply_mask(f, mask_s);
	f->warg = va_arg(*ap, wchar_t*);
	ft_handler_char(f);
	return (0);
}
