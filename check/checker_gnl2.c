/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_gnl2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-s <jperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 10:50:20 by jperez-s          #+#    #+#             */
/*   Updated: 2025/12/03 12:17:52 by jperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_gnl.h"

void	ft_copy_memory(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
}

static char	*process_line_with_newline(char **stash, char *newline)
{
	char	*line;

	line = malloc((newline - *stash) + 2);
	if (!line)
	{
		free(*stash);
		*stash = NULL;
		return (NULL);
	}
	ft_copy_memory(line, *stash, (newline - *stash) + 1);
	line[(newline - *stash) + 1] = '\0';
	*stash = ft_strjoin_c(NULL, newline + 1);
	return (line);
}

static char	*process_line_without_newline(char **stash)
{
	char	*line;

	line = ft_strdup_c(*stash);
	free(*stash);
	*stash = NULL;
	return (line);
}

static char	*extract_line(char **stash)
{
	char	*newline;
	char	*line;

	if (!*stash || (*stash)[0] == '\0')
	{
		free(*stash);
		*stash = NULL;
		return (NULL);
	}
	newline = ft_strchr_c(*stash, '\n');
	if (newline)
		line = process_line_with_newline(stash, newline);
	else
		line = process_line_without_newline(stash);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr_c(stash, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(stash);
			stash = NULL;
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stash = ft_strjoin_c(stash, buffer);
		if (!stash)
			return (NULL);
	}
	return (extract_line(&stash));
}
