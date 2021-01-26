/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 11:19:48 by lmarzano          #+#    #+#             */
/*   Updated: 2021/01/26 18:54:37 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	char		*tmp;
	static char	*s[4096];
	int			i;

	if (fd < 0 || line == NULL)
		return (-1);
}
/*
read() attempts to read nbyte bytes of data from the object referenced by the descriptor fildes into the buffer pointed to by buf.

If successful, the number of bytes actually read is returned.  Upon reading end-of-file, zero is returned.  Otherwise, a -1 is
returned and the global variable errno is set to indicate the error.


*/
