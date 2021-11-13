/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 18:34:32 by gilee             #+#    #+#             */
/*   Updated: 2021/01/18 18:37:40 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void	ft_lstadd_front(t_list **lst, t_list *newnode)
{
	if (lst && newnode)
	{
		newnode->next = *lst;
		*lst = newnode;
	}
}
