/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 12:23:23 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/02/21 13:58:08 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>
#include <unistd.h>
int			main(int ac, char **av)
{
	int		a;
	int		b;
	void	*test;
	setlocale(LC_ALL, "");
//	ft_printf("%x\n", 100);
	test = (void*)123;
//	ft_printf("%#o\n", 0);
	a = ft_printf("%15.4d", 42);
	b = printf("\n%15.4d\n", 42);
	printf("a = %d\nb = %d\n", a, b - 2);
//	ft_printf("%5.d %5.0d\n", 0, 0);
//	printf("%5.d %5.0d\n", 0, 0);
//	system("leaks a.out");
//	while (1);
	return (0);
}
