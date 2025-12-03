/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_gnl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-s <jperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 10:50:20 by jperez-s          #+#    #+#             */
/*   Updated: 2025/12/03 12:20:32 by jperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_gnl.h"

size_t	ft_strlen_c(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr_c(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strdup_c(const char *s)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	str = malloc((ft_strlen_c(s) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*join_strings(char *s1, char *s2, size_t s1_len, size_t s2_len)
{
	char	*joined;
	size_t	i;

	joined = malloc(s1_len + s2_len + 1);
	if (!joined)
	{
		free(s1);
		return (NULL);
	}
	i = -1;
	while (++i < s1_len)
		joined[i] = s1[i];
	i = -1;
	while (++i < s2_len)
		joined[s1_len + i] = s2[i];
	joined[s1_len + s2_len] = '\0';
	free(s1);
	return (joined);
}

char	*ft_strjoin_c(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;

	if (!s2)
		return (s1);
	if (!s1)
	{
		if (!s2)
			return (NULL);
		s1_len = 0;
		s2_len = ft_strlen_c(s2);
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	else
	{
		s1_len = ft_strlen_c(s1);
		s2_len = ft_strlen_c(s2);
	}
	return (join_strings(s1, s2, s1_len, s2_len));
}
