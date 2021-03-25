/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 19:43:26 by antmarti          #+#    #+#             */
/*   Updated: 2021/03/25 13:44:24 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*dest;
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	dest = (char *)malloc((sizeof(char)) * (len + 1));
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (((char *)s) + i);
		i++;
	}
	if (s[i] == '\0' && c == '\0')
		return (((char *)s) + i);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	dest = (char *)malloc(((sizeof(char)) * (len + 1)));
	if (!s)
		return (NULL);
	if ((start >= (ft_strlen(s))))
		return (ft_strdup(""));
	i = 0;
	while (i < len)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc((ft_strlen(s1) + 1) * sizeof(char));
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	if (!s[i])
		return (0);
	while (s[i])
		i++;
	return (i);
}
