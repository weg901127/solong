/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 18:42:47 by gilee             #+#    #+#             */
/*   Updated: 2021/01/18 18:43:16 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *newnode)
{
	t_list	*tmp;

	if (lst)
	{
		if (*lst == NULL)
			*lst = newnode;
		else
		{
			tmp = ft_lstlast(*(lst));
			tmp->next = newnode;
		}
	}
}
