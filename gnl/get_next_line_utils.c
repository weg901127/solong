/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 19:02:12 by gilee             #+#    #+#             */
/*   Updated: 2021/02/26 19:02:15 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *src)
{
	size_t count;

	count = 0;
	if (src)
	{
		while (*src++ != '\0')
		{
			count++;
		}
	}
	return (count);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	len;

	if (s)
	{
		len = ft_strlen(s) + 1;
		while (len--)
		{
			if (*s++ == (char)c)
				return ((char *)--s);
		}
	}
	return (NULL);
}

void	*ft_memcpy(void *d, void const *s, size_t n)
{
	char			*pd;
	char const		*ps;

	pd = d;
	ps = s;
	if (n == 0)
		return (d);
	if ((ps == NULL) && (pd == NULL))
		return (NULL);
	if ((ps != NULL) || (pd != NULL))
	{
		while (n--)
			*pd++ = *ps++;
	}
	return (d);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned char	*res;
	size_t			s1_len;
	size_t			s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(res = (unsigned char *)malloc\
(((s1_len + s2_len) + 1) * sizeof(unsigned))))
		return (NULL);
	ft_memcpy(res, s1, s1_len);
	ft_memcpy(res + s1_len, s2, s2_len);
	*(res + s1_len + s2_len) = '\0';
	return (char *)(res);
}

char	*ft_strdup(const char *s1)
{
	char		*rest;
	const char	*ps1;
	size_t		len;

	if (!s1)
	{
		if (!(rest = (char *)malloc((1) * sizeof(char))))
			return (NULL);
		rest[0] = '\0';
		return (rest);
	}
	ps1 = s1;
	len = ft_strlen(s1);
	if (!(rest = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (len--)
	{
		*rest++ = *ps1++;
	}
	*rest = '\0';
	return (rest - ft_strlen(s1));
}
