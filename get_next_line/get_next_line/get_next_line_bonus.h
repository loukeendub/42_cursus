/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 10:46:55 by lmarzano          #+#    #+#             */
/*   Updated: 2021/01/28 17:03:26 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4097
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
