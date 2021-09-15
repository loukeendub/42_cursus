#include "minishell.h"

static char	*ft_str_arrow(char *buf, char *tmp, t_list **list, int *size)
{
	char	*ret;
	char	*src;

	if (*list == NULL || (buf[2] == 'B' && (*list)->next == NULL))
		src = tmp;
	else
	{
		if (buf[2] == 'A' && (*list)->prev && *size != 0)
			*list = (*list)->prev;
		else if (buf[2] == 'B' && (*list)->next)
			*list = (*list)->next;
		src = ((char *)((*list)->content));
	}
	ret = ft_m_strlcpy(src, ft_strlen(src) + 1);
	if ((*list) && buf[2] == 'A' && (*list)->prev)
		(*size)++;
	else if ((*list) && buf[2] == 'B' && *size > 0)
		(*size)--;
	return (ret);
}

static char	*ft_create_exit(char *line)
{
	char	*tmp;

	tmp = line;
	line = malloc(5);
	if (line == NULL)
		return (NULL);
	ft_strlcpy(line, "exit", 5);
	free(tmp);
	return (line);
}

static char	*ft_create_line(char *buf, char *lne)
{
	char	*ret;

	ret = NULL;
	if (buf[0] > 31)
	{
		if (buf[0] != 127)
			ret = ft_strjoin(lne, buf);
		else if (buf[0] == 127)
			ret = ft_strdel(lne, 1);
	}
	else
		ret = ft_m_strlcpy(lne, ft_strlen(lne) + 1);
	return (ret);
}

static void	ft_newstr(char buf[5], char **line, t_list **list, int *size)
{
	static char	*tmp;
	char		*del;

	del = *line;
	if (buf == NULL)
	{
		tmp = ft_free_null(tmp);
		return ;
	}
	else if (buf[0] < 32 && buf[1] != '[')
		return ;
	else if (buf[1] == '[' && (buf[2] == 'A' || buf[2] == 'B'))
		*line = ft_str_arrow(buf, tmp, list, size);
	else if (buf[0] != 4)
	{
		*line = ft_create_line(buf, *line);
		if (tmp != NULL)
			tmp = ft_free_null(tmp);
		tmp = ft_m_strlcpy(*line, ft_strlen(*line) + 1);
	}
	if (buf[0] != 4)
		free(del);
}

char	*ft_read(const char *prompt, t_list **list)
{
	char	buf[5];
	char	*line;
	int		num;
	int		size;

	line = NULL;
	size = 0;
	ft_bzero(buf, 5);
	num = read(STDIN_FILENO, buf, 4);
	while (num > 0 && buf[0] != '\n' && buf[0] != 3)
	{
		write(2, &buf[0], 1);
		if (buf[0] == 4 && line == NULL)
			return (ft_create_exit(line));
		ft_newstr(buf, &line, list, &size);
		ft_write_prompt((char *)prompt, line);
		ft_bzero(buf, 5);
		num = read(STDIN_FILENO, buf, 4);
	}
	if (buf[0] == 3 && line != NULL)
		ft_bzero(line, ft_strlen(line));
	ft_bzero(buf, 5);
	ft_newstr(NULL, &line, list, &size);
	write(1, "\n", 1);
	return (line);
}
