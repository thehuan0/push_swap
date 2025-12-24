/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_gnl.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-s <jperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:17:44 by jperez-s          #+#    #+#             */
/*   Updated: 2025/12/24 19:50:43 by jperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

// Function declarations for checker_gnl.c
size_t	ft_strlen_c(const char *s);
char	*ft_strchr_c(const char *s, int c);
char	*ft_strdup_c(const char *s);
char	*ft_strjoin_c(char *s1, char *s2);
char	*ft_substr_c(char const *s, unsigned int start, size_t len);
// Function declaration for checker_gnl2.c
char	*get_next_line(int fd);

#endif
