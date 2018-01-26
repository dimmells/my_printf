/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 13:11:28 by dmelnyk           #+#    #+#             */
/*   Updated: 2017/11/05 14:26:17 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*map;
	t_list	*new;

	if (!lst || !f)
		return (NULL);
	new = f(lst);
	if (new == NULL)
		return (NULL);
	map = new;
	while (lst->next)
	{
		lst = lst->next;
		map->next = f(lst);
		if (map->next == NULL)
			return (NULL);
		map = map->next;
	}
	return (new);
}
