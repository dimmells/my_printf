/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 12:33:35 by dmelnyk           #+#    #+#             */
/*   Updated: 2017/10/29 15:36:05 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*cp;

	cp = (char*)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (cp == NULL)
		return (NULL);
	return (ft_strcpy(cp, src));
}
