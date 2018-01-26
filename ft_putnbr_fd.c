/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 17:54:15 by dmelnyk           #+#    #+#             */
/*   Updated: 2017/11/05 16:02:32 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int		del;
	long int		n1;
	size_t			k;

	del = 10;
	k = 1;
	n1 = (long int)n;
	if (n < 0)
	{
		n1 = n1 * -1;
		ft_putchar_fd('-', fd);
	}
	while (n1 / del != 0 && k++)
		del *= 10;
	while (del != 1)
	{
		ft_putchar_fd((n1 / (del /= 10)) + 48, fd);
		n1 %= del;
	}
}
