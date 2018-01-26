/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin_n_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 18:30:28 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/01/25 18:16:50 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*strjoin_n_del(char *s1, char *s2, int del)
{
	int		len;
	char	*str;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	str = ft_strcpy(str, s1);
	res = str;
	str = str + ft_strlen(s1);
	if (del == 1 || del == 3)
		ft_strdel(&s1);
	str = ft_strcpy(str, s2);
	if (del == 2 || del == 3)
		ft_strdel(&s2);
	return (res);
}
