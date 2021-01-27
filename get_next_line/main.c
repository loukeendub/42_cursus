/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 11:00:28 by lmarzano          #+#    #+#             */
/*   Updated: 2021/01/27 16:33:08 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	line = 0;
	fd = open("file1", O_RDONLY);
/*
** 1st line
*/
	get_next_line(fd, &line);
	printf("%s\n", line);
/*
** 2nd line
*/
	get_next_line(fd, &line);
	printf("%s\n", line);
/*
** 3rd line
*/
	get_next_line(fd, &line);
	printf("%s\n", line);
/*
** 4th line
*/
	get_next_line(fd, &line);
	printf("%s\n", line);
}
