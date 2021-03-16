/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_exam01.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 18:05:39 by lmarzano          #+#    #+#             */
/*   Updated: 2021/03/05 18:07:13 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int get_next_line(char **line)
{
	int ret = 0;
	int len = 0;
	int i = 0;
	if(!line)
		return(-1);
	if (!(*line = malloc(1000000)))
		return(-1);
	(*line)[len] = 0;
	while ((ret = read(0 , &(*line)[i], 1)) == 1)
	{
		if ((*line)[i] != '\n')
			i++;
		else
		{
			(*line)[i] = 0;
			return (1);
		}
	}
	(*line)[i] = 0;
	return (ret);
}

int main()
{
	int		r;
	char	*line;

	line = NULL;
	while ((r = get_next_line(&line) > 0))
	{
		printf("%s\n", line);
		free(line);
		line = NULL;
	}
	printf("%s", line);
	free(line);
	line = NULL;
}
