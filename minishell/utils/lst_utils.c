/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 18:01:40 by lmarzano          #+#    #+#             */
/*   Updated: 2021/09/15 18:02:18 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_list_by_file(char *dst, t_list **list, int file_len, int offset)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(dst, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (i < file_len)
	{
		if (ft_get_next_line(fd, &line) == -1)
		{
			close (fd);
			return (-1);
		}
		if (i++ >= offset && ft_lst_add_content(line, list, 2) == -1)
		{
			close(fd);
			free(line);
			return (-1);
		}
	}
	close (fd);
	return (1);
}

int	ft_lst_add_content(void	*content, t_list **list, int flag)
{
	t_list	*new;

	new = ft_lstnew(content);
	if (new == NULL)
		return (-1);
	if (flag == 1)
		ft_lstadd_front(list, new);
	else if (flag == 2)
		ft_lstadd_back(list, new);
	return (1);
}
