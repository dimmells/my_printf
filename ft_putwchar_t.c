/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_t.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 13:31:05 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/02/17 15:30:45 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	six_byte(wchar_t w)
{
	ft_putchar(w>>30 | 0xFC);
	ft_putchar(w>>(24 & 63) | 0x80);
	ft_putchar(w>>(18 & 63) | 0x80);
	ft_putchar(w>>(12 & 63) | 0x80);
	ft_putchar(w>>(6 & 63) | 0x80);
	ft_putchar((w&63) | 0x80);
}

static void	five_byte(wchar_t w)
{
	ft_putchar(w>>24 | 0xF8);
	ft_putchar(w>>(18 & 63) | 0x80);
	ft_putchar(w>>(12 & 63) | 0x80);
	ft_putchar(w>>(6 & 63) | 0x80);
	ft_putchar((w&63) | 0x80);
}

static void	four_byte(wchar_t w)
{
	ft_putchar(w>>18 | 0xF0);
	ft_putchar(w>>(12 & 63) | 0x80);
	ft_putchar(w>>(6 & 63) | 0x80);
	ft_putchar((w&63) | 0x80);
}

static void	tree_byte(wchar_t w)
{
	ft_putchar(w>>12 | 0xE0);
	ft_putchar(w>>(6 & 63) | 0x80);
	ft_putchar((w&63) | 0x80);
}

void		ft_putwchar_t(wchar_t w)
{

	if(w<128)
		ft_putchar(w);
	else if(w<2048)
	{
		ft_putchar(w>>6 | 0xC0);
		ft_putchar((w&63) | 0x80);
	}
	else if(w<1<<16)
		tree_byte(w);
	else if(w<1<<21)
		four_byte(w);
	else if(w<1<<26)
		five_byte(w);
	else
		six_byte(w);
}
