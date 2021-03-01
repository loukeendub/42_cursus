/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 10:46:55 by lmarzano          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/01/28 16:17:00 by lmarzano         ###   ########.fr       */
=======
/*   Updated: 2021/01/28 17:55:23 by lmarzano         ###   ########.fr       */
>>>>>>> origin/main
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
int		just_do_it(char **line, char *buffer);

size_t	ft_strlen(const char *s);
char	*ft_realloc(char **line);
char	*ft_realloc_finale(char **line);

#endif
