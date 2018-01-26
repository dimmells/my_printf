/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 12:55:26 by dmelnyk           #+#    #+#             */
/*   Updated: 2017/11/04 16:20:35 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*current;
	t_list	*tmp;

	tmp = *alst;
	while (tmp != NULL)
	{
		current = tmp;
		tmp = tmp->next;
		ft_lstdelone(&current, del);
	}
	*alst = NULL;
}
