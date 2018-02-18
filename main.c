/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 12:23:23 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/02/18 15:22:10 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>
int		main(int ac, char **av)
{
	int	a;
	int	b;
	setlocale(LC_ALL, "");
//	ft_printf("%x\n", 100);
	a = 3;
	a = ft_printf("%5C", L'猫');
	b = printf("\n%5C\n", L'猫');
	printf("a = %d\nb = %d\n", a, b - 2);
//	ft_printf("%5.d %5.0d\n", 0, 0);
//	printf("%5.d %5.0d\n", 0, 0);
//	system("leaks a.out");
//	while (1);
	return (0);
}
