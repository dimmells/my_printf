/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 16:08:14 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/02/21 12:54:15 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_putwstr(wchar_t *wstr)
{
	int		i;
	int		len;

	len = 0;
	i = 0;
	while (wstr[i])
	{
		len += ft_putwchar_t((unsigned int)wstr[i]);
		i++;
	}
	return (len);
}
