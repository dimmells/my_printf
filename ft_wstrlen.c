/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 13:10:17 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/02/21 18:44:07 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_wstrlen(wchar_t *wstr)
{
	int		i;
	int		len;

	len = 0;
	i = 0;
	while (wstr[i])
	{
		len += get_size_wchar_t((unsigned int)wstr[i]);
		i++;
	}
	return (len);
}
