/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adkhan <adkhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:58:31 by adkhan            #+#    #+#             */
/*   Updated: 2025/12/11 21:36:16 by adkhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (i = 0);
	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	*gnl_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dest1;
	const char	*src1;

	if (!dest && !src)
		return (NULL);
	dest1 = (char *)dest;
	src1 = (const char *)src;
	i = 0;
	while (i < n)
	{
		dest1[i] = src1[i];
		i++;
	}
	return (dest);
}

char	*gnl_strjoin(const char *s1, const char *s2)
{
	size_t	slen1;
	size_t	slen2;
	size_t	tot_len;
	char	*res;

	if (!s1)
		s1 = "";
	slen1 = gnl_strlen(s1);
	slen2 = gnl_strlen(s2);
	tot_len = slen1 + slen2;
	res = malloc((tot_len + 1) * (sizeof(char)));
	if (!res)
		return (NULL);
	gnl_memcpy(res, s1, slen1);
	gnl_memcpy((res + slen1), s2, slen2);
	res[slen1 + slen2] = '\0';
	return (res);
}

char	*gnl_strchr(const char *s, int c)
{
	char	*last_match;

	if (!s)
		return (NULL);
	last_match = NULL;
	while (1)
	{
		if (*s == (char)c)
		{
			last_match = (char *)s;
			break ;
		}
		if (*s == '\0')
			break ;
		s++;
	}
	return (last_match);
}
