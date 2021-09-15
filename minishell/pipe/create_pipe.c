#include "minishell.h"

static int	ft_check_pipe(char *line)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (line && line[i] && flag < 2)
	{
		if (line[i] == '|' && !ft_in_quotes(line, i, '\'', '"'))
			flag += 1;
		else if (line[i] != ' ' && flag == 1)
			flag -= 1;
		i++;
	}
	if (flag != 0)
		return (ft_error(1, '|', NULL));
	return (1);
}

static void	ft_list_pipe(char *line, t_list **list)
{
	int		i;
	int		j;
	char	*tmp;
	t_list	*ret;

	i = 0;
	j = 0;
	ret = NULL;
	while (line && line[i])
	{
		if (line[i] == '|' && !ft_in_quotes(line, i, '\'', '"'))
		{
			tmp = ft_m_strlcpy(line + j, i - j + 1);
			if (tmp == NULL)
				return (ft_free_list(ret));
			ft_lst_add_content(tmp, &ret, 2);
			j = i + 1;
		}
		i++;
	}
	tmp = ft_m_strlcpy(line + j, i - j + 1);
	if (tmp == NULL)
		return (ft_free_list(ret));
	ft_lst_add_content(tmp, &ret, 2);
	*list = ret;
}

t_list	*ft_list_parse(char *line)
{
	t_list	*pipe_list;
	t_list	*tmp;
	t_list	*ret;
	t_parse	*parse;

	pipe_list = NULL;
	ret = NULL;
	if (line == NULL || ft_check_pipe(line) < 0)
		return (ret);
	ft_list_pipe(line, &pipe_list);
	tmp = pipe_list;
	while (pipe_list)
	{
		parse = ft_parsing(pipe_list->content);
		ft_lst_add_content(parse, &ret, 2);
		pipe_list = pipe_list->next;
	}
	ft_free_list(tmp);
	return (ret);
}
