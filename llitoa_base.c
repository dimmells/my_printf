/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llitoa_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 14:17:47 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/02/15 16:24:06 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char				correct_result(int number)
{
	if (number < 0)
	{
		number *= -1;
		printf("\ntest\n%d\n", number);
		if (number > 9)
			number = 15 - number + 1;
		else
			number = 15 - number + 1;
	}
	if (number > 9)
		return (number - 10 + 'a');
	else
		return (number + '0');
}

char				*swap(char *str)
{
	int				i;
	int				j;
	char			tmp;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
	return (str);
}

char				*llitoa_base(long long int number, int base)
{
	long long int	div;
	int				mod;
	int				i;
	char			result[32];

	if (base < 0)
		return (NULL);
	i = 0;
	while ((div = number / base) != 0)
	{
		mod = (int) number % base;
		result[i] = correct_result(mod);
		number = div;
		i++;
	}
	result[i] = correct_result(number);
	result[i + 1] = '\0';
	return (ft_strdup(swap(result)));
}

int		main(void)
{
	char	*res;

	res = llitoa_base(-2619, 16);
	printf("%s\n", res);
	ft_strdel(&res);
//	printf("%d\n", 7562 % 16);
	return (0);
}
