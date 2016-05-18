/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 15:36:02 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/13 14:58:47 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void				ft_bufset(void)
{
	int				n;

	n = 0;
	while (n < 4096)
	{
		g_buf[n] = '\0';
		n++;
	}
	g_i = 0;
}

void				ft_display(t_flag *f)
{
	f->ret += write(1, g_buf, g_i);
	ft_bufset();
}

void				ft_buf_null(t_flag *f)
{
	static char		str[6] = "(null)";
	int				i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_buf(str[i], f);
		i++;
	}
}

void				ft_buf(char c, t_flag *f)
{
	g_buf[g_i] = c;
	g_i++;
	if (g_i == 4096)
		ft_display(f);
}
