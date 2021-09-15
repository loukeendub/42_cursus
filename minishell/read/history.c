#include "minishell.h"

int	ft_cpy_history(t_list *list, t_list *var)
{
	int		fd;
	int		num;
	int		i;
	char	*dst;

	i = 0;
	dst = ft_strjoin(ft_find_env(var, "HOME", 4), "/.minishell_history");
	if (dst == NULL)
		return (-1);
	fd = open(dst, O_WRONLY | O_TRUNC | O_CREAT, 00755);
	free (dst);
	if (fd == -1)
		return (-1);
	num = ft_lstsize(list) - 500;
	if (num < 0)
		num = 0;
	while (list && i < 500 + num)
	{
		if (i >= num)
			ft_putstrn_fd((char *)(list->content), fd);
		list = list->next;
		i++;
	}
	close (fd);
	return (1);
}

int	ft_change_history(char *line, t_list **list)
{
	t_list	*tmp;
	char	*cpy;

	*list = ft_lstfirst(*list);
	cpy = malloc(ft_strlen(line) + 1);
	if (cpy == NULL)
		return (-1);
	ft_strlcpy(cpy, line, ft_strlen(line) + 1);
	tmp = ft_lstnew(cpy);
	if (tmp == NULL)
		return (-1);
	ft_lstadd_back(list, tmp);
	return (1);
}

int	ft_file_history(t_list **list, t_list *var)
{
	int		fd;
	int		num;
	char	*dst;
	char	*buffer;

	buffer = NULL;
	dst = ft_strjoin(ft_find_env(var, "HOME", 4), "/.minishell_history");
	if (dst == NULL)
		return (-1);
	fd = open(dst, O_RDONLY | O_CREAT, 00755);
	if (fd == -1)
		return (fd);
	num = ft_get_next_line(fd, &buffer);
	while (num == 1)
	{
		num = ft_change_history(buffer, list);
		free(buffer);
		if (num != -1)
			num = ft_get_next_line(fd, &buffer);
	}
	close (fd);
	if (buffer != NULL)
		free(buffer);
	free(dst);
	return (num);
}
