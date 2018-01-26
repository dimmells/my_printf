/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 14:54:22 by dmelnyk           #+#    #+#             */
/*   Updated: 2017/11/05 17:32:12 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int					is_neg;
	unsigned long long	res;

	is_neg = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		is_neg = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	res = 0;
	while (str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	if (res > 9223372036854775807 && is_neg == -1)
		return (0);
	if (res > 9223372036854775807)
		return (-1);
	return ((int)res * is_neg);
}
