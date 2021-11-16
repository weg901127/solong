/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 04:53:53 by gilee             #+#    #+#             */
/*   Updated: 2021/06/30 20:25:21 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

size_t	ft_strlen(const char *src)
{
	size_t	count;

	count = 0;
	if (src)
		while (*src++ != '\0')
			count++;
	return (count);
}
