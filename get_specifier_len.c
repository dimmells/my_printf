/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_specifier_len.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 15:50:37 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/01/23 15:50:41 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_specifier_len(const char **format)
{
	char	*types;
	int		i;
	int		j;

	types = "sSpdDioOuUxXcC";
	i = 0;
	while ((*format)[i])
	{
		j = 0;
		while (types[j])
		{
			if ((*format)[i] == types[j])
				return (i + 1);
			j++;
		}
		i++;
	}
	return (0);
}
