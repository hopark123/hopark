/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 12:13:54 by hopark            #+#    #+#             */
/*   Updated: 2021/04/28 19:49:29 by hopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void				*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*s1;
	const unsigned char	*s2;

	if (!dst && !src)
		return (0);
	s1 = dst;
	s2 = src;
	while (n-- > 0)
	{
		*s1++ = *s2++;
	}
	return (dst);
}

char		*ft_strjoin(const char *s1, const char *s2)
{
	size_t		len1;
	size_t		len2;
	char		*result;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(result = malloc(sizeof(char) * (len1 + len2 + 1))))
		return (0);
	ft_memcpy(result, s1, len1);
	ft_memcpy(result + len1, s2, len2);
	result[len1 + len2] = 0;
	return (result);
}

char		*ft_strndup(const char *s, size_t len)
{
	char		*temp;

	if (!(temp = malloc(sizeof(char) * (len + 1))))
		return (0);
	ft_memcpy(temp, s, len);
	temp[len] = 0;
	return (temp);
}

char		*ft_strchr(const char *s, char c)
{
	while (*s != c)
	{
		if (*s == 0)
			return (0);
		s++;
	}
	return ((char *)s);
}