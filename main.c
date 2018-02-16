/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 12:23:23 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/02/16 15:07:30 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	int	a;
	int	b;

//	ft_printf("%+d\n", 0);
	a = ft_printf("%#.o %#.0o", 0, 0);
	b = printf("\n%#.o %#.0o\n", 0, 0);
	printf("a = %d\nb = %d\n", a, b - 2);
//	ft_printf("%5.d %5.0d\n", 0, 0);
//	printf("%5.d %5.0d\n", 0, 0);
//	system("leaks a.out");
//	while (1);
	return (0);
}
